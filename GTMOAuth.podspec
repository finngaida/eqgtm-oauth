Pod::Spec.new do |s|
  s.name             = 'GTMOAuth'
  s.version          = '0.1.4'
  s.license          = 'MIT'
  s.summary          = 'OAuth engine for iOS.'
  s.homepage         = 'https://github.com/sdkdimon/gtm-oauth'
  
  s.author           = { 'daemmon' => 'sdkdimon@gmail.com' }
  s.source           = { :git => 'https://github.com/sdkdimon/gtm-oauth.git', :tag => '0.1.4' }
  s.ios.deployment_target = '6.0'
  s.requires_arc = false
  s.public_header_files = '**/*.h'
  s.source_files = '**/*.{h,m}'
  s.resource = 'OAuth_v1.0/Touch/*.xib', 'OAuth_v2.0/Touch/*.xib'
  s.ios.frameworks = 'Security', 'SystemConfiguration'
end
