//
//  TimeSDKShareConfig.h
//  HeroCoinSDK
//
//  Created by time on 2019/9/29.
//  Copyright © 2019 zhutaofeng. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 分享平台
typedef NS_ENUM(NSInteger, TimeSocialPlatformType) {
    TimeSocialPlatformType_Facebook = 16,
    TimeSocialPlatformType_Twitter = 17,
    TimeSocialPlatformType_Line = 21,
    TimeSocialPlatformType_FaceBookMessenger = 34,
};

/// 分享类型
typedef NS_ENUM(NSUInteger, TimeSocialShareType) {
    ///纯文本                            //可支持分享的平台
    TimeSocialShareType_Text,           //Twitter,
    ///本地图片
    TimeSocialShareType_Image,          //Facebook, Messenger, Twitter
    ///Https网络图片
    TimeSocialShareType_Image_Url,      //Facebook, Messenger, Twitter
    ///文本+图片
    TimeSocialShareType_TextAndImage,   //Twitter
    ///网页链接
    TimeSocialShareType_Web_Link,       //Facebook, Messenger, Twitter
    ///网络视频url
    TimeSocialShareType_Video_Link,     //Twitter
    ///本地视频
    TimeSocialShareType_Video,          //Facebook
};
 
typedef void (^TimeSDKShareRequestCompletionHandler)(TimeSocialPlatformType platformType, NSString * _Nullable result, NSError * _Nullable error);
NS_ASSUME_NONNULL_BEGIN
 
@interface TimeSDKShareObject : NSObject

/**
 * 标题
 * @note 标题的长度依各个平台的要求而定
 */
@property (nonatomic, copy) NSString *title;

/**
 * 描述
 * @note 描述内容的长度依各个平台的要求而定
 */
@property (nonatomic, copy) NSString *descr;

/**
 * 缩略图 UIImage或者NSData类型或者NSString类型（图片url）
 */
@property (nonatomic, strong) id thumbImage;

///****************分享文本内容****************
@property (nonatomic, strong) NSString *text;

///****************分享单张图片****************
/** 分享单个图片（支持UIImage，NSdata以及图片链接Url NSString类对象集合）
 * @note 图片大小根据各个平台限制而定
 */
@property (nonatomic, retain) id shareImage;

///****************分享网络链接****************
/// 链接标题
//@property (nonatomic, copy) NSString *webpageTitle;
/// 链接地址
@property (nonatomic, copy) NSString *webpageUrl;

/**
 视频网页的url
 
 @warning 不能为空且长度不能超过255
 */
@property (nonatomic, strong) NSString *videoUrl;

/// 视频数据
@property (nonatomic, strong) NSData *videoData;

@end
NS_ASSUME_NONNULL_END
