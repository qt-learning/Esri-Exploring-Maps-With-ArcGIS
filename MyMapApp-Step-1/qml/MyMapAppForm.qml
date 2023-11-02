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

import QtQuick
import QtQuick.Controls
import Esri.MyMapApp

Item {

    // Create MapQuickView here, and create its Map etc. in C++ code
    MapView {
        id: view
        anchors.fill: parent
        // set focus to enable keyboard navigation
        focus: true
    }

    // Declare the C++ instance which creates the map etc. and supply the view
    MyMapApp {
        id: model
        mapView: view
    }

    // A background rectangle over which to display the buttons
    Rectangle {
        id: background
        anchors.fill: buttonCol
        anchors.margins: -5
        color: "white"
        radius: 5
    }

    // A column to contain the buttons
    Column {
        id: buttonCol
        anchors {
            top: parent.top
            right: parent.right
            margins: 15
        }
        spacing: 10

        // Step 1
        // Toggle between tracking the user's location with the line graphic
        Button {
            id: locationBtn
            anchors.horizontalCenter: parent.horizontalCenter
            icon.source: checked ? "qrc:/Resources/calcite-icons/gps-on-32-f.svg" : "qrc:/Resources/calcite-icons/gps-off-32.svg"
            text: checked ? "Tracking" : "Not Tracking"
            display: AbstractButton.TextUnderIcon
            checkable: true
            onCheckedChanged: {
                model.isTracking = checked;
            }
        }
    }
}
