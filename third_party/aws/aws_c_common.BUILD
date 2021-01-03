"""Core c99 package for AWS SDK for C"""

load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "aws_c_common",
    srcs = glob([
        "source/*.c",  # AWS_COMMON_SRC
        "include/aws/common/private/*.c",  # AWS_COMMON_PRIV_SRC
    ]) + select({
        # AWS_COMMON_OS_SRC
        "@bazel_tools//src/conditions:windows_msvc": glob(["source/windows/*.c"]),
        "//conditions:default": glob(["source/posix/*.c"]),
    }) + select({
        # AWS_COMMON_ARCH_SRC
        "@bazel_tools//src/conditions:windows_msvc": glob([
            "source/arch/intel/*.c",
            "source/arch/intel/msvc/*.c",
        ]),
        "//conditions:default": glob(["source/arch/generic/*.c"]),
    }),
    hdrs = [
        "include/aws/common/config.h",
    ] + glob([
        "include/aws/common/*.h",  # AWS_COMMON_HEADERS
        "include/aws/common/private/*.h",  # AWS_COMMON_PRIV_HEADERS
    ]) + select({
        # AWS_COMMON_OS_HEADERS
        "@bazel_tools//src/conditions:windows_msvc": glob(["include/aws/common/windows/*"]),
        "//conditions:default": glob(["include/aws/common/posix/*"]),
    }),
    includes = ["include"],
    linkopts = select({
        # PLATFORM_LIBS
        "@bazel_tools//src/conditions:windows_msvc": [
            "-DEFAULTLIB:kernel32.lib",
            "-DEFAULTLIB:bcrypt.lib",
            "-DEFAULTLIB:ws2_32.lib",
        ],
        "@bazel_tools//src/conditions:darwin": [
            "-ldl",
            "-lpthread",
            "-framework CoreFoundation",
        ],
        "@bazel_tools//src/conditions:linux_x86_64": [
            "-ldl",
            "-lm",
            "-lpthread",
            "-lrt",
        ],
        "@bazel_tools//src/conditions:freebsd": [
            "-ldl",
            "-lm",
            "-lthr",
            "-lexecinfo",
        ],
    }),
    local_defines = select({
        "@bazel_tools//src/conditions:windows_msvc": [],
        "@bazel_tools//src/conditions:darwin": [],
        "//conditions:default": [
            "_POSIX_C_SOURCE=200809L",
            "_XOPEN_SOURCE=500",
        ],
    }),
    textual_hdrs = glob([
        "include/**/*.inl",
    ]),
)

genrule(
    name = "aws_c_common_config_h",
    srcs = [
        "include/aws/common/config.h.in",
    ],
    outs = [
        "include/aws/common/config.h",
    ],
    cmd = "sed 's/cmakedefine/undef/g' $< > $@",
    visibility = ["//visibility:private"],
)
