//
//  ViewController.swift
//  HyprMX-ExampleTableViewApp
//
//  Created by Sean Reinhardt on 7/20/21.
//  Copyright © 2021 hyprmx. All rights reserved.
//

import UIKit
import HyprMX
class TableViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, HyprMXInitializationDelegate {
    
    @IBOutlet weak var tableView: UITableView!
    let TABLE_CELL_COUNT = 150
    @IBOutlet weak var placementNameLabel: UILabel!
    @IBOutlet weak var reloadAdsButton: UIButton!
    let BANNER_CELL_FREQUENCY = 5
    let CELL_HEIGHT:CGFloat = 60.0
    
    // Reference to banners for reloading ads
    var banners:Set<HyprMXBannerView> = []
    #warning("Set your Distributor ID to run the Example App with")
    let myDistributorID = "11000124103"
    
    #warning("Set your placement names to run the Example App with")
    let placementNameBanner:String = "banner_320_50"
    let bannerAdSize = kHyprMXAdSizeBanner
    
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
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        HyprMX.initialize(withDistributorId: myDistributorID, userId: uniqueUserId(), consentStatus: CONSENT_STATUS_UNKNOWN, initializationDelegate: self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.placementNameLabel.text = placementNameBanner
        self.reloadAdsButton.isEnabled = false
        tableView.delegate = self
    }

    func initializationDidComplete() {
        tableView.dataSource = self
        tableView.reloadData()
        self.reloadAdsButton.isEnabled = true
    }
    
    func initializationFailed() {
        print("HyprMX Initialization Failed")
    }
    
    
    @IBAction func reloadAdsTapped(_ sender: Any) {
        for banner:HyprMXBannerView in banners {
            banner.loadAd()
        }
    }
    
    // MARK: - TableViewController -
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        TABLE_CELL_COUNT
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return CELL_HEIGHT
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        if (indexPath.row % BANNER_CELL_FREQUENCY == 0) {
            let cell:BannerAdCell = self.tableView.dequeueReusableCell(withIdentifier: "com.hyprmx.banneradcell") as! BannerAdCell
            cell.configureCell(placementName: placementNameBanner, adSize: bannerAdSize)
            banners.insert(cell.bannerView)
            return cell
        }
        let cell:ContentTableViewCell = self.tableView.dequeueReusableCell(withIdentifier: "com.hyprmx.contentcell") as! ContentTableViewCell
        cell.contentLabel.text = "Content Cell # \(indexPath.row - indexPath.row/BANNER_CELL_FREQUENCY)"
        return cell
    }
    
}

