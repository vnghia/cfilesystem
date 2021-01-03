"""A module handles all IO and TLS work for application protocols."""

load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "aws_c_io",
    srcs = glob([
        "source/*.c",  # AWS_IO_SRC
    ]) + select({
        # AWS_IO_OS_SRC
        "@bazel_tools//src/conditions:windows_msvc": glob([
            "source/windows/*.c",
            "source/windows/iocp/*.c",
        ]),
        "@bazel_tools//src/conditions:linux_x86_64": glob([
            "source/linux/*.c",
            "source/posix/*.c",
            "source/s2n/*.c",  # AWS_IO_TLS_SRC
        ]),
        "@bazel_tools//src/conditions:darwin": glob([
            "source/bsd/*.c",
            "source/posix/*.c",
            "source/darwin/*.c",
        ]),
        "@bazel_tools//src/conditions:freebsd": glob([
            "source/bsd/*.c",
            "source/posix/*.c",
            "source/s2n/*.c",  # AWS_IO_TLS_SRC
        ]),
        "//conditions:default": [],
    }),
    hdrs = glob([
        "include/aws/io/*.h",  # AWS_IO_HEADERS
        "include/aws/io/uv/*.h",  # AWS_IO_UV_HEADERS
        "include/aws/io/private/*.h",  # AWS_IO_PRIV_HEADERS
    ]),
    defines = select({
        # EVENT_LOOP_DEFINE
        "@bazel_tools//src/conditions:windows_msvc": [
            "AWS_USE_IO_COMPLETION_PORTS",
        ],
        "@bazel_tools//src/conditions:linux_x86_64": [
            "AWS_USE_EPOLL",
        ],
        "@bazel_tools//src/conditions:darwin": [
            "AWS_USE_KQUEUE",
        ],
        "@bazel_tools//src/conditions:freebsd": [
            "AWS_USE_KQUEUE",
        ],
    }),
    includes = ["include"],
    linkopts = select({
        # PLATFORM_LIBS
        "@bazel_tools//src/conditions:windows_msvc": [
            "-DEFAULTLIB:secur32.lib",
            "-DEFAULTLIB:crypt32.lib",
            "-DEFAULTLIB:shlwapi.lib",
        ],
        "@bazel_tools//src/conditions:darwin": [
            "-framework Security",
        ],
        "//conditions:default": [],
    }),
    deps = [
        "@aws_c_cal",
        "@aws_c_common",
    ] + select({
        "@bazel_tools//src/conditions:linux_x86_64": [
            "@aws_s2n",
        ],
        "@bazel_tools//src/conditions:freebsd": [
            "@aws_s2n",
        ],
        "//conditions:default": [],
    }),
)
