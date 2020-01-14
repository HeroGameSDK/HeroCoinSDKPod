

Pod::Spec.new do |s|

s.name         = "HeroCoinSDK"
s.version      = "0.0.1"
s.summary      = "游戏SDK."

s.description  = <<-DESC
A short description of HeroCoinSDK.
DESC

s.homepage     = "https://github.com/HeroGameSDK/HeroCoinSDKPod"

s.license      = "MIT"

s.author             = { "Time" => "hylccmh@163.com" }

s.platform     = :ios
s.platform     = :ios, "9.0"

s.source       = { :git => "https://github.com/HeroGameSDK/HeroCoinSDKPod.git", :tag => "#{s.version}" }

s.vendored_frameworks = "Classes/*.framework"

s.resource     = 'Assets/HeroCoinResources.bundle'
#s.resource     = 'Assets/HeroCoinResources.bundle/**/*.png', 'Assets/HeroCoinResources.bundle/*.text'

s.dependency "AFNetworking"
s.dependency "Masonry"
s.dependency "FBSDKLoginKit"
s.dependency "FBSDKShareKit"
s.dependency "JGProgressHUD"
s.dependency "MJRefresh"
s.dependency "YYModel"
s.dependency "JSONKit", "~> 1.4"
s.dependency "YYImage"
s.dependency "AppsFlyerFramework"
s.dependency "Firebase/Analytics"
s.dependency "Firebase/Messaging"
s.dependency "Firebase/DynamicLinks"
s.dependency "LineSDK"
s.dependency "TwitterKit"
s.dependency "WebViewJavascriptBridge"

end







