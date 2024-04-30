//
//  HYPRUserInfoAppearance.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRFooter, HYPRUserInfoNavigationBarAppearance, HYPRUserInfoHeader, HYPRUserInfoSubmitButton;

@interface HYPRUserInfoAppearance : NSObject

/** property backgroundColor is the string value of the color to draw on the background of the user info form */
@property (nonatomic, copy) NSString *backgroundColor;

/** Navigation Bar Appearance Properties */
@property(nonatomic, strong) HYPRUserInfoNavigationBarAppearance *navigationBarAppearance;

/** Title Section Appearance Properties */
@property(nonatomic, strong) HYPRUserInfoHeader *titleSectionAppearance;

/** Headers Placed above Questions */
@property(nonatomic, copy) NSArray<HYPRUserInfoHeader *> *headers;

/** Title Section Appearance Properties */
@property(nonatomic, strong) HYPRUserInfoSubmitButton *submitButton;

/** Footer section of user info form */
@property(nonatomic, strong) HYPRFooter *footer;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
@end
