# Exploring with ArcGIS Maps SDK for Qt

Welcome to the repository for the course "Exploring with ArcGIS Maps SDK for Qt" on Qt Academy.

> Get the full learning experience by enrolling in the course on [Qt Academy](https://www.qt.io/academy/course-catalog?q=#esri-x-qt:-exploring-with-arcgis-maps-sdk-for-qt)

## What You'll Learn

- **Setting up a basic mapping application** using the ArcGIS Maps SDK for Qt with user location display.

- **Plotting a user's path** as a line on the map using graphics overlays and location tracking.

- **Downloading map areas** from an online basemap service for offline storage on the device.

- **Displaying offline maps** by loading cached vector tiles when the device has no network connectivity.

**Skill Level**: Beginner

## Getting Started

In this course, you will build a backcountry navigation app suggested for use in settings like hiking or backpacking. Over four progressive steps, you'll go from displaying an online map to recording paths, downloading map regions, and displaying them offline.

The repository contains the finished code at the end of each step:

| Folder                   | Description                                         |
| ------------------------ | --------------------------------------------------- |
| `00-Setting-Up`          | Display a world map and zoom to the user's location |
| `01-Plot-Your-Path`      | Record and display the user's travelled path        |
| `02-Download-Map`        | Download a basemap area for offline use             |
| `03-Display-Map-Offline` | Load and display offline basemaps from the device   |

The code includes line comments not made in the video for extra clarity. Feel free to compare your progress against this repo or clone it to start a clean slate.

## Prerequisites

Before getting started, you should be familiar with Qt Quick fundamentals and C++ development with Qt. To use ArcGIS Maps SDK for Qt, you need an [ArcGIS](https://www.arcgis.com/index.html) Online, [ArcGIS Enterprise](https://enterprise.arcgis.com/), or [ArcGIS Location Platform](https://location.arcgis.com/) account, as well as an API key. To learn more about ArcGIS accounts and API keys, visit the [ArcGIS Maps SDK for Qt website](https://developers.arcgis.com/qt/).

## Instructions

To get started with this project, you will need to have Qt (6.8 or later), the ArcGIS Maps SDK for Qt, and an IDE (e.g., Qt Creator) installed on your computer. You can download Qt and Qt Creator from the [Qt.io website](https://qt.io).

Once you have Qt and an IDE installed, head over to [Qt Academy](https://academy.qt.io) and follow along with the course videos.

To run any project in Qt Creator:

1. Navigate to the project folder
2. Open the `CMakeLists.txt` file
3. Build and run the project

The application will launch and display a mapping interface demonstrating the concepts covered in each step.

## Resources

If you need additional help, the following resources may be helpful:

- ArcGIS Maps SDK for Qt: https://developers.arcgis.com/qt/
- ArcGIS Maps SDK for Qt API Reference: https://developers.arcgis.com/qt/cpp/api-reference/
- Qt Documentation: https://doc.qt.io
- Qt Forum: https://forum.qt.io
- Qt Academy: https://qt.io/academy

## Licensing Information

```
Copyright (C) 2026 Qt Group.
SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
```

This course teaches essential techniques for building offline-capable mapping applications with the ArcGIS Maps SDK for Qt.

### Terms and Conditions

If you, your employer, or the legal entity you act on behalf of hold commercial license(s) with a Qt Group entity, this software package constitutes Pre-Release Code under the Qt License/Frame Agreement governing those licenses, and that agreement's terms and conditions govern your access and use of this software package.

This software package may provide links or access to third party libraries or code (collectively "Third-Party Software") to implement various functions. Use or distribution of Third-Party Software is discretionary and in all respects subject to applicable license terms of applicable third-party right holders.

### Third-Party Attributions

#### ArcGIS Maps SDK for Qt

The ArcGIS Maps SDK for Qt is proprietary software that requires a separate license from Esri. A free Lite license is available for basic functionality. See [License and Deployment](https://developers.arcgis.com/qt/license-and-deployment/license-levels-and-capabilities/) for details.

Applications built from this project must display "Powered by Esri" attribution per [Esri's attribution requirements](https://developers.arcgis.com/documentation/esri-and-data-attribution/), as well as displaying all data source provider names in maps that use ArcGIS basemap and/or data services.

Note: The ArcGIS Maps SDK for Qt is a proprietary dependency. Users who wish to build and run these examples should be aware of the licensing considerations described above.

#### Calcite Design System

The icons used in this course are from the [Calcite Design System](https://developers.arcgis.com/calcite-design-system/). Calcite is available with either an [ArcGIS](https://www.arcgis.com/index.html) Online, [ArcGIS Enterprise](https://enterprise.arcgis.com/), or [ArcGIS Location Platform](https://location.arcgis.com/) account. If you don't have an account, you can create an [ArcGIS Location Platform account](https://location.arcgis.com/sign-up/) for free.

Use of Calcite Design System is subject to the terms of use found in the [Esri Master Services Agreement](https://www.esri.com/content/dam/esrisites/en-us/media/legal/ma-full/ma-full.pdf).
