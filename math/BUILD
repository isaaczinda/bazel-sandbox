load(
  "//bazel:cross_platform.bzl",
  "cc_posix_binary",
  "cc_windows_binary",
)

### COMMON ###

# for static linking
cc_library(
    name = "math",
    visibility = ["//visibility:public"],

    # headers will be of the format math/___.h
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include",

    srcs = ["src/add.cpp"],
)

# for dynamic linking
cc_library(
  name = "math_dynamic",
  visibility = ["//visibility:public"],

  # headers will be of the format math/___.h
  hdrs = glob(["include/**/*.h"]),
  strip_include_prefix = "include",

  # include the .dll or .so file dependency for each OS
  deps = select({
      "@bazel_tools//src/conditions:windows": [":math_dll_import"],
      "//conditions:default": [":math_so_import"],
    }),
)

### POSIX ###

cc_posix_binary(
    name = "libmath_plugin.so",
    linkshared = 1,
    includes = ["include"],
    srcs = ["src/add.cpp"] + glob(["include/**/*.h"]),
    defines = ["MATH_EXPORTS"], # export symbols
)

cc_import(
  name = "math_so_import",
  shared_library = ":libmath_plugin.so",
)

### WINDOWS ###

cc_windows_binary(
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
