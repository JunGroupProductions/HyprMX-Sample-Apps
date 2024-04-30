//
//  ViewController.swift
//  HyprMX-ExampleApp
//
//  Created by Ben Balcomb on 8/5/19.
//  Copyright © 2019 hyprmx. All rights reserved.
//

import UIKit
import HyprMX

class ViewController: UIViewController, HyprMXPlacementShowDelegate, HyprMXPlacementExpiredDelegate, HyprMXBannerDelegate {

    @IBOutlet weak var placementOneNameLabel: UILabel!
    @IBOutlet weak var placementTwoNameLabel: UILabel!
    @IBOutlet weak var bannerPlacementNameLabel: UILabel!
    
    @IBOutlet weak var placementOneStatusLabel: UILabel!
    @IBOutlet weak var placementTwoStatusLabel: UILabel!
    @IBOutlet weak var bannerPlacementStatusLabel: UILabel!
    
    @IBOutlet weak var placementOneInventoryButton: UIButton!
    @IBOutlet weak var placementTwoInventoryButton: UIButton!
    @IBOutlet weak var bannerLoadButton: UIButton!
    
    @IBOutlet weak var placementOneShowButton: UIButton!
    @IBOutlet weak var placementTwoShowButton: UIButton!
    
    @IBOutlet weak var bannerContainerView: UIView!
    @IBOutlet weak var sdkVersionLabel: UILabel?
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView?

    let myDistributorID = "11000124103"
    
    let placementName1:String = "Vast"
    let placementName2:String = "Mraid"
    let placementNameBanner:String = "banner_320_50"

    var placements:[HyprMXPlacement] = []
    var bannerView:HyprMXBannerView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        /** Initialize SDK */
        // Initialize HyprMX before loading ads on your placements or bannerViews.
        // You can begin to load ads if success is true
        HyprMX.setLogLevel(HYPRLogLevelDebug)
        HyprMX.initialize(myDistributorID) {success, error in
            if success {
                /** Initializing Banner Ads */
                self.bannerView = HyprMXBannerView.init(placementName: self.placementNameBanner, adSize: kHyprMXAdSizeBanner)
                if let banner = self.bannerView {
                    // Placement delegates are optional for banners, you can set one to receive status on your banner ads.
                    banner.placementDelegate = self
                    
                    // Add to a view in your UI
                    self.bannerContainerView.addSubview(banner)
                    
                    // Add constraints to HyprMXBannerView
                    banner.translatesAutoresizingMaskIntoConstraints = false
                    banner.widthAnchor.constraint(equalToConstant: banner.adSize.width).isActive = true
                    banner.heightAnchor.constraint(equalToConstant: banner.adSize.height).isActive = true
                    banner.centerXAnchor.constraint(equalTo: self.bannerContainerView.centerXAnchor).isActive = true
                    banner.centerYAnchor.constraint(equalTo: self.bannerContainerView.centerYAnchor).isActive = true
                }

                for placementName in [self.placementName1, self.placementName2] {
                    // You can get HyprMXPlacement objects from HyprMX by their placement Name
                    if let placement:HyprMXPlacement = HyprMX.getPlacement(placementName) {
                        // Set a expiredDelegate on each of your placements to receive callback
                        // on ad expired before it could be shown.
                        placement.expiredDelegate = self;
                        self.placements.append(placement)
                    }
                }

                print("Initialization of HyprMX Completed Successfully")
                self.updateUIInitializationSuccess()
            } else {
                print("Initialization of HyprMX Failed - please re-initialize")
                self.updateUIInitializationFailed()
            }
        }
        
        self.setUpUI()
    }

    // MARK: - Full Screen Rewarded/Interstitial Ads Load/Show API -

    func loadAd(placementName: String) {
        /**
         * loadAd will check for an ad to present for this placement.
         */
        HyprMX.getPlacement(placementName)?.loadAd() {success in
            if success {
                print("Ad available for \(placementName)")
                if let placement = HyprMX.getPlacement(placementName) {
                    self.updateUIAdAvailable(placement: placement)
                }
            } else {
                print("Ad not available for \(placementName)")
                if let placement = HyprMX.getPlacement(placementName) {
                    self.updateUIAdNotAvailable(placement: placement, alertOn: true)
                }
            }
        }
    }
    
    func showAd(placementName: String) {
        guard let placement = HyprMX.getPlacement(placementName) else {
            print("HyprMX failed to return placement")
            return
        }

        /**
         * Check the state of isAdAvailable before attempting to show an ad
         */
        if placement.isAdAvailable {
            /**
             * showAd will begin presentation of an ad.
             * The placement will message adWillStartForPlacement: immediately before attempting to present;
             * adDidCloseForPlacement: when everything is off screen;
             * and adDidRewardForPlacement: if the ad completed successfully and the user should receive a reward.
             * If there is no ad to display or an error occurs during presentation,
             * adDisplayErrorForPlacement:error: will be messaged with an error description,
             * then adDidCloseForPlacement: will be messaged.
             */
            placement.showAd(from: self, delegate: self)
        } else {
            print("No ads available for placement ", placementName)
        }
    }
    
    // MARK: - Banner Ads Load API -
    func loadBannerAd() {
        guard let bannerView = self.bannerView else {
            return
        }
        Task {
            /**
             * loadAd will check for an ad to present for this Banner placement.
             * The result of this call will true if there's an ad to show, or false if there's no inventory.
             */
            let success = await bannerView.loadAd()
            print("Banner load \(success ? "succeeded" : "failed")")
        }
    }
    
    // MARK: - HyprMXPlacementDelegate Implementation -

    /** Messaged immediately before attempting to present an ad. */
    func adWillStart(placement: HyprMXPlacement) {
        print("adWillStartForPlacement: ", placement.placementName as Any)
        updateUIAdWillStart(placement: placement)
    }

    /** Messaged upon conclusion of any ad presentation attempt */
    func adDidClose(placement: HyprMXPlacement, finished: Bool) {
        print("adDidCloseForPlacement: ", placement.placementName as Any)
        updateUIAdDidClose(placement: placement, finished: finished)
    }

    /** Messaged when an error occurs during ad presentation. */
    private func adDisplayError(_ error: Error, placement: HyprMXPlacement) {
        let nsError = error as NSError
        let hyprMXError:HyprMXError = HyprMXError(UInt32(nsError.code))
        print("adDisplayError: \(nsError.localizedDescription) placement: \(placement.placementName)")
        updateUIAdDisplayError(placement: placement, error: hyprMXError)
    }

    /** Messaged when user has earned a reward. */
    func adDidReward(placement: HyprMXPlacement, rewardName: String?, rewardValue: Int) {
        print("adDidRewardForPlacement: ", placement.placementName as Any, " - reward: ", rewardName as Any, " value: ", rewardValue)
        updateUIAdDidReward(placement: placement)
    }

    /** Messaged when an ad has not been shown but is no longer available. */
    func adExpired(placement: HyprMXPlacement) {
        print("adExpiredForPlacement: ", placement.placementName as Any)
        updateUIAdExpired(placement: placement)
    }
    
    // MARK: - HyprMXBannerDelegate Implementation -
    
    /** Called in response to loadAd when an ad was loaded */
    func adDidLoad(_ bannerView: HyprMXBannerView) {
        print("adDidLoad: ", bannerView.placementName as Any)
        updateUIBannerLoaded(bannerView: bannerView)
    }
     
    /** Called in response to loadAd when there was an error loading an ad */
    func adFailed(toLoad bannerView: HyprMXBannerView, error: Error) {
        let nsError = error as NSError
        print("adFailed: \(nsError.localizedDescription) bannerView: \(String(describing: bannerView.placementName))")
        updateUIBannerFailedToLoad(bannerView: bannerView)
    }
     
    /** Called when the user clicks on the bannerView */
    func adWasClicked(_ bannerView: HyprMXBannerView) {
        print("adWasClicked: ", bannerView.placementName as Any)
        updateUIBannerAction(text: "Ad Clicked", bannerView: bannerView)
    }
     
    /** Called when a banner click will open a full-screen modal */
    func adDidOpen(_ bannerView: HyprMXBannerView) {
        print("adDidOpen: ", bannerView.placementName as Any)
        updateUIBannerAction(text: "Ad Opened", bannerView: bannerView)
    }
         
    /** Called when a full-screen modal has been closed */
    func adDidClose(_ bannerView: HyprMXBannerView) {
        print("adDidClose: ", bannerView.placementName as Any)
        updateUIBannerAction(text: "Ad Closed", bannerView: bannerView)
    }
     
    /** Called when a banner click will open another application */
    func adWillLeaveApplication(_ bannerView: HyprMXBannerView) {
        print("adWillLeaveApplication: ", bannerView.placementName as Any)
        updateUIBannerAction(text: "Ad Leaving Application", bannerView: bannerView)
    }
    
    // MARK: - IBActions -
    
    @IBAction func checkInventoryOneTapped(_ sender: UIButton) {
        self.loadAd(placementName: self.placementName1)
        styleLoadButton(index: 0, tapped: true)
    }
    
    @IBAction func checkInventoryTwoTapped(_ sender: Any) {
        self.loadAd(placementName: self.placementName2)
        styleLoadButton(index: 1, tapped: true)
    }

    @IBAction func showPlacementOne(_ sender: UIButton) {
        self.showAd(placementName: self.placementName1)
    }
    
    @IBAction func showPlacementTwo(_ sender: UIButton) {
        self.showAd(placementName: self.placementName2)
    }
    
    @IBAction func loadBannerTapped(_ sender: UIButton) {
        self.loadBannerAd()
        styleLoadButton(index: 2, tapped: true)
    }
    
}

