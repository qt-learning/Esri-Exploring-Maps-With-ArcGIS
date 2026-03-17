// Copyright (C) 2026 Esri.
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
// See: https://resources.arcgis.com/en/sample-use-restrictions/
//
// Copyright (C) 2026 Qt Group.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include "MyMapApp.h"

#include "Map.h"
#include "MapTypes.h"
#include "MapQuickView.h"

// Step 0
#include "LocationDisplay.h"
#include "MapViewTypes.h"

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

  emit mapViewChanged();
}
