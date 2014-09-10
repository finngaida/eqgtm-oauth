Pod::Spec.new do |s|
  s.name             = 'GTMOAuth'
  s.version          = '0.1.2'
  s.license          = 'MIT'
  s.summary          = 'OAuth engine for iOS.'
  s.homepage         = 'https://github.com/sdkdimon/gtm-oauth'
  
  s.author           = { 'daemmon' => 'sdkdimon@gmail.com' }
  s.source           = { :git => 'https://github.com/sdkdimon/gtm-oauth.git', :tag => '0.1.2' }
  
  s.ios.deployment_target = '6.0'
  
  s.requires_arc = false
  
  s.public_header_files = 'TouchBase/*.h', 'OAuth_v1.0/**/*.h', 'OAuth_v2.0/**/*.h'
  s.source_files = 'TouchBase/*.{h,m}', 'GTMHTTPFetcher/*.{h,m}', 'OAuth_v1.0/**/*.{h,m}', 'OAuth_v2.0/**/*.{h,m}'
  s.private_header_files = 'GTMHTTPFetcher/*.h'
  s.ios.frameworks = 'Security', 'SystemConfiguration'
end
