#import <UIKit/UIKit.h>


extern NSString * const OAVCMessageLoading;
extern NSString * const OAVCMessageFetchAccess;
extern NSString * const OAVCMessageFetchRequest;


@class BaseOAuthViewController;

@protocol OAuthVCActivityDelegate <NSObject>
-(void)oAuthViewController:(BaseOAuthViewController *)viewController becomeActiveWithMessage:(NSString *)message;
-(void)oAuthViewControllerDoneActivity:(BaseOAuthViewController *)viewController;
-(void)oAuthViewControllerDismissed:(BaseOAuthViewController *)viewController;
-(void)oAuthViewControllerDidCancel:(BaseOAuthViewController *)viewController;
@end

@interface BaseOAuthViewController : UIViewController{
    @protected NSNotificationCenter *_notificationCenter;
    @protected __weak id <OAuthVCActivityDelegate> _activityDelegate;
}

@property(weak,nonatomic) id <OAuthVCActivityDelegate> activityDelegate;

@end
