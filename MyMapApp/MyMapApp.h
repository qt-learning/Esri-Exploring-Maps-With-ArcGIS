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

#ifndef MYMAPAPP_H
#define MYMAPAPP_H

namespace Esri::ArcGISRuntime {
class Map;
class MapQuickView;

// Step 2
class ArcGISVectorTiledLayer;
class Basemap;
class ExportVectorTilesJob;
class ExportVectorTilesTask;
class OfflineMapTask;

// Step 3
class ArcGISVectorTiledLayer;
class ItemResourceCache;
class VectorTileCache;

// Step 4
class Graphic;
class PolylineBuilder;

} // namespace Esri::ArcGISRuntime

#include <QObject>

Q_MOC_INCLUDE("MapQuickView.h")

class MyMapApp : public QObject
{
  Q_OBJECT

  Q_PROPERTY(Esri::ArcGISRuntime::MapQuickView* mapView READ mapView WRITE setMapView NOTIFY mapViewChanged)

  // Step 1
  Q_PROPERTY(bool isTracking MEMBER m_isTracking NOTIFY isTrackingChanged)

  // Step 2
  Q_PROPERTY(int downloadProgress MEMBER m_downloadProgress NOTIFY downloadProgressChanged)

public:
  explicit MyMapApp(QObject* parent = nullptr);
  ~MyMapApp() override;

  // Step 2
  Q_INVOKABLE void createOfflineAreaFromExtent();

  // Step 3
  Q_INVOKABLE void toggleOffline(bool offline);

signals:
  void mapViewChanged();

  // Step 1
  void isTrackingChanged();

  // Step 2
  void downloadProgressChanged();

private:
  Esri::ArcGISRuntime::MapQuickView* mapView() const;
  void setMapView(Esri::ArcGISRuntime::MapQuickView* mapView);

  Esri::ArcGISRuntime::Map* m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;

  // Step 1
  void setupTracking();
  Esri::ArcGISRuntime::Graphic* m_offlineMapExtentGraphic = nullptr;
  Esri::ArcGISRuntime::PolylineBuilder* m_lineBuilder = nullptr;
  bool m_isTracking = false;

  // Step 2
  void exportVectorTiles(Esri::ArcGISRuntime::ArcGISVectorTiledLayer* vectorTileLayer);

  Esri::ArcGISRuntime::Basemap* m_basemap = nullptr;
  Esri::ArcGISRuntime::OfflineMapTask* m_offlineMapTask = nullptr;
  Esri::ArcGISRuntime::ExportVectorTilesJob* m_exportVectorTilesJob = nullptr;
  Esri::ArcGISRuntime::ExportVectorTilesTask* m_exportVectorTilesTask = nullptr;
  std::unique_ptr<QObject> m_tempParent;
  int m_downloadProgress = 0;

  // Step 3
  void loadOfflineBasemaps();
  Esri::ArcGISRuntime::VectorTileCache* m_vectorTileCache = nullptr;
  Esri::ArcGISRuntime::ItemResourceCache* m_itemResourceCache = nullptr;
  Esri::ArcGISRuntime::ArcGISVectorTiledLayer* m_offlineLayer = nullptr;
};

#endif // MYMAPAPP_H
