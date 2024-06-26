//
//  HYPRAlertView.h
//  HyprMX-Framework
//
//  Created by Jeremy Ellison on 10/10/14.
//  Copyright (c) 2014 HyprMX Mobile LLC. All rights reserved.
//
//  Borrowed from TTAlertView: https://github.com/twotoasters/TTAlertView

#import <UIKit/UIKit.h>
#import "HYPREnvironment.h"
typedef void (^HYPRAlertViewActionHandler)(NSInteger index);

@protocol HYPRAlertViewDelegate;
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRAlertView : UIView {}

#pragma mark - HYPRAlertView properties

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, weak) id<HYPRAlertViewDelegate> delegate;
@property (nonatomic, readonly, getter = isVisible) BOOL visible;
@property (nonatomic, readonly) NSInteger cancelButtonIndex;
@property (nonatomic, readonly) NSInteger firstOtherButtonIndex;
@property (nonatomic, readonly) NSUInteger numberOfButtons;

#pragma mark - HYPRAlertView properties

@property (nonatomic, copy) HYPRAlertViewActionHandler buttonActionHandler;

@property (nonatomic, readonly) UIImageView *backgroundView; // by default, the darkened background displayed behind the alert
@property (nonatomic, readonly) UIImageView *containerView; // the background of the alert view
@property (nonatomic, readonly) UILabel *titleLabel;
@property (nonatomic, readonly) UILabel *messageLabel;

@property (nonatomic, strong) UIImage *backgroundImage UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *containerImage UI_APPEARANCE_SELECTOR;

/**
 * Insets for the content area and the button area sized inside of the container view
 */
@property (nonatomic, assign) UIEdgeInsets contentInsets UI_APPEARANCE_SELECTOR; // insets for the content area (title and message portion of the alert view)
@property (nonatomic, assign) UIEdgeInsets buttonInsets UI_APPEARANCE_SELECTOR; // insets for the button area (all of the buttons layed out by the alert view)

/**
 * Insets for the container (view that contains the content view and the buttons). The minimum vertical inset describes the minimum ammount of space from top and bottom of the superview
 * that the container view can be sized in - this means at the container view's maximum size, it will be spaced the minimum vertical inset from the top and bottom of its superview.
 */
@property (nonatomic, assign) CGFloat containerLeftInset UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat containerRightInset UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat containerMinVerticalInset UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat containerVerticalOffset;

@property (nonatomic, assign) CGFloat contentTitleMessageSpacer UI_APPEARANCE_SELECTOR; // space between the title label and the message label in the default layout
@property (nonatomic, assign) CGFloat buttonVerticalSpacerFirst UI_APPEARANCE_SELECTOR; // the vertical distance between the first and second button in the #buttons > 2 vertical layout
@property (nonatomic, assign) CGFloat buttonVerticalSpacer UI_APPEARANCE_SELECTOR; // the vertical distance between the buttons in the #buttons > 2 vertical layout
@property (nonatomic, assign) CGFloat buttonHorizontalSpacer UI_APPEARANCE_SELECTOR; // the horizontal space between buttons

#pragma mark - HYPRAlertView methods

- (id)initWithTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ...;

- (void)show;
- (void)showInView:(UIView *)view;
- (void)dismissWithClickedButtonIndex:(NSInteger)index animated:(BOOL)animated;
- (void)addButtonWithTitle:(NSString *)title;
- (NSString *)buttonTitleAtIndex:(NSUInteger)index;

#pragma mark - HYPRAlertView methods

/**
 * Set the background image for the button at a given index.
 * This is intended to be used with the button title text and a resizable image.
 */
- (void)setButtonBackgroundImage:(UIImage *)image forState:(UIControlState)state atIndex:(NSUInteger)index UI_APPEARANCE_SELECTOR;

/**
 * Set the background image for the button at a given index, for a specific size.
 * This is intended to be used with resizable images, and allows the button to
 * have a custom size.
 */
- (void)setButtonBackgroundImage:(UIImage *)image forState:(UIControlState)state withSize:(CGSize)size atIndex:(NSUInteger)index UI_APPEARANCE_SELECTOR;

/**
 * Set the button image for the button at a given index, with a given size.
 * This is intended to be used for button images which have the text baked in,
 * or for buttons with non-repeatable textures. It can also be used to force
 * particular buttons to layout with a different size. It is the responsibility
 * of the developer to not specify button sizes larger than the alert view
 * can display
 */
- (void)setButtonImage:(UIImage *)image forState:(UIControlState)state withSize:(CGSize)size atIndex:(NSUInteger)index UI_APPEARANCE_SELECTOR;

/**
 * Retrieve the button at the given index to allow for further customization. Changes to the button's frame may result in unexpected layout behavior.
 */
- (UIButton *)buttonAtIndex:(NSUInteger)index;

@end

#pragma mark - HYPRAlertViewDelegate

/**
 * HYPRAlertViewDelegate
 * Mainly mimicks UIAlertViewDelegate methods
 */
HYPR_CLASS_AVAILABLE_IOS
@protocol HYPRAlertViewDelegate <NSObject>

// Called when a button is clicked. The view will be automatically dismissed after this call returns
- (void)alertView:(HYPRAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

- (void)willPresentAlertView:(HYPRAlertView *)alertView;  // before animation and showing view
- (void)didPresentAlertView:(HYPRAlertView *)alertView;  // after animation

- (void)alertViewCancel:(HYPRAlertView *)alertView;
- (void)alertView:(HYPRAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex; // before animation and hiding view
- (void)alertView:(HYPRAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex;  // after animation

- (BOOL)alertViewShouldEnableFirstOtherButton:(HYPRAlertView *)alertView;

@end
