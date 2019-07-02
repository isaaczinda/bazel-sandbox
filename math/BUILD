cc_library(
    name = "math",
    visibility = ["//visibility:public"], # this is the only one that needs to be public

    # headers will be of the format math/___.h
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include",

    srcs = ["src/add.cpp"],

    # how incldue the interface library and the dll
    deps = [":math_dll_import"],
)

cc_binary(
    name = "math_plugin.dll",
    linkshared = 1,
    includes = ["include"],
    srcs = ["src/add.cpp"] + glob(["include/**/*.h"]),
    defines = ["MATH_EXPORTS"], # export symbols
)

# create the interface library for math_plugin.dll
filegroup(
  name = "math_import_lib",
  srcs = [":math_plugin.dll"],
  output_group = "interface_library",
)

# get access to interface library which can be linked
# create DLL which can be linked with at runtime
cc_import(
  name = "math_dll_import",
  interface_library = ":math_import_lib",
  shared_library = ":math_plugin.dll",
)
