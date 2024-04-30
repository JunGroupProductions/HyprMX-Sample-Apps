//  HYPREnvironment.h
//  HyprMX

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "HYPRLogger.h"
#import "HYPRConstants.h"
#import "HYPRQueueManager.h"
#import <HyprMX/HyprMX.h>


#pragma mark -
#pragma mark Constants
#pragma mark -

/* Embedded Images as Base64 */
extern NSString * const kHYPRWebViewBackButton;
extern NSString * const kHYPRLogoData;
extern NSString * const kHYPRWhiteCloseButton;

/* Macros */
#define HYPR_SCREEN_SCALE_SOURCE [[UIScreen mainScreen] scale]
#define HYPR_SCREEN_SCALE [NSNumber numberWithFloat:HYPR_SCREEN_SCALE_SOURCE]

#pragma mark -
#pragma mark iOS Version and Debugger State Functions
#pragma mark -

/**
 *
 *  @return true if debugger is attached
 */
extern BOOL HYPRIsInDebugger(void);

/**
 * returns true if either HYPRAPIHelper.sharedHelper.isInDebugger or HYPRIsInFunctionalTests() is true
 */
extern BOOL HYPRIsDebugOrTest(void);


#pragma mark -
#pragma mark HYPRAPIHelper Class
#pragma mark -

@interface HYPRAPIHelper : NSObject

/* 
 * Returns a singleton of the wrapper class for HYPRAPI Calls
 * This wrapper allows for mocking the contained method for testing. 
 * It's not possible to mock a C-style function.
 */
+ (instancetype)sharedHelper;

/* 
 * Wrapper for HYPRIsInDebugger() - returns the debugger state
 * This wrapped method is mockable by OCMock.
 * 
 * @return YES if in debugger session, NO otherwise
 */
- (BOOL)isInDebugger;

@end


