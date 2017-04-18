/**
 * The HTTPMessage class is a simple Objective-C wrapper around Apple's CFHTTPMessage class.
**/

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
  // Note: You may need to add the CFNetwork Framework to your project
  #import <CFNetwork/CFNetwork.h>
#endif

#define HTTPVersion1_0  ((NSString *)kCFHTTPVersion1_0)
#define HTTPVersion1_1  ((NSString *)kCFHTTPVersion1_1)


@interface HTTPMessage : NSObject
{
	CFHTTPMessageRef message;
}

@property(nonatomic, assign, readonly) CFHTTPMessageRef message;

- (instancetype)initEmptyRequest ;

- (instancetype)initRequestWithMethod:(NSString *)method URL:(NSURL *)url version:(NSString *)version ;

- (instancetype)initResponseWithStatusCode:(NSInteger)code description:(NSString *)description version:(NSString *)version ;

- (BOOL)appendData:(NSData *)data;

@property (NS_NONATOMIC_IOSONLY, getter=isHeaderComplete, readonly) BOOL headerComplete;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *version;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *method;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSURL *url;

@property (NS_NONATOMIC_IOSONLY, readonly) NSInteger statusCode;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSDictionary *allHeaderFields;
- (NSString *)headerField:(NSString *)headerField;

- (void)setHeaderField:(NSString *)headerField value:(NSString *)headerFieldValue;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSData *messageData;

@property (NS_NONATOMIC_IOSONLY, copy) NSData *body;

@end
