"""AWS Crypto Abstraction Layer"""

load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "aws_c_cal",
    srcs = glob([
        "source/*.c",  # AWS_CAL_SRC
    ]) + select({
        # AWS_CAL_OS_SRC
        "@bazel_tools//src/conditions:windows_msvc": glob(["source/windows/*.c"]),
        "@bazel_tools//src/conditions:darwin": glob(["source/darwin/*.c"]),
        "//conditions:default": glob(["source/unix/*.c"]),
    }),
    hdrs = glob([
        "include/aws/cal/*.h",  # AWS_CAL_HEADERS
        "include/aws/cal/private/*.h",  # AWS_CAL_PRIV_SRC
    ]),
    includes = ["include"],
    linkopts = select({
        # PLATFORM_LIBS
        "@bazel_tools//src/conditions:windows_msvc": [
            "-DEFAULTLIB:bcrypt.lib",
        ],
        "@bazel_tools//src/conditions:darwin": [
            "-framework Security",
        ],
        "//conditions:default": [
            "-ldl",
        ],
    }),
    deps = select({
        # PLATFORM_LIBS
        "@bazel_tools//src/conditions:windows": [
            "@aws_c_common",
        ],
        "@bazel_tools//src/conditions:darwin": [
            "@aws_c_common",
        ],
        "//conditions:default": [
            "@aws_c_common",
            "@boringssl//:crypto",
        ],
    }),
)
