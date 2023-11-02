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

using namespace Esri::ArcGISRuntime;

MyMapApp::MyMapApp(QObject* parent /* = nullptr */):
  QObject(parent),
  m_map(new Map(BasemapStyle::OsmStandard, this))
{
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
  m_pathGraphic = new Graphic(this);
  m_pathGraphic->setSymbol(new SimpleLineSymbol(SimpleLineSymbolStyle::Solid, Qt::blue, 2, this));
  graphicsOverlay->graphics()->append(m_pathGraphic);

  // Create a PolylineBuilder to construct lines given a set of points
  m_lineBuilder = new PolylineBuilder(SpatialReference::wgs84(), this);

  // Whenever the user's location changes, update the line path if necessary and recenter the map
  connect(m_mapView->locationDisplay(), &LocationDisplay::locationChanged, this, [this](const Location& l)
  {
    if (!m_isTracking)
      return;

    m_mapView->locationDisplay()->setAutoPanMode(LocationDisplayAutoPanMode::CompassNavigation);

    m_lineBuilder->addPoint(l.position());
    m_pathGraphic->setGeometry(m_lineBuilder->toGeometry());
  });
}
