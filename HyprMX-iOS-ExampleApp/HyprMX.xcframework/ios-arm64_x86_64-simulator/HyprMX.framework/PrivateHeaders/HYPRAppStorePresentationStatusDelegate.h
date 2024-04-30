//
//  HYPRAppStorePresentationStatusDelegate.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 7/29/20.
//  Copyright © 2020 HyprMX Mobile LLC. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>

@protocol HYPRAppStorePresentationStatusDelegate <NSObject>
NS_ASSUME_NONNULL_BEGIN
@required
- (void)appStorePresentation:(nullable SKStoreProductViewController *)controller failedWithError:(NSError *)error;
- (void)appStorePresentationPresentedProductController:(SKStoreProductViewController *)controller;
- (void)fullScreenPresentationFinishedPresentation:(SKStoreProductViewController *)viewController;
#if TARGET_OS_MACCATALYST == 0
- (void)appStorePresentationPresentedOverlay:(SKOverlay *)overlay API_AVAILABLE(ios(14.0));
- (void)overlayPresentationFinishedPresentation:(SKOverlay *)overlay API_AVAILABLE(ios(14.0));
#endif
@end
NS_ASSUME_NONNULL_END
