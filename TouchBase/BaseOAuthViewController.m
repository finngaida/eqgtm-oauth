#import "BaseOAuthViewController.h"

NSString * const OAVCMessageLoading = @"Loading...";
NSString * const OAVCMessageFetchAccess = @"Fetch access token...";
NSString * const OAVCMessageFetchRequest = @"Fetch request token...";

@interface BaseOAuthViewController ()

@end

@implementation BaseOAuthViewController
@synthesize activityDelegate = _activityDelegate;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        _notificationCenter = [NSNotificationCenter defaultCenter];
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
