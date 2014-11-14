Pod::Spec.new do |s|
  s.name             = 'EQGTMOAuth'
  s.version          = '1.0'
  s.license          = 'MIT'
  s.summary          = 'Stripped down OAuth engine for iOS.'
  s.homepage         = 'https://github.com/equinux/eqgtm-oauth'

  s.author           = { 'equinux' => 'support@equinux.com' }
  s.source           = { :git => 'https://github.com/equinux/eqgtm-oauth.git', :tag => '1.0' }
  s.ios.deployment_target = '6.0'
  s.requires_arc = false
  s.public_header_files = '**/*.h'
  s.source_files = '**/*.{h,m}'
  s.ios.frameworks = 'Security', 'SystemConfiguration'
end
