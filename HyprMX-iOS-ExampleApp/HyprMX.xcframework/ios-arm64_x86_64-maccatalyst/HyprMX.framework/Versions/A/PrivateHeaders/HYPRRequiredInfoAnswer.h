//
//  HYPRRequiredInfoAnswer.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRUserInfoElementImage, HYPRUserInfoElementStyle, HYPRRequiredInfoSelectionShape;
@interface HYPRRequiredInfoAnswer : NSObject

/** Answer text as displayed on cell */
@property (nonatomic, copy) NSString *answerText;

/** answer value returned to server if answer is chosen */
@property (nonatomic, copy) NSString *value;

/** Image for answer cell */
@property (nonatomic, strong) HYPRUserInfoElementImage *image;

/** Style */
@property (nonatomic, strong) HYPRUserInfoElementStyle *style;

/** Selection Shape object definition */
@property (nonatomic, strong) HYPRRequiredInfoSelectionShape *selectionShape;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
@end
