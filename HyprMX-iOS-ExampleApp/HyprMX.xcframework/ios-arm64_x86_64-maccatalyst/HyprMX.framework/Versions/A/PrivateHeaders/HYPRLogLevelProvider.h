//
//  HYPRLogLevelProvider.h
//  HyprMX
//
//  Created by Tim Kerchmar on 1/17/24.
//  Copyright © 2024 HyprMX Mobile LLC. All rights reserved.
//

#ifndef HYPRLogLevelProvider_h
#define HYPRLogLevelProvider_h

@protocol HYPRLogLevelProvider
@property (atomic, assign) HYPRLogLevel logLevel;
@end

#endif /* HYPRLogLevelProvider_h */
