//
//  HYPRHostAppInformationProvider.h
//  HyprMX
//
//  Created by Tim Kerchmar on 10/27/23.
//  Copyright © 2023 HyprMX Mobile LLC. All rights reserved.
//

#ifndef HYPRHostAppInformationProvider_h
#define HYPRHostAppInformationProvider_h

@protocol HYPRHostAppInformationProvider <NSObject>

@property (readonly, nullable, strong) NSMutableDictionary *userExtras;
@property (atomic, assign) BOOL ageRestrictedUser;
@property (nullable, strong, nonatomic) NSString *unityVersion;

@end

#endif /* HYPRHostAppInformationProvider_h */
