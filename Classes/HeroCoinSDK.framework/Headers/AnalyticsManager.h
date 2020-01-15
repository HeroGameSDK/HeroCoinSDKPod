//
//  AnalyticsManager.h
//  HeroCoinSDK
//
//  Created by time on 2019/10/9.
//  Copyright © 2019 zhutaofeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AnalyticsManager : NSObject

/// 自定义事件
/// @param eventName 事件名称
/// @param values 自定义的事件参数字典
+ (void)logCustomEvent:(NSString *)eventName withValues:(NSDictionary *)values;

///应用内事件 In App Event
///
///用户Login事件
/// @param loginMethod 登录方式
+ (void)logAchieveLoginEvent:(NSString *)loginMethod;

/// 用户完成注册事件
/// @param registrationMethod 注册方式。注册时，用户提交的注册信息，例如，电子邮件、Facebook。
+ (void)logCompleteRegistrationEvent:(NSString *)registrationMethod;



/// 用户在应用程序中达到某个级别事件。Facebook仅能使用其中一个参数，level优先
/// @param level 级别
+ (void)logAchieveLevelEvent:(NSString *)level;

/// 用户完成应用程序中的教程事件
/// @param contentData 教程名称
/// @param contentId 教程ID
/// @param success successful or not
+ (void)logCompleteTutorialEvent:(NSString *)contentData
                       contentId:(NSString *)contentId
                         success:(BOOL)success;

/// 用户开始教程事件
+ (void)logBeginTutorialEvent;

/// 用户解锁应用程序中的成就事件
/// @param description 完成您想要在应用程序、业务或组织中奖励的特定活动或行动。例如，介绍一个朋友，完成你的资料，等等。
+ (void)logUnlockAchievementEvent:(NSString *)description;

/// 用户查看特定的产品详细信息页面时, 应触发此事件
/// 访问您关心的内容页面，如产品页面、登录页面或文章。
/// @param contentType 用于为记录的事件指定一个通用的内容类型。如“音乐”、“照片”、“视频”。使用的选项会根据应用程序的不同而有所不同。

#warning @param contentName  Applies only to Firebase
/// @param contentName 用于为记录的特定内容名称。

#warning @param contentData  Applies only to Facebook
/// @param contentData 用于为记录的一个或多个内容指定数据。Data should be a JSON encoded string. Example: "[{\"id\": \"1234\", \"quantity\": 2, \"item_price\": 5.99}, {\"id\": \"5678\", \"quantity\": 1, \"item_price\": 9.99}]"

/// @param contentId 用于为记录的特定内容指定ID。根据应用程序的性质，可以是EAN、文章标识符等。
/// @param currency 用于指定与记录的事件一起使用的货币单位。如"USD", "EUR", "GBP". 详情可见：<http://en.wikipedia.org/wiki/ISO_4217>
/// @param price 价格
+ (void)logViewContentEvent:(NSString *)contentType
                  contentId:(NSString *)contentId
                contentName:(NSString *)contentName
                contentData:(NSString * _Nullable)contentData
                   currency:(NSString *)currency
                 valueToSum:(double)price;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~以下是各个平台对应的事件~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//=================================================================== Facebook 事件方法

/// 自定义无参数事件
/// @param eventName 事件名字
+ (void)Facebook_logCustomEvent:(NSString *)eventName;


/// 自定义事件
/// @param eventName 事件名称
/// @param values 自定义的事件参数字典
+ (void)Facebook_logCustomEvent:(NSString *)eventName withValues:(NSDictionary *)values;


/// 用户完成注册事件
/// @param registrationMethod 注册方式。注册时，用户提交的注册信息，例如，电子邮件、Facebook。
+ (void)Facebook_logCompleteRegistrationEvent:(NSString *)registrationMethod;


/// 用户在应用程序中达到某个级别事件。Facebook仅能使用其中一个参数，level优先
/// @param level 级别
/// @param score 得分
+ (void)Facebook_logAchieveLevelEvent:(NSString *)level score:(NSString * _Nullable)score;


/// 用户完成应用程序中的教程事件
/// @param contentData 教程名称
/// @param contentId 教程ID
/// @param success successful or not
+ (void)Facebook_logCompleteTutorialEvent:(NSString *)contentData
                       contentId:(NSString *)contentId
                         success:(BOOL)success;


/// 用户解锁应用程序中的成就事件
/// @param description 完成您想要在应用程序、业务或组织中奖励的特定活动或行动。例如，介绍一个朋友，完成你的资料，等等。
+ (void)Facebook_logUnlockAchievementEvent:(NSString *)description;


/// 用户查看特定的产品详细信息页面时, 应触发此事件
/// 访问您关心的内容页面，如产品页面、登录页面或文章。
/// @param contentType 用于为记录的事件指定一个通用的内容类型。如“音乐”、“照片”、“视频”。使用的选项会根据应用程序的不同而有所不同。
/// @param contentData 用于为记录的一个或多个内容指定数据。Data should be a JSON encoded string. Example: "[{\"id\": \"1234\", \"quantity\": 2, \"item_price\": 5.99}, {\"id\": \"5678\", \"quantity\": 1, \"item_price\": 9.99}]"
/// @param contentId 用于为记录的特定内容指定ID。根据应用程序的性质，可以是EAN、文章标识符等。
/// @param currency 用于指定与记录的事件一起使用的货币单位。如"USD", "EUR", "GBP". 详情可见：<http://en.wikipedia.org/wiki/ISO_4217>
/// @param price 价格
+ (void)Facebook_logViewContentEvent:(NSString *)contentType
                  contentId:(NSString *)contentId
                contentData:(NSString * _Nullable)contentData
                   currency:(NSString *)currency
                 valueToSum:(double)price;


/// Facebook，内购统计
/// @param purchaseAmount 单价
/// @param numItems 数量
/// @param contentType 商品类型
/// @param contentData 内容
/// @param contentId 物品ID
/// @param currency 货币
+ (void)Facebook_logPurchaseEvent:(double)purchaseAmount
                numItems:(int)numItems
             contentType:(NSString *)contentType
             contentData:(NSString *)contentData
               contentId:(NSString *)contentId
                currency:(NSString *)currency;

//=================================================================== FireBase 事件方法

/// 自定义无参数事件
/// @param eventName 事件名字
+ (void)Firebase_logCustomEvent:(NSString *)eventName;


/// 自定义事件
/// @param eventName 事件名称
/// @param values 自定义的事件参数字典
+ (void)Firebase_logCustomEvent:(NSString *)eventName withValues:(NSDictionary *)values;


///应用内事件 In App Event
///
///用户Login事件
/// @param loginMethod 登录方式
+ (void)Firebase_logAchieveLoginEvent:(NSString *)loginMethod;


/// 用户完成注册事件
/// @param registrationMethod 注册方式。注册时，用户提交的注册信息，例如，电子邮件、Facebook。
+ (void)FireBase_logCompleteRegistrationEvent:(NSString *)registrationMethod;


/// 用户在应用程序中达到某个级别事件
/// @param level 级别
+ (void)FireBase_logAchieveLevelEvent:(NSString *)level;


/// 用户开始教程事件
+ (void)FireBase_logBeginTutorialEvent;


/// 用户完成教程事件
+ (void)FireBase_logCompleteTutorialEvent;


/// 用户解锁应用程序中的成就事件
/// @param description 完成您想要在应用程序、业务或组织中奖励的特定活动或行动。例如，介绍一个朋友，完成你的资料，等等。
+ (void)FireBase_logUnlockAchievementEvent:(NSString *)description;


/// 用户查看特定的产品详细信息页面时, 应触发此事件
/// 访问您关心的内容页面，如产品页面、登录页面或文章。
/// @param contentType 用于为记录的事件指定一个通用的内容类型。如“音乐”、“照片”、“视频”。使用的选项会根据应用程序的不同而有所不同。
/// @param contentName 用于为记录的特定内容名称。
/// @param contentId 用于为记录的特定内容指定ID。根据应用程序的性质，可以是EAN、文章标识符等。
/// @param currency 用于指定与记录的事件一起使用的货币单位。如"USD", "EUR", "GBP". 详情可见：<http://en.wikipedia.org/wiki/ISO_4217>
/// @param price 价格
+ (void)FireBase_logViewContentEvent:(NSString *)contentType
                  contentId:(NSString *)contentId
                contentName:(NSString *)contentName
                   currency:(NSString *)currency
                 valueToSum:(double)price;



//=================================================================== AppsFlyer 事件方法

/// 自定义无参数事件
/// @param eventName 事件名字
+ (void)AppsFlyer_logCustomEvent:(NSString *)eventName;


/// 自定义事件
/// @param eventName 事件名称
/// @param values 自定义的事件参数字典
+ (void)AppsFlyer_logCustomEvent:(NSString *)eventName withValues:(NSDictionary *)values;


///应用内事件 In App Event
///
///用户Login事件
+ (void)AppsFlyer_logAchieveLoginEvent;


/// 用户完成注册事件
/// @param registrationMethod 注册方式。注册时，用户提交的注册信息，例如，电子邮件、Facebook。
+ (void)AppsFlyer_logCompleteRegistrationEvent:(NSString *)registrationMethod;


/// 用户在应用程序中达到某个级别事件。Facebook仅能使用其中一个参数，level优先
/// @param level 级别
/// @param score 得分
+ (void)AppsFlyer_logAchieveLevelEvent:(NSString *)level score:(NSString * _Nullable)score;


/// 用户完成应用程序中的教程事件
/// @param contentData 教程名称
/// @param contentId 教程ID
/// @param success successful or not
+ (void)AppsFlyer_logCompleteTutorialEvent:(NSString *)contentData
                       contentId:(NSString *)contentId
                         success:(BOOL)success;


/// 用户解锁应用程序中的成就事件
/// @param description 完成您想要在应用程序、业务或组织中奖励的特定活动或行动。例如，介绍一个朋友，完成你的资料，等等。
+ (void)AppsFlyer_logUnlockAchievementEvent:(NSString *)description;


/// 用户查看特定的产品详细信息页面时, 应触发此事件
/// 访问您关心的内容页面，如产品页面、登录页面或文章。
/// @param contentType 用于为记录的事件指定一个通用的内容类型。如“音乐”、“照片”、“视频”。使用的选项会根据应用程序的不同而有所不同。
/// @param contentId 用于为记录的特定内容指定ID。根据应用程序的性质，可以是EAN、文章标识符等。
/// /// @param contentData 用于为记录的一个或多个内容指定数据。Data should be a JSON encoded string. Example: "[{\"id\": \"1234\", \"quantity\": 2, \"item_price\": 5.99}, {\"id\": \"5678\", \"quantity\": 1, \"item_price\": 9.99}]"
/// @param currency 用于指定与记录的事件一起使用的货币单位。如"USD", "EUR", "GBP". 详情可见：<http://en.wikipedia.org/wiki/ISO_4217>
/// @param price 价格
+ (void)AppsFlyer_logViewContentEvent:(NSString *)contentType
                            contentId:(NSString *)contentId
                          contentData:(NSString *)contentData
                             currency:(NSString *)currency
                           valueToSum:(double)price;


/// AppsFlyer 购买事件
/// @param purchaseAmount 购买金额
/// @param currency 货币单位
/// @param productId 产品id, 如果没有可以传nil
+ (void)AppsFlyer_logPurchaseEvent:(double)purchaseAmount
                          currency:(NSString *)currency
                         productId:(NSString *)productId;

@end

NS_ASSUME_NONNULL_END
