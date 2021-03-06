{
  'sources': [
    'test/bad_extension_test.cc',
    'test/context_destruction.cc',
    'test/extension_in_iframe.cc',
    'test/external_extension.cc',
    'test/internal_extension_browsertest.cc',
    'test/internal_extension_browsertest.h',
    'test/internal_extension_browsertest_api.js',
    'test/nested_namespace.cc',
    'test/conflicting_entry_points.cc',
    'test/test.idl',
    'test/xwalk_extensions_browsertest.cc',
    'test/xwalk_extensions_test_base.cc',
    'test/xwalk_extensions_test_base.h',
    'test/v8tools_module.cc',
  ],

  'dependencies': [
    'extensions/external_extension_sample.gyp:*',
  ],
  'includes': [
    'xwalk_js2c.gypi',
  ],
}
