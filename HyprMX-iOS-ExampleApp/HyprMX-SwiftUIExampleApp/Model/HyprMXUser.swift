//
//  HyprMXUser.swift
//  HyprMX-SwiftUIExampleApp
//
//  Created by Sean Reinhardt on 7/23/21.
//  Copyright © 2021 hyprmx. All rights reserved.
//

import Foundation
import HyprMX

struct HyprMXUser: Codable {
    var userId: String {
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
    let distributorId: String
    
    func initSDK(delegate:HyprMXInitializationDelegate) {
        HyprMX.initialize(withDistributorId: distributorId, userId: userId, initializationDelegate: delegate)
    }
}
