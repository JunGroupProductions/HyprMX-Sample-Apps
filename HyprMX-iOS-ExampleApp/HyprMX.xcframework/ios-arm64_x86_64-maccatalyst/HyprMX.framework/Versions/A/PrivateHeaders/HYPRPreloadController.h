//  HYPRPreloadController.h
//  HyprMX-Framework

#ifndef HYPRPreloadController_h
#define HYPRPreloadController_h

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <HyprMX/HYPRImageCacheProvider.h>
#import <HyprMX/HYPRJSContext.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString *const kHYPRDeveloperSettingsDictionaryKeyPlacementId;
extern NSString *const kHYPRDeveloperSettingsDictionaryKeyAdId;
extern NSString *const kHYPRDeveloperSettingsDictionaryKeyTimeToExpiration;
extern NSString *const kHYPRDeveloperSettingsDictionaryKeyPlacementName;
extern NSString *const kHYPRDeveloperSettingsDictionaryKeyRewardToken;

/**
 * Protocol to bind the preload controller to the JS Core
 */
@protocol HYPRPreloadListenerProtocol <JSExport>

/**
 * Preload an image that has a portrait url
 * @param portrait_url       The URL to load
 * @param height             The height of the desired image
 * @param width              The width of the desired image
 * @param fill_screen_width  Flag to indicate if the image should fill the screen
 */
JSExportAs(preloadPortraitImage, -(void) preloadPortraitImage:(NSString*)portrait_url height:(NSNumber*)height width:(NSNumber*)width fill_screen_width:(BOOL)fill_screen_width);

/**
 * Preload an image
 *
 * @param url     The URL to load
 * @param height  The height of the desired image
 * @param width   The width of the desired image
 * @param scale   The scale factor
 * @param tiled   Indicates if the image is tiled
 * @param x       The x location of the image in the image
 * @param y       The y location of the image in the image
 *
 */
JSExportAs(preloadUIImage, -(void) preloadUIImage:(NSString*)url height:(NSNumber*)height width:(NSNumber*)width scale:(NSNumber *)scale tiled:(BOOL)tiled x:(NSNumber *)x y:(NSNumber *)y);

- (void)storeInstance:(NSString *)instanceId;
@end

/**
 * This class is responsible for pre-loading offers
 **/
API_AVAILABLE(ios(13.4))
@interface HYPRPreloadController : NSObject <HYPRPreloadListenerProtocol>

/**
 * Initialize the controller with the JS Context
 * @param context The JS Context
 * @return The HYPRPreloadController initialized with
 */
- (instancetype)initWithContext:(JSContext<HYPRJSContextProtocol> *)context imageCacheProvider:(NSObject<HYPRImageCacheProvider> *)controller;

-(void)addSelfToContext;

/**
 * Retrieves preloaded ad for placement
 * @return Preloaded ad or nil
 */
- (nullable UIView *)popPreloadedAdForPlacement:(NSString *)placementName;

@end

NS_ASSUME_NONNULL_END

#endif // HYPRPreloadController_h
