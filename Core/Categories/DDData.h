#import <Foundation/Foundation.h>

@interface NSData (DDData)

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSData *md5Digest;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSData *sha1Digest;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *hexStringValue;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *base64Encoded;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSData *base64Decoded;

@end
