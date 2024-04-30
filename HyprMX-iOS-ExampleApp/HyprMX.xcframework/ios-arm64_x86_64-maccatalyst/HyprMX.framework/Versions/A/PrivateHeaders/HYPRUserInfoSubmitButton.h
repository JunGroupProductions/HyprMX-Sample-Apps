//
//  HYPRUserInfoSubmitButton.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRUserInfoElementStyle, HYPRUserInfoElementImage;

@interface HYPRUserInfoSubmitButton : NSObject

/** Style */
@property (nonatomic, strong) HYPRUserInfoElementStyle *style;

/** Image for Submit button */
@property (nonatomic, strong) HYPRUserInfoElementImage *submitImage;

/** Submit button text */
@property (nonatomic, copy) NSString *text;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
