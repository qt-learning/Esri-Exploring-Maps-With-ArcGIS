// Copyright 2023 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "MyMapApp.h"

#include "Map.h"
#include "MapTypes.h"
#include "MapQuickView.h"

// Step 0
#include "LocationDisplay.h"
#include "MapViewTypes.h"

// Step 1
#include "Graphic.h"
#include "GraphicListModel.h"
#include "GraphicsOverlay.h"
#include "GraphicsOverlayListModel.h"
#include "Location.h"
#include "Point.h"
#include "PolylineBuilder.h"
#include "SimpleLineSymbol.h"
#include "SpatialReference.h"
#include "SymbolTypes.h"

// Step 2
#include "ArcGISVectorTiledLayer.h"
#include "Basemap.h"
#include "GeometryEngine.h"
#include "Error.h"
#include "ExportVectorTilesJob.h"
#include "ExportVectorTilesParameters.h"
#include "ExportVectorTilesTask.h"
#include "LayerListModel.h"
#include "Polygon.h"

#include <QDir>
#include <QFuture>
#include <QStandardPaths>


using namespace Esri::ArcGISRuntime;

const QString vtpkPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

MyMapApp::MyMapApp(QObject* parent /* = nullptr */):
  QObject(parent),
  m_map(new Map(this)),
  m_basemap(new Basemap(BasemapStyle::OsmStandard, this))
{
  m_map->setBasemap(m_basemap);
  m_tempParent = std::make_unique<QObject>();
}

MyMapApp::~MyMapApp()
{
}

MapQuickView* MyMapApp::mapView() const
{
  return m_mapView;
}

// Set the view (created in QML)
void MyMapApp::setMapView(MapQuickView* mapView)
{
  if (!mapView || mapView == m_mapView)
  {
    return;
  }

  m_mapView = mapView;
  m_mapView->setMap(m_map);

  // Start the location display and center the map on the user
  m_mapView->locationDisplay()->start();
  m_mapView->locationDisplay()->setAutoPanMode(LocationDisplayAutoPanMode::Recenter);

  // Allow the user to rotate the map by pinching a touchscreen
  m_mapView->setRotationByPinchingEnabled(true);

  setupTracking();

  emit mapViewChanged();
}

// Step 1
void MyMapApp::setupTracking()
{
  // Create and add a GraphicsOverlay to display Graphics on the MapView
  GraphicsOverlay* graphicsOverlay = new GraphicsOverlay(this);
  m_mapView->graphicsOverlays()->append(graphicsOverlay);

  // Create and add a Graphic to show the user's path
  m_offlineMapExtentGraphic = new Graphic(this);
  m_offlineMapExtentGraphic->setSymbol(new SimpleLineSymbol(SimpleLineSymbolStyle::Solid, Qt::blue, 2, this));
  graphicsOverlay->graphics()->append(m_offlineMapExtentGraphic);

  // Create a PolylineBuilder to construct lines given a set of points
  m_lineBuilder = new PolylineBuilder(SpatialReference::wgs84(), this);

  // Whenever the user's location changes, update the line path if necessary and recenter the map
  connect(m_mapView->locationDisplay(), &LocationDisplay::locationChanged, this, [this](const Location& l)
  {
    if (!m_isTracking)
      return;

    m_mapView->locationDisplay()->setAutoPanMode(LocationDisplayAutoPanMode::CompassNavigation);

    m_lineBuilder->addPoint(l.position());
    m_offlineMapExtentGraphic->setGeometry(m_lineBuilder->toGeometry());
  });

}

// Step 2
void MyMapApp::createOfflineAreaFromExtent()
{
  // Export the first available ArcGISVectorTileLayers
  for (Layer* layer : *(m_basemap->baseLayers()))
  {
    if (ArcGISVectorTiledLayer* vectorTileLayer = dynamic_cast<ArcGISVectorTiledLayer*>(layer))
    {
      exportVectorTiles(vectorTileLayer);
      break;
    }
  }
}

// Step 2
void MyMapApp::exportVectorTiles(Esri::ArcGISRuntime::ArcGISVectorTiledLayer* vectorTileLayer)
{
  // Create a new export task from the layer's source url
  m_exportVectorTilesTask = new ExportVectorTilesTask(vectorTileLayer->url(), m_tempParent.get());

  // Create default parameters for the layer service
  // Normalize the central meridian in case the download area crosses the meridian
  m_exportVectorTilesTask->createDefaultExportVectorTilesParametersAsync(GeometryEngine::normalizeCentralMeridian(m_mapView->visibleArea()), m_mapView->mapScale()*0.1)
      .then(this, [this](const ExportVectorTilesParameters& defaultParams)
  {
    QDir path(vtpkPath);

    // Remove any existing offline files
    path.removeRecursively();

    // Create the directory if it does not already exist
    if (!QDir().exists(vtpkPath))
      QDir().mkdir(vtpkPath);

    const QString vtpkFileName = vtpkPath+"/vectorTiles.vtpk";
    const QString itemResourcesPath = vtpkPath+"/itemResources";

    // Create a Job object to manage the export
    m_exportVectorTilesJob = m_exportVectorTilesTask->exportVectorTiles(defaultParams, vtpkFileName, itemResourcesPath);

    // Monitor the download progress and update the UI every time it changes
    connect(m_exportVectorTilesJob, &Job::progressChanged, this, [this]()
    {
      m_downloadProgress = m_exportVectorTilesJob->progress();
      emit downloadProgressChanged();
    });

    // Display any errors in the console log
    connect(m_exportVectorTilesJob, &Job::errorOccurred, this, [](const Error& e){qWarning() << e.message() << e.additionalMessage();});

    // Once all async slots have been created, start the export
    m_exportVectorTilesJob->start();
  });
}

