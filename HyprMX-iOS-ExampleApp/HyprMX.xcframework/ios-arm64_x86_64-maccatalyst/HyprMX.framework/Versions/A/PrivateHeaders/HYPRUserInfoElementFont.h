//
//  HYPRUserInfoElementFont.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface HYPRUserInfoElementFont : NSObject

/** Name of Font */
@property (nonatomic, copy) NSString *fontName;

/** Font Size */
@property (nonatomic, copy) NSNumber *fontSize;

/** Color of font */
@property (nonatomic, copy) NSString *fontColor;

/** Color of font on disabled button */
@property (nonatomic, copy) NSString *disabledFontColor;

/** Text Alignment - Center - Left - Right */
@property (nonatomic, copy) NSString *textAlignment;

/** Line height of text lines */
@property (nonatomic, copy) NSNumber *textLineHeight;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
