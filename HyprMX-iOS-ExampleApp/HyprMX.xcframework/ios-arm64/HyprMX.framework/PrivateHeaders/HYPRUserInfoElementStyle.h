//
//  HYPRUserInfoElementStyle.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRUserInfoElementFont, HYPRUserInfoElementBorder;

@interface HYPRUserInfoElementStyle : NSObject

/** Hex description of section background color */
@property (nonatomic, copy) NSString *backgroundColor;

/** Hex description of section placeholder color */
@property (nonatomic, copy) NSString *placeholderColor;

/** Hex description of section disabled background color */
@property (nonatomic, copy) NSString *disabledBackgroundColor;

/** Hex description of section selected background border color */
@property (nonatomic, copy) NSString *selectedBackgroundColor;

/** float values of inside padding */
@property (nonatomic, copy) NSArray<NSNumber *> *padding;

/** float value of outside margins */
@property (nonatomic, copy) NSArray<NSNumber *> *margin;

/** float value of corner radius */
@property (nonatomic, copy) NSNumber *cornerRadius;

/** Font description for section */
@property (nonatomic, strong) HYPRUserInfoElementFont *font;

/** Border description for section */
@property (nonatomic, strong) HYPRUserInfoElementBorder *border;

/** Float value of shadow elevation */
@property (nonatomic, copy) NSNumber *shadowElevation;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
