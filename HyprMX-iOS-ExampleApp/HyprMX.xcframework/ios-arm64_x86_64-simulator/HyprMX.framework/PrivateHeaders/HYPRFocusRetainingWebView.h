//
//  HYPRFocusRetainingWebView.h
//  HyprMX
//
//  Created by Tim Kerchmar on 10/6/23.
//  Copyright © 2023 HyprMX Mobile LLC. All rights reserved.
//

#ifndef HYPRFocusRetainingWebView_h
#define HYPRFocusRetainingWebView_h

#import <WebKit/WebKit.h>
#import <HyprMX/HYPRAvailability.h>

HYPR_CLASS_AVAILABLE_IOS
@interface HYPRFocusRetainingWebView : WKWebView

- (BOOL)canResignFirstResponder;

@end

#endif /* HYPRFocusRetainingWebView_h */
