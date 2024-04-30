//
//  HYPRUserInfoNavigationBarAppearance.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRUserInfoElementImage, HYPRUserInfoElementStyle;
@interface HYPRUserInfoNavigationBarAppearance : NSObject

/** Style */
@property (nonatomic, strong) HYPRUserInfoElementStyle *style;

/** Text displayed on close button */
@property (nonatomic, copy) NSString *closeButtonText;

/** Text displayed on submit button */
@property (nonatomic, copy) NSString *submitButtonText;

/** Behavior of Submit Button - Valid options are:
 * -Always
 * -Complete
 * -Auto 
 */
@property (nonatomic, copy) NSString *submitButtonBehavior;

/** Image for submit button */
@property (nonatomic, strong) HYPRUserInfoElementImage *submitImage;

/** Image for close button */
@property (nonatomic, strong) HYPRUserInfoElementImage *closeImage;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
