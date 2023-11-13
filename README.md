# Exploring Maps with the ArcGIS Maps SDK for Qt

## About this repository

This repository contains the finished files at the end of each step in the Qt Academy course: Exploring Maps with the ArcGIS Maps SDK for Qt. The code in this repository also includes line comments that are not made in the video for extra clarity. Feel free to compare your progress against this repo or clone the repo to start a clean slate to work against. This repo does not contain any of the recommended extra steps in the series, such as a cancel button for the download or support for additional online maps.

This repository is provided "AS IS" without warranties or conditions of any kind.

## About the app

The app created over the duration of the Exploring Maps with the ArcGIS Maps SDK for Qt course is a basic mapping app suggested for use in backcountry navigation in settings like hiking or backpacking. The finished app has the ability to plot the user's path as a line to the map, download map areas from an online service, and display those map areas when in an offline setting.

## Steps

### 00 - Setting up

At this stage the app displays a world map from an online service and zooms to and displays the user's location upon opening. NOTE: The app requires an API key from the [ArcGIS Developer Website](https://developers.arcgis.com) in order to display the map.

### 01 - Plot your path

At this stage, the user can tap a button to record the path they've travelled to a line that is displayed on the map. Further enhancements could be to [clear the line](https://developers.arcgis.com/qt/cpp/api-reference/esri-arcgisruntime-graphiclistmodel.html#clear) or display the length of the line with the [GeometryEngine](https://developers.arcgis.com/qt/cpp/api-reference/esri-arcgisruntime-geometryengine.html#length).


### 02 - Download map

At this stage, the user can download one area of the basemap and store it on their local device. Further enhancements could be to create a [cancel button](https://developers.arcgis.com/qt/cpp/api-reference/esri-arcgisruntime-job.html#cancelJobAsync) for the download or to persist and display multiple offline areas rather than just one by naming the offline area something unique.

### 03 - Display map offline

At this final stage, the app can now display offline basemaps saved to the device by retrieving the [VectorTileCache](https://developers.arcgis.com/qt/cpp/api-reference/esri-arcgisruntime-vectortilecache.html). Further steps could be to create a library of offline maps so the user can choose what they want to display or to make use of [QNetworkInformation](https://doc.qt.io/qt-6.5/qnetworkinformation.html#Reachability-enum) to determine if the device is online or not.
