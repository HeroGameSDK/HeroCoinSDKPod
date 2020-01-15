

Pod::Spec.new do |spec|

  spec.name         = "HeroCoinSDK"
  spec.version      = "0.0.1"
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

   #spec.dependency "JSONKit", "~> 1.4"

end
