#import <UIKit/UIKit.h>
#import "HTTPServer.h"

@interface iPhoneHTTPServerViewController : UIViewController <HTTPServerDelegate> {

}

@property (weak, nonatomic) HTTPServer *theServer;
@property (weak, nonatomic) IBOutlet UITextView *textView;
@property (weak, nonatomic) IBOutlet UILabel *statusLbl;

@end

