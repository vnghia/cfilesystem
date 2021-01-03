load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "s3_filesystem",
    srcs = ["s3_filesystem.cc"],
    visibility = ["//cfilesystem/plugins:__subpackages__"],
    deps = [
        "//cfilesystem/plugins:interface_header",
        "//cfilesystem/plugins/common:status",
        "@aws_sdk_cpp//:s3",
    ],
    alwayslink = 1,
)

cc_binary(
    name = "s3_filesystem_plugin",
    linkshared = True,
    deps = [
        ":s3_filesystem",
    ],
)
