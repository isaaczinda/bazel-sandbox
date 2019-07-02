cc_binary(

  name = "main-static",
  srcs = ["src/main.cpp"],
  deps = ["//math:math"],

  # links with the math library statically
  # the :math_dll_import dependency won't be used for anything
  linkstatic = 1,
  defines = ["MATH_STATIC"],
)

cc_binary(
  name = "main-dynamic",
  srcs = ["src/main.cpp"],
  deps = ["//math:math"],

  # links with the math library dynamically
  # uses the //math:math_dll_import cc_import to get access to the
  # interface library
  linkstatic = 0,
)
