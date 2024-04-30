//
//  HYPRWebViewAsyncScriptEvent.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 3/31/21.
//  Copyright © 2021 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HYPRWebViewLoadDataEvent : NSObject
@property (strong, nonatomic) NSString *webData;
@property (strong, nonatomic) NSString *baseUrl;
+(nullable instancetype)fromDictionary:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
