//
//  HYPRRequiredInfoQuestion.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRRequiredInfoAnswer, HYPRUserInfoElementStyle;
@interface HYPRRequiredInfoQuestion : NSObject

/** Text of the question thats displayed on the section label */
@property (nonatomic, strong) NSString *questionText;

/** Key to identify the question to the server when sending answer */
@property (nonatomic, strong) NSString *questionName;

/** How many answers fit on one row in portrait */
@property (nonatomic, copy) NSNumber *answersPerLinePortrait;

/** Answer Type Format - Single Select, Numer Entry */
@property (nonatomic, copy) NSString *answerType;

/** Array of possible answers for the question */
@property (nonatomic, copy) NSArray<HYPRRequiredInfoAnswer *> *answers;

/** Style */
@property (nonatomic, strong) HYPRUserInfoElementStyle *style;

/** minimum input value */
@property (nonatomic, strong) NSNumber *min;

/** maximum input value */
@property (nonatomic, strong) NSNumber *max;

/** text for input placeholder */
@property (nonatomic, strong) NSString *hint;

/** text to display when answer violates min or max */
@property (nonatomic, strong) NSString *invalidAnswerMessage;

/** set by controller to link answer */
@property (nonatomic, strong) NSString *answerKey;

/** set by controller for use in cell rendering */
@property (nonatomic) BOOL answerIsInvalid;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

+ (NSArray<HYPRRequiredInfoQuestion*>*)questionsFromJSON:(NSString *)json;
@end
