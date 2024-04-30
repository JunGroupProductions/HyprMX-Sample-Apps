//
//  HYPRSecondaryControllerRotationHelper.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>
#import <EventKitUI/EventKitUI.h>
#import <SafariServices/SafariServices.h>
#import "HYPRConstants.h"
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRSecondaryControllerRotationHelper : NSObject

+ (BOOL)shouldControllerRotate:(nonnull UIViewController *)controller;

+ (UIInterfaceOrientationMask)supportedInterfaceOrientationsForController:(nonnull UIViewController *)controller;

+ (UIInterfaceOrientation)preferredInterfaceOrientationForController:(nonnull UIViewController *)controller;

@end

/*
 * Subclass HYPRJavascriptAlertViewController so that we can override orientation callbacks
 *
 */
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRJavascriptAlertViewController : UIAlertController
@end

/*
 * Subclass SFSafariViewController so that we can override rotation delegates.
 *
 * -shouldAutorotate must return NO if there are no shared supported interface
 * orientations between the Application and the View Controller.
 * -preferredInterfaceOrientationForPresentation will return statusBar orientation since the offer view controller has already set that to the presentation mode of the offer
 */
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRSFSafariViewController : SFSafariViewController
@end

