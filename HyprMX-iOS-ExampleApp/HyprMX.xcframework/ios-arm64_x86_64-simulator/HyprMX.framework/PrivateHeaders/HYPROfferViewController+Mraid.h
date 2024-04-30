//
//  HYPROfferViewController+Mraid.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 3/29/21.
//  Copyright © 2021 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HYPROfferViewController.h"
#import "HYPRMRAIDSupport.h"
#import "HYPRPhotoActivityViewHelper.h"

NS_ASSUME_NONNULL_BEGIN

@interface HYPROfferViewController(Mraid) <HYPRMRAIDEventReceiver, HYPRPhotoActivityDelegate>

@end

NS_ASSUME_NONNULL_END
