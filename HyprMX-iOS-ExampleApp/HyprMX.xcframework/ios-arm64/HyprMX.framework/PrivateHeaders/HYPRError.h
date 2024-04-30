//
//  HYPRError.h
//  HyprMX-Framework
//
//  Created by Kevin E. Rafferty II on 4/6/16.
//  Copyright © 2016 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HYPRLogger.h"
#import "HYPRConstants.h"
#import "HYPRErrorType.h"

HYPR_CLASS_AVAILABLE_IOS
@interface HYPRError : NSObject

#pragma mark - Analytics Properties -

// Analytics categorization Properites (Required)
// Properties are set in init
@property (strong, nonatomic, readonly) NSString *eventType;
@property (strong, nonatomic, readonly) NSString *eventDescription;  // Optional
@property (strong, nonatomic, readonly) NSNumber *eventSeverityCode;
@property (strong, nonatomic, readonly) NSString *eventCollectionType;


#pragma mark - wrappers for init and send -

+ (void)sendErrorWithCollectionType:(HYPRErrorCollectionType)collection
                   eventSummaryType:(HYPRErrorType)summary
                   eventDescription:(NSString *)description
                  eventSeverityCode:(NSNumber *)severity;

- (HYPRError *)initWithCollectionType:(HYPRErrorCollectionType)collection
                               eventSummaryType:(HYPRErrorType)summary
                               description:(NSString *)description
                              severityCode:(NSNumber *)severity;

+ (NSString *)stringForErrorType:(HYPRErrorType)errorType;
+ (NSString *)stringForErrorCollection:(HYPRErrorCollectionType)collectionType;

@end
