//
//  HYPRImageCacheProvider.h
//  HyprMX
//
//  Created by Tim Kerchmar on 12/8/23.
//  Copyright © 2023 HyprMX Mobile LLC. All rights reserved.
//

#ifndef HYPRImageCacheProvider_h
#define HYPRImageCacheProvider_h

@class HYPRImageCache;

@protocol HYPRImageCacheProvider
@property (nonatomic, strong, readonly) NSURLSession * _Nonnull dataRequestSession;
- (nonnull HYPRImageCache *)sharedImageCache API_AVAILABLE(ios(13.4));

@end
#endif /* HYPRImageCacheProvider_h */
