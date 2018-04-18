Pod::Spec.new do |s|
  s.name             = 'EQGTMOAuth-watchOS'
  s.version          = '1.1.5'
  s.license          = 'Apache'
  s.summary          = 'Stripped down OAuth engine for iOS.'
  s.homepage         = 'https://github.com/equinux/eqgtm-oauth'

  s.author           = { 'equinux' => 'support@equinux.com' }
  s.source           = { :git => 'https://github.com/finngaida/eqgtm-oauth.git', :tag => s.version }

  s.watchos.deployment_target = '3.0'
  s.watchos.public_header_files = 'OAuth_v1.0/*.h'
  s.watchos.source_files = 'OAuth_v1.0/*.{h,m}'
  s.watchos.frameworks = 'Security'

  s.requires_arc = false
end
