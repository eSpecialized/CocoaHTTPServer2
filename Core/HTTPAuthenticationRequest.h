#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
  // Note: You may need to add the CFNetwork Framework to your project
  #import <CFNetwork/CFNetwork.h>
#endif

@class HTTPMessage;


@interface HTTPAuthenticationRequest : NSObject
{
	BOOL isBasic;
	BOOL isDigest;
	
	NSString *base64Credentials;
	
	NSString *username;
	NSString *realm;
	NSString *nonce;
	NSString *uri;
	NSString *qop;
	NSString *nc;
	NSString *cnonce;
	NSString *response;
}
- (instancetype)initWithRequest:(HTTPMessage *)request NS_DESIGNATED_INITIALIZER;

@property (NS_NONATOMIC_IOSONLY, getter=isBasic, readonly) BOOL basic;
@property (NS_NONATOMIC_IOSONLY, getter=isDigest, readonly) BOOL digest;

// Basic
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *base64Credentials;

// Digest
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *username;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *realm;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *nonce;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *uri;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *qop;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *nc;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *cnonce;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *response;

@end
