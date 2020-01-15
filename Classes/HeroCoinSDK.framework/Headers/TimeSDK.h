//
//  TimeSDK.h
//  HeroCoinSDK
//
//  Created by admin on 2018/5/9.
//  Copyright © 2018年 zhutaofeng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class UIApplication;
typedef NS_ENUM(NSUInteger, EnvironmentType) {
    EnvironmentTypeWithTest,            //测试环境
    EnvironmentTypeWithPre_production,  //预生产环境
    EnvironmentTypeWithProduction,      //生产环境
};


/// 登录类型
typedef NS_ENUM(NSUInteger, LoginType) {
    /// Facebook登录
    LoginTypeFacebook = 1,
    //LoginTypeGoogle = 2,
    /// 游客登录
    LoginTypeTourists = 3,
    /// GameCenter登录
    LoginTypeGameCenter = 4,
    /// Twitter 登录
    LoginTypeTwitter = 8,
    /// AppleID 登录，iOS 13后支持，iOS 13以下不会显示
    LoginTypeSignInWithApple = 9,
    /// Line 登录, iOS 10以上支持，iOS 10以下不会显示
    LoginTypeLine = 10,
    /// 密码登录
    LoginTypePassword = 11
    
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^LoginResult)(NSDictionary * _Nullable info, NSError * _Nullable error);
typedef void (^LogoutResult)(BOOL success);
 

@interface TimeSDK : NSObject


/// 单利初始化入口
+ (instancetype)sharedInstance;
 
/// AppsFlyer DevKey
@property (nonatomic, copy) NSString *appsFlyerDevKey;
/// Apple Id
@property (nonatomic, copy) NSString *appleAppID;

///  Twitter Consumer Key
@property (nonatomic, copy) NSString *twitterConsumerKey;
///  Twitter Consumer Secret
@property (nonatomic, copy) NSString *twitterConsumerSecret;

/// 游戏注册后获得的 渠道标识符
@property (nonatomic, copy) NSString *productId;
/// 游戏注册后获得的 包体标识符
@property (nonatomic, copy) NSString *projectId;

///  SDK环境，对接不同服务器，默认为测试环境
@property (nonatomic, assign) EnvironmentType environmentType;

/// 需要的登录类型
@property (nonatomic, copy) NSArray <NSNumber *>*loginTypes;

/// 自动游客登录，默认false，如果是true，调用登录接口时，不再弹出选择登录方式的界面，直接使用游客的方式进行登录
@property (nonatomic, assign) BOOL automaticTouristsLogin;
/// 是否屏蔽访问特殊地区的URL,默认false（不屏蔽）
@property (nonatomic, assign) BOOL shieldSpecialAreaURL;
/// 屏蔽Time悬浮小图标, 默认false(不屏蔽), 如果设置成true, showTimeIcon 方法将不再生效
@property (nonatomic, assign) BOOL shieldTimeIcon;

/// 来自哪个UIViewController
@property (nonatomic, strong) UIViewController *fromViewController;


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler;

- (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<NSString *, id> *)options;

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

- (void)applicationDidBecomeActive:(UIApplication *)application;

- (BOOL)application:(UIApplication *)application continueUserActivity:(nonnull NSUserActivity *)userActivity restorationHandler:
#if defined(__IPHONE_12_0) && (__IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_12_0)
(nonnull void (^)(NSArray<id<UIUserActivityRestoring>> *_Nullable))restorationHandler;
#else
(nonnull void (^)(NSArray *_Nullable))restorationHandler;
#endif  // __IPHONE_12_0
+ (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window portrait:(NSUInteger)portrait;

/// 显示Time图标（time UI入口）
- (void)showTimeIcon;
/// 影藏Time图标（time UI入口）
- (void)hiddenTimeIcon;

/// 退出账号结果回调 (当程序中有退出登录/切换账号操作时回调)
@property (nonatomic,   copy) LogoutResult logoutResult;
/// 登录/切换账号 结果回调
@property (nonatomic,   copy) LoginResult loginResult;

/// 登录，这个方法将调起有SDK内置的界面
- (void)loginTimeWithFromViewController:(UIViewController *)fromViewController;
/// 登录，这个接口除了会显示第三方（如Facebook自带的界面）界面，不会显示本SDK UI相关的东西
/// @param loginType 登录方式
/// @param fromViewController 来自哪个viewController
- (void)loginTimeWithLoginType:(LoginType)loginType fromViewController:(UIViewController *)fromViewController;
/// 快捷登录,这个接口除了会显示第三方（如Facebook自带的界面）界面，不会显示本SDK UI相关的东西
/// 如果本地有登录状态，直接使用原来的状态登录，如果没有，将使用游客登录
/// @param fromViewController 来自哪个viewController
- (void)quickLoginTimeWithFromViewController:(UIViewController *)fromViewController;
/// 切换账号（主动调用退出，并调出登录UI页面）
- (void)switchAccount;
/// 退出账号（主动调用退出，并返回是否退出成功）
- (void)logoutAccount;

/// 用户分享游戏（给用户记录分享贡献度）
+ (void)userShareApp;

/// timeSDK 版本
@property (nonatomic, copy, readonly) NSString *timeSDKVersion;

///游戏断线标记，默认没断线
@property (nonatomic,assign,)BOOL isOffLine;


@end

NS_ASSUME_NONNULL_END
