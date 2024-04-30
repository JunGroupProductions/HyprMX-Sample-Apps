//
//  HYPRMutableURLRequest.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 10/29/15.
//  Copyright © 2015 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HYPRMutableURLRequest : NSMutableURLRequest

/**
 * Retrieves the default WebKit UserAgent String and returns it as an NSString
 *
 * @return - User Agent String
 */
+ (NSString *)userAgentString;

@end
