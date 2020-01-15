

Pod::Spec.new do |spec|

  spec.name         = "HeroCoinSDK"
  spec.version      = "0.0.2"
  spec.summary      = "游戏SDK"

  spec.description  = "Hero游戏SDK"

  spec.homepage     = "https://github.com/HeroGameSDK/HeroCoinSDKPod"

  spec.license      = { :type => "MIT", :file => "LICENSE" }


  spec.author             = { "huyunlong" => "yunlong.hu@timeltd.cn" }


  spec.platform     = :ios
  spec.platform     = :ios, "9.0"

  spec.source       = { :git => "https://github.com/HeroGameSDK/HeroCoinSDKPod.git", :tag => "#{spec.version}" }

  #spec.source_files  = "Classes", "Classes/**/*.{h,m}"
  #spec.exclude_files = "Classes/Exclude"

  #spec.public_header_files = "Classes/**/*.h"

  spec.resource  = "Assets/HeroCoinResources.bundle"
  spec.vendored_frameworks = "Classes/*.framework"

  # spec.framework  = "SomeFramework"
  # spec.frameworks = "SomeFramework", "AnotherFramework"


   spec.requires_arc = true

    spec.dependency "AFNetworking"
    spec.dependency "Masonry"
    spec.dependency "FBSDKLoginKit"
    spec.dependency "FBSDKShareKit"
    spec.dependency "JGProgressHUD"
    spec.dependency "MJRefresh"
    spec.dependency "YYModel"
    spec.dependency "Toast", "~> 4.0.0"
    spec.dependency "YYImage"
    spec.dependency "AppsFlyerFramework"
    spec.dependency "Firebase/Analytics"
    spec.dependency "Firebase/Messaging"
    spec.dependency "Firebase/DynamicLinks"
    spec.dependency "LineSDK"
    spec.dependency "TwitterKit"
    spec.dependency "WebViewJavascriptBridge"

end
