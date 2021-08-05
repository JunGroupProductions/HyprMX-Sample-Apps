//
//  HyprMXBannerView.h
//  HyprMX
//


#import <UIKit/UIKit.h>
#import <HyprMX/HyprMXPlacement.h>
NS_ASSUME_NONNULL_BEGIN

@protocol HyprMXBannerDelegate;
extern NSString * const kHyprMXBannerAdErrorDomain;

extern CGSize const kHyprMXAdSizeShort;
extern CGSize const kHyprMXAdSizeBanner;
extern CGSize const kHyprMXAdSizeMediumRectangle;
extern CGSize const kHyprMXAdSizeLeaderBoard;
extern CGSize const kHyprMXAdSizeSkyScraper;

IB_DESIGNABLE
@interface HyprMXBannerView : UIView

@property (nonatomic, strong, nullable) IBInspectable NSString *placementName;
@property (nullable, nonatomic, weak) IBOutlet id<HyprMXBannerDelegate> placementDelegate;
@property (nonatomic) IBInspectable CGSize adSize;

/** Gets the type of placement */
@property (assign, nonatomic, readonly) HyprMXPlacementType placementType;

- (instancetype)initWithPlacementName:(nullable NSString *)placementName adSize:(CGSize)size;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (void)loadAd;

@end

@protocol HyprMXBannerDelegate <NSObject>
@optional
-(void)adDidLoad:(HyprMXBannerView *)bannerView;
-(void)adFailedToLoad:(HyprMXBannerView *)bannerView error:(NSError *)error;
-(void)adDidOpen:(HyprMXBannerView *)bannerView;
-(void)adDidClose:(HyprMXBannerView *)bannerView;
-(void)adWasClicked:(HyprMXBannerView *)bannerView;
-(void)adWillLeaveApplication:(HyprMXBannerView *)bannerView;
@end

NS_ASSUME_NONNULL_END
