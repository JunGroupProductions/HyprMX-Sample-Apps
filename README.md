# HyprMX SDK
## Overview
HyprMX is the world's first invite-only brand ad network.  Born on Madison Avenue and raised in mobile gaming, HyprMX brings brands into premium mobile apps.

To request an invitation for HyprMX fill out the form [here](https://www.hyprmx.com/request-invite)

This repo is to be used with the [integration documentation.](https://documentation.hyprmx.com/)

## Demo Apps
To get started with HyprMX Example Apps, clone this repo and follow the instructions for your platform.  

### Android
1. Open HyprMX-Android-ExampleApp in Android Studio
2. Run the application to see the Ads using our Example App Distributor ID
3. Open MainActivity.kt
4. Modify `DISTRIBUTOR_ID` to match the Distributor ID provided to you by HyprMX
5. Modify `REWARDED_PLACEMENT_NAME` to match one of your rewarded placements
6. Modify `INTERSTITIAL_PLACEMENT_NAME` to match one of your interstitial placements
7. Modify `BANNER_PLACEMENT_NAME` to match one of your banner placements
8. Modify `BANNER_SIZE` to match the banner placement size
9. Run the application to see the Ads using your Distributor ID

For `app-kotlin` module, there's an extra flag `USE_SUSPENDED_API_MODE` that can be used to switch between the callback and suspend versions of initialization and Placement.loadAd API.

### iOS ExampleApp
1. Open HyprMX-ExampleApp.xcodeproj in Xcode
2. Run the scheme `HyprMX-ExampleApp` to see the Rewarded, Interstitial and Banner Ads using our Example App Distributor ID
3. Open ViewController.swift
4. Modify myDistributorID to match the Distributor ID provided to you by HyprMX
5. Modify placementName1 to match one of your rewarded placements
6. Modify placementName2 to match one of your interstitial placements
7. Modify placementNameBanner to match one of your banner placements
8. Run the application to see the Ads using your Distributor ID

### iOS TableView ExampleApp
1. Open HyprMX-ExampleApp.xcodeproj in Xcode
2. Run the scheme `HyprMX-ExampleTableViewApp` to see the Banner Ads in a TableView with reuse cells, using our Example App Distributor ID
3. Open TableViewController.swift
4. Modify myDistributorID to match the Distributor ID provided to you by HyprMX
5. Modify placementNameBanner to match one of your banner placements
6. Run the application to see the Ads using your Distributor ID
## License

[Eula](https://www.hyprmx.com/eula)
