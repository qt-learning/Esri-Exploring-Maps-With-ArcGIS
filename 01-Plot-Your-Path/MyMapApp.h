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

// Step 1
class Graphic;
class PolylineBuilder;

} // namespace Esri::ArcGISRuntime

#include <QObject>

Q_MOC_INCLUDE("MapQuickView.h")

class MyMapApp : public QObject {
  Q_OBJECT

  Q_PROPERTY(Esri::ArcGISRuntime::MapQuickView *mapView READ mapView WRITE
                 setMapView NOTIFY mapViewChanged)

  // Step 1
  Q_PROPERTY(bool isTracking MEMBER m_isTracking NOTIFY isTrackingChanged)

public:
  explicit MyMapApp(QObject *parent = nullptr);
  ~MyMapApp() override;

signals:
  void mapViewChanged();

  // Step 1
  void isTrackingChanged();

private:
  Esri::ArcGISRuntime::MapQuickView *mapView() const;
  void setMapView(Esri::ArcGISRuntime::MapQuickView *mapView);

  Esri::ArcGISRuntime::Map *m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView *m_mapView = nullptr;

  // Step 1
  void setupTracking();
  Esri::ArcGISRuntime::Graphic *m_pathGraphic = nullptr;
  Esri::ArcGISRuntime::PolylineBuilder *m_lineBuilder = nullptr;
  bool m_isTracking = false;
};

#endif // MYMAPAPP_H
