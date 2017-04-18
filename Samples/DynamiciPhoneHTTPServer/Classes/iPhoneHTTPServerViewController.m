#import "iPhoneHTTPServerViewController.h"

#import "iPhoneHTTPServerAppDelegate.h"

@implementation iPhoneHTTPServerViewController


-(void)viewDidLoad
{
    [super viewDidLoad];
    
    iPhoneHTTPServerAppDelegate *dg = (iPhoneHTTPServerAppDelegate*)[UIApplication sharedApplication].delegate;
    dg.viewController = self;
    
    self.theServer = dg.httpServer;
    
    self.textView.text = @"\n\nTo use all samples;\n\n1) Enable Bonjour in Safari Favorites.\n\n2) Use 'View' to show Favorites\n\n3)  Use the bonjour in the  Favorites bar";
}


-(void)setTheServer:(HTTPServer *)theServer
{
    _theServer = theServer;
    _theServer.delegate = self;
}


-(void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    NSLog(@"All up and online / running");
}

-(void)httpserver:(HTTPServer *)theSrvr clientConnected:(NSString *)theClient
{
    NSUInteger clientsQtty = [theSrvr numberOfHTTPConnections];
    
    NSString *currentText = self.textView.text;
    
    currentText = [currentText stringByAppendingFormat:@"\nConnections : %lu",(unsigned long)clientsQtty];
    
    self.textView.text = currentText;
}

-(void)httpserver:(HTTPServer *)theSrvr serverDidPublish:(NSNetService *)ns
{
    
    NSInteger portNumber = (long)[theSrvr listeningPort];
    
    NSString *publishedName = [theSrvr publishedName];
    
    publishedName = [publishedName stringByReplacingOccurrencesOfString:@" " withString:@"-"];
    publishedName = [publishedName stringByReplacingOccurrencesOfString:@"+" withString:@""];

    NSString *serverConnectString = [NSString stringWithFormat:@"http://%@.%@:%ld", publishedName,[ns domain],(long)portNumber];
    
    self.statusLbl.text = serverConnectString;
}

-(void)httpserver:(HTTPServer *)theSrvr serverDidNotPublish:(NSDictionary *)errors
{
    self.textView.text = @"Unable to publish webserverlet";
    self.statusLbl.text = @"Unable to publish webserverlet";
}

@end
