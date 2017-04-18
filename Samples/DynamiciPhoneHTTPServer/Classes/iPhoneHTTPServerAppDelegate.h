#import <UIKit/UIKit.h>

@class iPhoneHTTPServerViewController;
@class HTTPServer;

@interface iPhoneHTTPServerAppDelegate : NSObject <UIApplicationDelegate>

@property (nonatomic,strong) HTTPServer *httpServer;
@property (nonatomic,strong) UIWindow *window;
@property (nonatomic,strong) iPhoneHTTPServerViewController *viewController;

@end

