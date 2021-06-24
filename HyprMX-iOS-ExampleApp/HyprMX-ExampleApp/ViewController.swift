//
//  ViewController.swift
//  HyprMX-ExampleApp
//
//  Created by Ben Balcomb on 8/5/19.
//  Copyright © 2019 hyprmx. All rights reserved.
//

import UIKit
import HyprMX

class ViewController: UIViewController, HyprMXPlacementDelegate, HyprMXInitializationDelegate {

    @IBOutlet weak var placementOneNameLabel: UILabel!
    @IBOutlet weak var placementTwoNameLabel: UILabel!
    
    @IBOutlet weak var placementOneStatusLabel: UILabel!
    @IBOutlet weak var placementTwoStatusLabel: UILabel!
    
    @IBOutlet weak var placementOneInventoryButton: UIButton!
    @IBOutlet weak var placementTwoInventoryButton: UIButton!
    
    @IBOutlet weak var placementOneShowButton: UIButton!
    @IBOutlet weak var placementTwoShowButton: UIButton!
    
    @IBOutlet weak var sdkVersionLabel: UILabel?
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView?

    #warning("You must set a Distributor ID to run the Example App with")
    let myDistributorID = "1000198877"
    
    #warning("You must set your placement names to run the Example App with")
    let placementName1:String = "Vast"
    let placementName2:String = "Mraid"

    var placements:[HyprMXPlacement] = []
    
    func uniqueUserId() -> String {
        /**
         * HyprMX requires a userID for each user.
         * If your application does not create a userID already,
         * you may use this code block to create and store a unique userID for each user.
         */
        let userDefaultsUserIDKey = "hyprUserID"
        var userID = ""

        if let storedUserID = UserDefaults.standard.object(forKey: userDefaultsUserIDKey) as? String {
            userID = storedUserID
        } else {
            userID = ProcessInfo.processInfo.globallyUniqueString
            UserDefaults.standard.set(userID, forKey: userDefaultsUserIDKey)
        }
        return userID
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Initialize HyprMX before loading ads on your placements.
        // You can begin to load ads once your HyprMXInitializationDelegate implementation receives
        // the initializationDidComplete() callback.
        
        HyprMX.initialize(withDistributorId: myDistributorID,
                          // HyprMX requires a unique userID for each user.
                          userId: self.uniqueUserId(),
                          // If you don't have consent status for the user, set consentStatus to CONSENT_STATUS_UNKNOWN
                          consentStatus: CONSENT_STATUS_UNKNOWN,
                          initializationDelegate: self)
        
        for placementName in [placementName1, placementName2] {
            // You can get HyprMXPlacement objects from HyprMX by their placement Name
            let placement:HyprMXPlacement = HyprMX.getPlacement(placementName)
            // Set a placementDelegate on each of your placements to receive callback on ad display status.
            placement.placementDelegate = self;
            placements.append(placement)
        }
        
        setUpUI()
    }

    // MARK: - loadAd Action -

    func loadAd(placementName: String) {
        /**
         * loadAd will check for an ad to present for this placement.
         * The result of this call will be a delegate message to adAvailableForPlacement: if there's an ad to show, or
         * adNotAvailableForPlacement: if there's no inventory.
         */
        HyprMX.getPlacement(placementName)?.loadAd()
    }
    
    // MARK: - showAd Action -
    func showAd(placementName: String) {
        guard let placement = HyprMX.getPlacement(placementName) else {
            print("HyprMX failed to return placement")
            return
        }

        /**
         * Check the state of isAdAvailable before attempting to show an ad
         */
        if placement.isAdAvailable() {
            /**
             * showAd will begin presentation of an ad.
             * The placement will message adWillStartForPlacement: immediately before attempting to present;
             * adDidCloseForPlacement: when everything is off screen;
             * and adDidRewardForPlacement: if the ad completed successfully and the user should receive a reward.
             * If there is no ad to display or an error occurs during presentation,
             * adDisplayErrorForPlacement:error: will be messaged with an error description,
             * then adDidCloseForPlacement: will be messaged.
             */
            placement.showAd(from: self)
        } else {
            print("No ads available for placement ", placementName)
        }
    }
    
    // MARK: - HyprMXInitializationDelegate Implementation -
    
    /** Messaged when HyprMX has completed initializing.  You can call loadAd on your placements to load inventory after this messaged has been received. */
    func initializationDidComplete() {
        print("Initialization of HyprMX Completed Successfully")
        updateUIInitializationSuccess()
    }

    /** Messaged when HyprMX could not initialize. */
    func initializationFailed() {
        print("Initialization of HyprMX Failed - please re-initialize")
        updateUIInitializationFailed()
    }
    
    // MARK: - HyprMXPlacementDelegate Implementation -

    /** Messaged in response to loadAd when there is an ad to show */
    func adAvailable(for placement: HyprMXPlacement) {
        print("adAvailableForPlacement: ", placement.placementName as Any)
        updateUIAdAvailable(placement: placement)
    }

    /** Messaged in response to loadAd when there's no ad to show */
    func adNotAvailable(for placement: HyprMXPlacement) {
        print("adNotAvailableForPlacement: ", placement.placementName as Any)
        updateUIAdNotAvailable(placement: placement, alertOn: true)
    }

    /** Messaged immediately before attempting to present an ad. */
    func adWillStart(for placement: HyprMXPlacement) {
        print("adWillStartForPlacement: ", placement.placementName as Any)
        updateUIAdWillStart(placement: placement)
    }

    /** Messaged upon conclusion of any ad presentation attempt */
    func adDidClose(for placement: HyprMXPlacement, didFinishAd finished: Bool) {
        print("adDidCloseForPlacement: ", placement.placementName as Any)
        updateUIAdDidClose(placement: placement, finished: finished)
    }

    /** Messaged when an error occurs during ad presentation. */
    func adDisplayError(for placement: HyprMXPlacement, error hyprMXError: HyprMXError) {
        print("adDisplayErrorForPlacement: ", placement.placementName as Any)
        updateUIAdDisplayError(placement: placement, error: hyprMXError)
    }

    /** Messaged when user has earned a reward. */
    func adDidReward(for placement: HyprMXPlacement, rewardName: String?, rewardValue: Int) {
        print("adDidRewardForPlacement: ", placement.placementName as Any, " - reward: ", rewardName as Any, " value: ", rewardValue)
        updateUIAdDidReward(placement: placement)
    }

    /** Messaged when an ad has not been shown but is no longer available. */
    func adExpired(for placement: HyprMXPlacement) {
        print("adExpiredForPlacement: ", placement.placementName as Any)
        updateUIAdExpired(placement: placement)
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
}

