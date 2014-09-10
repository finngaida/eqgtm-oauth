//
// GTMOAuthViewControllerTouch.h
//
// This view controller for iPhone handles sign-in via OAuth.
//
// This controller is not reusable; create a new instance of this controller
// every time the user will sign in.
//
// Sample usage:
//
//  static NSString *const kAppServiceName = @”My Application: My API”;
//  NSString *scope = @"read/write";
//
//  GTMOAuthViewControllerTouch *viewController =
//    [[[GTMOAuthViewControllerTouch alloc] initWithScope:scope
//                                               language:nil
//                                        requestTokenURL:requestURL
//                                      authorizeTokenURL:authorizeURL
//                                         accessTokenURL:accessURL
//                                         authentication:auth
//                                         appServiceName:kAppServiceName
//                                               delegate:self
//                                       finishedSelector:@selector(viewController:finishedWithAuth:error:)] autorelease];
//  [[self navigationController] pushViewController:viewController
//                                         animated:YES];
//
// The finished selector should have a signature matching this:
//
//  - (void)windowController:(GTMOAuthWindowController *)windowController
//          finishedWithAuth:(GTMOAuthAuthentication *)auth
//                     error:(NSError *)error {
//    if (error != nil) {
//     // sign in failed
//    } else {
//     // sign in succeeded
//     //
//     // With a GTMHTTPFetcher, use the auth object as an authorizer,
//     // like
//     //   [fetcher setAuthorizer:auth];
//     //
//     // or use it to sign a request directly, like
//     //    [auth authorizeRequest:myNSURLMutableRequest]
//    }
//  }
//
// If the network connection is lost for more than 10 seconds while the sign-in
// html is displayed, the view will be dismissed and the callback method
// will be invoked with an error.

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE

#import "BaseOAuthViewController.h"

#import "GTMOAuthAuthentication.h"

#undef _EXTERN
#undef _INITIALIZE_AS
#ifdef GTMOAUTHVIEWCONTROLLERTOUCH_DEFINE_GLOBALS
#define _EXTERN
#define _INITIALIZE_AS(x) =x
#else
#define _EXTERN extern
#define _INITIALIZE_AS(x)
#endif

_EXTERN NSString* const kGTLOAuthKeychainErrorDomain _INITIALIZE_AS(@"com.google.GTMOAuthKeychain");


@class GTMOAuthSignIn;
@class GTMOAuthViewControllerTouch;

@interface GTMOAuthViewControllerTouch : BaseOAuthViewController <UINavigationControllerDelegate, UIWebViewDelegate> {
 @private
  UIButton *backButton_;
  UIButton *forwardButton_;
  UIView *navButtonsView_;
  UIBarButtonItem *rightBarButtonItem_;
  UIWebView *webView_;
  // The object responsible for the sign-in networking sequence; it holds
  // onto the authentication object as well.
  GTMOAuthSignIn *signIn_;

  // the page request to load when awakeFromNib occurs
  NSURLRequest *request_;

  // The user we're calling back
  //
  // The delegate is retained only until the callback is invoked
  // or the sign-in is canceled
  id delegate_;
  SEL finishedSelector_;

#if NS_BLOCKS_AVAILABLE
  void (^completionBlock_)(GTMOAuthViewControllerTouch *, GTMOAuthAuthentication *, NSError *);
#endif

  NSString *keychainApplicationServiceName_;

  // if non-nil, the html string to be displayed immediately upon opening
  // of the web view
  NSString *initialHTMLString_;

  // if non-nil, the URL for which cookies will be deleted when the
  // browser view is dismissed
  NSURL *browserCookiesURL_;

  id userData_;

  // We delegate the decision to our owning NavigationController (if any).
  // But, the NavigationController will call us back, and ask us.
  // BOOL keeps us from infinite looping.
  BOOL isInsideShouldAutorotateToInterfaceOrientation_;

  // YES, when view first shown in this signIn session.
  BOOL isViewShown_;

  // To prevent us from calling our delegate's selector more than once.
  BOOL hasCalledFinished_;

  // Set in a webView callback.
  BOOL hasDoneFinalRedirect_;

  // Set during the pop initiated by the sign-in object; otherwise,
  // viewWillDisappear indicates that some external change of the view
  // has stopped the sign-in.
  BOOL didDismissSelf_;
}

// the application and service name to use for saving the auth tokens
// to the keychain
@property (nonatomic, copy) NSString *keychainApplicationServiceName;

// the application name to be displayed during sign-in
@property (nonatomic, copy) NSString *displayName;

// optional html string displayed immediately upon opening the web view
//
// This string is visible just until the sign-in web page loads, and
// may be used for a "Loading..." type of message or to set the
// initial view color
@property (nonatomic, copy) NSString *initialHTMLString;

// the underlying object to hold authentication tokens and authorize http
// requests
@property (nonatomic, retain, readonly) GTMOAuthAuthentication *authentication;

// the underlying object which performs the sign-in networking sequence
@property (nonatomic, retain, readonly) GTMOAuthSignIn *signIn;

// user interface elements
@property (nonatomic, retain) IBOutlet UIButton *backButton;
@property (nonatomic, retain) IBOutlet UIButton *forwardButton;
@property (nonatomic, retain) IBOutlet UIView *navButtonsView;
@property (strong, nonatomic) IBOutlet UINavigationItem *navigationBarItem;
@property (strong, nonatomic) IBOutlet UIButton *cancelButton;//Added by DAEMMON
@property (strong, nonatomic) IBOutlet UINavigationBar *navigationBar;//Added by DAEMMON
@property (strong, nonatomic) IBOutlet UIBarButtonItem *leftBarButtonItem;//Added by DAEMMON
@property (nonatomic, retain) IBOutlet UIBarButtonItem *rightBarButtonItem;
@property (nonatomic, retain) IBOutlet UIWebView *webView;


// the default timeout for an unreachable network during display of the
// sign-in page is 10 seconds; set this to 0 to have no timeout
@property (nonatomic, assign) NSTimeInterval networkLossTimeoutInterval;

// If set, cookies are deleted for this URL when the view is hidden
@property (nonatomic, retain) NSURL *browserCookiesURL;

@property (nonatomic, retain) id userData;

// init method for authenticating, taking endpoint URLs and an authentication
// object
//
// this is the designated initializer
- (id)initWithScope:(NSString *)scope
           language:(NSString *)language
    requestTokenURL:(NSURL *)requestURL
  authorizeTokenURL:(NSURL *)authorizeURL
     accessTokenURL:(NSURL *)accessURL
     authentication:(GTMOAuthAuthentication *)auth
     appServiceName:(NSString *)keychainAppServiceName
           delegate:(id)delegate
   finishedSelector:(SEL)finishedSelector;

#if NS_BLOCKS_AVAILABLE
- (id)initWithScope:(NSString *)scope
           language:(NSString *)language
    requestTokenURL:(NSURL *)requestURL
  authorizeTokenURL:(NSURL *)authorizeURL
     accessTokenURL:(NSURL *)accessURL
     authentication:(GTMOAuthAuthentication *)auth
     appServiceName:(NSString *)keychainAppServiceName
  completionHandler:(void (^)(GTMOAuthViewControllerTouch *viewController, GTMOAuthAuthentication *auth, NSError *error))handler;
#endif

// Override default in UIViewController. If we have a navigationController, ask
// it. else default result (i.e., Portrait mode only).
//============================DAEMMON COMMENT============================
//- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

// Subclasses may override authNibName to specify a custom name
+ (NSString *)authNibName;

// If the nib is not found, this ViewwController calls this method to construct
// the view.
//- (void)constructView;

- (void)cancelSigningIn;

//
// Keychain
//

// Add tokens from the keychain, if available, to an authentication
// object.  The authentication object must have previously been created.
//
// Returns YES if the authentication object was authorized from the keychain
+ (BOOL)authorizeFromKeychainForName:(NSString *)appServiceName
                      authentication:(GTMOAuthAuthentication *)auth;

// Delete the stored access token and secret, useful for "signing
// out"
+ (BOOL)removeParamsFromKeychainForName:(NSString *)appServiceName;

// Store the access token and secret, typically used immediately after
// signing in
+ (BOOL)saveParamsToKeychainForName:(NSString *)appServiceName
                     authentication:(GTMOAuthAuthentication *)auth;

@end

// To function, GTMOAuthViewControllerTouch needs a certain amount of access
// to the iPhone's keychain. To keep things simple, its keychain access is
// broken out into a helper class. We declare it here in case you'd like to use
// it too, to store passwords.

enum {
  kGTLOAuthKeychainErrorBadArguments = -1001,
  kGTLOAuthKeychainErrorNoPassword = -1002
};


@interface GTMOAuthKeychain : NSObject

+ (GTMOAuthKeychain *)defaultKeychain;

// OK to pass nil for the error parameter.
- (NSString *)passwordForService:(NSString *)service
                         account:(NSString *)account
                           error:(NSError **)error;

// OK to pass nil for the error parameter.
- (BOOL)removePasswordForService:(NSString *)service
                         account:(NSString *)account
                           error:(NSError **)error;

// OK to pass nil for the error parameter.
- (BOOL)setPassword:(NSString *)password
         forService:(NSString *)service
            account:(NSString *)account
              error:(NSError **)error;

// For unit tests: allow setting a mock object
+ (void)setDefaultKeychain:(GTMOAuthKeychain *)keychain;

@end

#endif // TARGET_OS_IPHONE
