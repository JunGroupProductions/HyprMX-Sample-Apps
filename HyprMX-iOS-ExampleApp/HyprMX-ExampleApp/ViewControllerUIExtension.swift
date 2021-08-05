//
//  ViewControllerUIExtension.swift
//  HyprMX-ExampleApp
//
//  Created by Ben Balcomb on 8/12/19.
//  Copyright © 2019 hyprmx. All rights reserved.
//

import Foundation
import UIKit
import HyprMX

// For UI functionality
extension ViewController {

    func setUpUI() {
        navigationItem.titleView = UIImageView(image: UIImage(named: "hyprLogo"))
        hideUI(isHidden: true)
        let bundle = Bundle(for: HyprMX.self)

        if let versionString = bundle.object(forInfoDictionaryKey: "CFBundleShortVersionString") as? String {
            let versionNum = Int(HyprMXVersionNumber)
            sdkVersionLabel?.text = String(format: "HyprMX SDK Version %@ (b%d)", versionString, versionNum)
        }
        self.placementOneNameLabel.text = self.placementName1
        self.placementTwoNameLabel.text = self.placementName2
        self.bannerPlacementNameLabel.text = self.placementNameBanner
        self.placementOneStatusLabel.text = ""
        self.placementTwoStatusLabel.text = ""
        self.bannerPlacementStatusLabel.text = ""
        
        styleShowButton(index: 0, isReady: false)
        styleShowButton(index: 1, isReady: false)
        styleLoadButton(index: 0, tapped: false)
        styleLoadButton(index: 1, tapped: false)
        styleLoadButton(index: 2, tapped: false)
    }

    func updateUIInitializationSuccess() {
        activityIndicator?.stopAnimating()
        hideUI(isHidden: false)
    }

    func updateUIInitializationFailed() {
        activityIndicator?.stopAnimating()
    }
    
    func updateUIAdAvailable(placement:HyprMXPlacement) {
        let index = index(fromPlacement: placement)
        statusLabelForIndex(index: index).text = "Ad Available."
        styleShowButton(index:index, isReady: true)
        styleStatusAlert(index:index, alertOn: false)
    }

    func updateUIAdNotAvailable(placement:HyprMXPlacement, alertOn: Bool) {
        let index = index(fromPlacement: placement)
        statusLabelForIndex(index: index).text = alertOn ? "No Ads Available." : ""
        styleStatusAlert(index: index, alertOn: alertOn)
        styleShowButton(index: index, isReady: false)
    }

    func updateUIAdWillStart(placement:HyprMXPlacement) {
        let index = index(fromPlacement: placement)
        statusLabelForIndex(index: index).text = "Ad Started."
        styleShowButton(index:index, isReady: false)
        styleStatusAlert(index:index, alertOn: false)
    }

    func updateUIAdDidClose(placement:HyprMXPlacement, finished: Bool) {
        let index = index(fromPlacement: placement)
        let statusLabel:UILabel = statusLabelForIndex(index: index)
        statusLabel.text = statusLabel.text! + (finished ? " Ad Finished." : " Ad Canceled.")
        styleShowButton(index:index, isReady: false)
    }

    func updateUIAdDisplayError(placement:HyprMXPlacement, error: HyprMXError) {
        var reason = "Placement Does Not Exist"

        if error == NO_FILL {
            reason = "No Fill"
        } else if error == DISPLAY_ERROR {
            reason = "Display Error"
        }

        let index = index(fromPlacement: placement)
        let statusLabel:UILabel = statusLabelForIndex(index: index)
        statusLabel.text = statusLabel.text! + String(format: " Error: \"%@\".", reason)
        styleStatusAlert(index:index, alertOn: true)
        styleShowButton(index:index, isReady: false)
    }

    func updateUIAdDidReward(placement:HyprMXPlacement) {
        let index = index(fromPlacement: placement)
        let statusLabel:UILabel = statusLabelForIndex(index: index)
        statusLabel.text = statusLabel.text! + " Reward Delivered."
        styleStatusAlert(index:index, alertOn: false)
    }

    func updateUIAdExpired(placement:HyprMXPlacement) {
        let index = index(fromPlacement: placement)
        statusLabelForIndex(index: index).text = "Ad Expired."
        styleShowButton(index:index, isReady: false)
    }
    
    func updateUIBannerLoaded(bannerView:HyprMXBannerView) {
        let statusLabel:UILabel = statusLabelForIndex(index: 2)
        statusLabel.text = "Ad Loaded."
        styleStatusAlert(index:2, alertOn: false)
    }
    
    func updateUIBannerFailedToLoad(bannerView:HyprMXBannerView) {
        let statusLabel:UILabel = statusLabelForIndex(index: 2)
        statusLabel.text = "No Ads Available."
        styleStatusAlert(index:2, alertOn: false)
    }
    
    func updateUIBannerAction(text:String, bannerView:HyprMXBannerView) {
        let statusLabel:UILabel = statusLabelForIndex(index: 2)
        statusLabel.text = "\(statusLabel.text!) \(text)."
        styleStatusAlert(index:2, alertOn: false)
    }
    
    func hideUI(isHidden:Bool) {
        self.placementOneNameLabel.isHidden = isHidden;
        self.placementTwoNameLabel.isHidden = isHidden;
        self.bannerPlacementNameLabel.isHidden = isHidden
        self.placementOneStatusLabel.isHidden = isHidden;
        self.placementTwoStatusLabel.isHidden = isHidden;
        self.bannerPlacementStatusLabel.isHidden = isHidden
        self.placementOneInventoryButton.isHidden = isHidden;
        self.placementTwoInventoryButton.isHidden = isHidden;
        self.placementOneShowButton.isHidden = isHidden
        self.placementTwoShowButton.isHidden = isHidden
        self.bannerLoadButton.isHidden = isHidden
    }
    
    func index(fromPlacement:HyprMXPlacement) -> Int {
        return placements.firstIndex(of: fromPlacement) ?? 0
    }
    
    func statusLabelForIndex(index:Int) -> UILabel {
        return [self.placementOneStatusLabel, self.placementTwoStatusLabel, self.bannerPlacementStatusLabel][index]
    }
    
    func loadButtonForIndex(index:Int) -> UIButton {
        return [self.placementOneInventoryButton, self.placementTwoInventoryButton, self.bannerLoadButton][index]
    }
    
    func showButtonForIndex(index:Int) -> UIButton {
        return [self.placementOneShowButton, self.placementTwoShowButton][index]
    }
    
    func renderAdAvailable(index:Int) {
        statusLabelForIndex(index: index).text = "Ad Available."
        styleShowButton(index: index, isReady: true)
        styleStatusAlert(index: index, alertOn: false)
    }

    func renderAdNotAvailable(index:Int, alertOn: Bool) {
        statusLabelForIndex(index: index).text = alertOn ? "No Ads Available." : ""
        styleStatusAlert(index: index, alertOn: alertOn)
        styleShowButton(index: index, isReady: false)
    }

    func renderAdWillStart(index:Int) {
        statusLabelForIndex(index: index).text = "Ad Started."
        styleShowButton(index: index, isReady: false)
        styleStatusAlert(index: index, alertOn: false)
    }

    func renderAdDidClose(index:Int, finished: Bool) {
        let statusLabel:UILabel = statusLabelForIndex(index: index)
        statusLabel.text = statusLabel.text! + (finished ? " Ad Finished." : " Ad Canceled.")
        styleShowButton(index: index, isReady: false)
    }

    func renderAdDisplayError(index:Int, error: Error) {
        let reason = (error as NSError).localizedDescription
        let statusLabel:UILabel = statusLabelForIndex(index: index)
        statusLabel.text = statusLabel.text! + String(format: " Error: \"%@\".", reason)
        styleStatusAlert(index: index, alertOn: true)
        styleShowButton(index: index, isReady: false)
    }

    func renderAdDidReward(index:Int) {
        let statusLabel:UILabel = statusLabelForIndex(index: index)
        statusLabel.text = statusLabel.text! + " Reward Delivered."
        styleStatusAlert(index: index, alertOn: false)
    }

    func renderAdExpired(index:Int) {
        statusLabelForIndex(index: index).text = "Ad Expired."
        styleShowButton(index: index, isReady: false)
    }
    
    func styleLoadButton(index:Int, tapped: Bool) {
        let loadButton:UIButton = loadButtonForIndex(index: index)
        loadButton.backgroundColor = tapped ? UIColor.lightGray : UIColor.white
        loadButton.setTitleColor(tapped ? UIColor.white : UIColor.darkGray, for:UIControl.State.normal)
        loadButton.layer.borderWidth = 1
        loadButton.layer.borderColor = UIColor.gray.cgColor
    }
    
    func styleShowButton(index:Int, isReady: Bool) {
        let showButton:UIButton = showButtonForIndex(index: index)
        showButton.backgroundColor = isReady ? UIColor.white : UIColor(white: 0.8, alpha: 1)
        showButton.setTitleColor(isReady ? UIColor.darkGray : UIColor.lightGray,
                                 for: UIControl.State.normal)
        showButton.layer.borderWidth = 1
        showButton.layer.borderColor = UIColor.gray.cgColor
        styleLoadButton(index: index, tapped: false)
    }
    
    func styleStatusAlert(index:Int, alertOn: Bool) {
        statusLabelForIndex(index: index).textColor = alertOn ? UIColor.red : UIColor(named: "statusTextColor")
        if (index < placements.count) {
            showButtonForIndex(index: index).layer.borderColor = alertOn ? UIColor.red.cgColor : UIColor.lightGray.cgColor
        }
    }
}
