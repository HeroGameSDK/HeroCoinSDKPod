//
//  TimeSDKShareManager.h
//  HeroCoinSDK
//
//  Created by time on 2019/9/29.
//  Copyright © 2019 zhutaofeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TimeSDKShareConfig.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface TimeSDKShareManager : NSObject

/// 分享
/// @param fromViewController 来自哪个controller
/// @param platformType 分享平台，如Twitter、Line
/// @param shareType 分享类型，如分享图片
/// @param shareObject 分享对象
/// @param completion 完成回调(注意：Line没有回调)
+ (void)shareWithFromViewController:(UIViewController *)fromViewController
                       platformType:(TimeSocialPlatformType)platformType
                          shareType:(TimeSocialShareType)shareType
                        shareObject:(TimeSDKShareObject *)shareObject
                         completion:(TimeSDKShareRequestCompletionHandler)completion;
@end

NS_ASSUME_NONNULL_END
