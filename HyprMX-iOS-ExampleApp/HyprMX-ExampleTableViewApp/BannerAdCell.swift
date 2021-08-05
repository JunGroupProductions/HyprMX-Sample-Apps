//
//  BannerAdCell.swift
//  HyprMX-ExampleTableViewApp
//
//  Created by Sean Reinhardt on 7/20/21.
//  Copyright © 2021 hyprmx. All rights reserved.
//

import UIKit
import HyprMX
class BannerAdCell: UITableViewCell {

    // HyprMXBannerView defined in main.storyboard
    @IBOutlet weak var bannerView: HyprMXBannerView!
    
    func configureCell(placementName:String, adSize:CGSize) {
        // If placementName and adSize are not set in Interface Builder, set them before loading ads
        if (self.bannerView.placementName != nil) {
            return
        }
        self.bannerView.placementName = placementName
        self.bannerView.adSize = adSize
    
        // Call loadAd on your banner when you're ready to show the ad.
        self.bannerView.loadAd()
    }

}
