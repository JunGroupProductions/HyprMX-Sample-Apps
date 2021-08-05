//
//  BannerViewModel.swift
//  HyprMX-SwiftUIExampleApp
//
//  Created by Sean Reinhardt on 7/22/21.
//  Copyright © 2021 hyprmx. All rights reserved.
//

import Foundation
import Combine
import HyprMX

let myDistributorID = "1000198877"

class BannerViewModel: NSObject, Identifiable, ObservableObject, HyprMXBannerDelegate, HyprMXInitializationDelegate {
    
    var adSize:CGSize = CGSize.zero
    
    let statusTextChanged = CurrentValueSubject<String,Never>("")
    var statusLabelText: String = "" {
        didSet {
            statusTextChanged.send(self.statusLabelText)
        }
    }
    
    let placementNameChanged = CurrentValueSubject<String,Never>("")
    var placementName: String = "" {
        didSet {
            placementNameChanged.send(self.placementName)
        }
    }
    
    /** Load Ad button is enabled after SDK completes initialization */
    let loadAdButtonEnableChanged = CurrentValueSubject<Bool,Never>(false)
    var loadButtonEnabled: Bool = false {
        didSet {
            loadAdButtonEnableChanged.send(self.loadButtonEnabled)
        }
    }
    
    let bannerPlacement: BannerPlacement
    var hyprMXUser: HyprMXUser = HyprMXUser.init(distributorId: myDistributorID)
    
    init(placement: BannerPlacement) {
        self.bannerPlacement = placement
        super.init()
        self.adSize = CGSize.init(width:CGFloat(self.bannerPlacement.adWidth), height: CGFloat(self.bannerPlacement.adHeight))
        self.placementName = placement.placementName
        
        /** Initialize SDK early in your app lifecycle in order to load ads. */
        hyprMXUser.initSDK(delegate: self)
    }
    
    /** Call loadAd on banner placements after the SDK is initialized, when you're ready to show a banner */
    func loadAd(bannerView:HyprMXBannerView) {
        statusLabelText = ""
        bannerView.loadAd()
    }
    
    // MARK: - HyprMXBannerDelegate Implementation -
    
    /** Called in response to loadAd when an ad was loaded */
    func adDidLoad(_ bannerView: HyprMXBannerView) {
        print("adDidLoad: ", bannerView.placementName as Any)
        statusLabelText = "Banner Loaded."
    }
     
    /** Called in response to loadAd when there was an error loading an ad */
    func adFailed(toLoad bannerView: HyprMXBannerView, error: Error) {
        let nsError = error as NSError
        print("adFailed: \(nsError.localizedDescription) bannerView: \(String(describing: bannerView.placementName))")
        statusLabelText = "Banner failed to load."
    }
     
    /** Called when the user clicks on the bannerView */
    func adWasClicked(_ bannerView: HyprMXBannerView) {
        print("adWasClicked: ", bannerView.placementName as Any)
        statusLabelText = "Banner was clicked."
    }
     
    /** Called when a banner click will open a full-screen modal */
    func adDidOpen(_ bannerView: HyprMXBannerView) {
        print("adDidOpen: ", bannerView.placementName as Any)
        statusLabelText = "\(statusLabelText) Opened Modal."
    }
         
    /** Called when a full-screen modal has been closed */
    func adDidClose(_ bannerView: HyprMXBannerView) {
        print("adDidClose: ", bannerView.placementName as Any)
        statusLabelText = "\(statusLabelText) Closed Modal."
    }
     
    /** Called when a banner click will open another application */
    func adWillLeaveApplication(_ bannerView: HyprMXBannerView) {
        print("adWillLeaveApplication: ", bannerView.placementName as Any)
        statusLabelText = "\(statusLabelText) Opened link outside app."
    }
    
    // MARK: - HyprMXInitializationDelegate Implementation -
    
    /** Messaged when HyprMX has completed initializing.  You can call loadAd on your placements to load inventory after this messaged has been received. */
    func initializationDidComplete() {
        print("Initialization of HyprMX Completed Successfully")
        loadButtonEnabled = true
    }

    /** Messaged when HyprMX could not initialize. */
    func initializationFailed() {
        print("Initialization of HyprMX Failed - please re-initialize")
        loadButtonEnabled = false
    }
}
