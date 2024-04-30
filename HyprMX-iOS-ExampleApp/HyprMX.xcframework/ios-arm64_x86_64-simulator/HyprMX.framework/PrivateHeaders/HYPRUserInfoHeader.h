//
//  HYPRUserInfoHeader.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRUserInfoElementStyle, HYPRUserInfoElementImage;
@interface HYPRUserInfoHeader : NSObject

/** Style */
@property (nonatomic, strong) HYPRUserInfoElementStyle *style;

/** Image to display on header */
@property (nonatomic, strong) HYPRUserInfoElementImage *image;

/** Text displayed on Header */
@property (nonatomic, copy) NSString *text;

/** URL to navigate to on click */
@property (nonatomic, copy) NSString *urlString;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
@end
