//
//  AppDelegate.swift
//  HyprMX-ExampleTableViewApp
//
//  Created by Sean Reinhardt on 7/20/21.
//  Copyright © 2021 hyprmx. All rights reserved.
//

import UIKit
import HyprMX

@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        // Pass EIDs to HyprMX before initializing for best results
        // passEIDSToHyprMX()
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }

    func passEIDSToHyprMX() {
        let uid2 = [
            [
                "id": "testUID2Id"
            ]
        ]

        let id5 = [
            [
                "id": "testID5Id",
                "linkType": 2, // Optional. Only integer values 0..3 are allowed.
                "abTestingControlGroup": true // Optional
            ]
        ]

        let liveintent = [
            [
                "id": "testLiveintentId",
                "atype": 1 // Optional. Only integer values 1, 2, 3, or 500+ allowed
            ]
        ]

        let eids = [
            "uid2": uid2,
            "id5": id5,
            "liveintent": liveintent
        ]

        if let eidData = try? JSONSerialization.data(withJSONObject: eids) {
            // Pass EID json string to HyprMX
            HyprMX.setUserExtras(String(data: eidData, encoding: .utf8) ?? "", for: "eids")
        }
    }
}
