Pod::Spec.new do |s|
  s.name             = 'EQGTMOAuth'
  s.version          = '1.1.4'
  s.license          = 'Apache'
  s.summary          = 'Stripped down OAuth engine for iOS.'
  s.homepage         = 'https://github.com/equinux/eqgtm-oauth'

  s.author           = { 'equinux' => 'support@equinux.com' }
  s.source           = { :git => 'https://github.com/equinux/eqgtm-oauth.git', :tag => s.version }

  s.ios.deployment_target = '6.0'
  s.ios.public_header_files = 'OAuth_v1.0/*.h'
  s.ios.source_files = 'OAuth_v1.0/*.{h,m}'
  s.ios.frameworks = 'Security', 'SystemConfiguration'

  s.watchos.deployment_target = '3.0'
  s.watchos.public_header_files = 'OAuth_v1.0/*.h'
  s.watchos.source_files = 'OAuth_v1.0/*.{h,m}'
  s.watchos.frameworks = 'Security'

  s.tvos.deployment_target = '9.0'
  s.tvos.public_header_files = 'OAuth_v1.0/*.h'
  s.tvos.source_files = 'OAuth_v1.0/*.{h,m}'
  s.tvos.frameworks = 'Security', 'SystemConfiguration'

  s.osx.deployment_target = '10.7'
  s.osx.public_header_files = 'OAuth_v1.0/*.h'
  s.osx.source_files = 'OAuth_v1.0/*.{h,m}'

  s.requires_arc = false
end
