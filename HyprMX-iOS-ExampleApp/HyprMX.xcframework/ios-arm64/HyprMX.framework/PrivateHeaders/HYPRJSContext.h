//
//  HYPRJSContext.h
//  HyprMX
//
//  Created by Ben Balcomb on 10/29/19.
//  Copyright © 2019 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavascriptCore/JavascriptCore.h>

NS_ASSUME_NONNULL_BEGIN

@protocol HYPRJSContextProtocol

- (NSString*)scriptToCheckObject:(NSString*)name
                            type:(NSString*)type;

- (JSValue*)callFunction:(NSString*)function
           withArguments:(nullable NSArray*)args;

+(NSString *)apostropheEscapedString:(NSString *)unescapedString;

- (NSString *)setNativeObject:(NSObject *)object hash:(NSUInteger)hash;
- (void)removeObjectByHash:(NSUInteger)hash;
@end

@protocol HYPRJSContextInitRequestProtocol
-(BOOL)requestInitializationAllowed;
@end

@interface HYPRJSContext:JSContext <HYPRJSContextProtocol, HYPRJSContextInitRequestProtocol>
@end
NS_ASSUME_NONNULL_END
