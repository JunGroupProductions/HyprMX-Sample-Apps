//
//  HyprManager.h
//  HyprMX
//
//  Created by Tim Kerchmar on 11/14/23.
//  Copyright © 2023 HyprMX Mobile LLC. All rights reserved.
//

#ifndef HyprManager_h
#define HyprManager_h

#import <JavaScriptCore/JavaScriptCore.h>
#import <HyprMX/HYPRAudioDelegateSource.h>
#import <HyprMX/HYPRHostAppInformationProvider.h>
#import <HyprMX/HyprMX.h>
#import <HyprMX/HYPRController.h>
#import <HyprMX/HyprMX-Swift.h>
#import <HyprMX/HYPRLogLevelProvider.h>

#define HyprMXStateNames @[@"NOT_INITIALIZED", @"INITIALIZING", @"INITIALIZATION_FAILED", @"INITIALIZATION_COMPLETE"]

@class HYPRMediationProvider;

API_AVAILABLE(ios(13.4))
@interface HyprManager : NSObject
<HYPRAudioDelegateSource, HYPRHostAppInformationProvider, HYPRLogLevelProvider>

// Loosely coupled to @objc var Manager.controller by the guarantee to Objective-C
@property (nullable, strong, nonatomic) HYPRController *controller;

@property (nullable, strong, nonatomic) NSString *initializationHostName;

// Loosely coupled to @objc var Manager.sharedInstance() by the guarantee to Objective-C
+ (nonnull HyprManager *)sharedInstance;

@end
#endif /* HyprManager_h */
