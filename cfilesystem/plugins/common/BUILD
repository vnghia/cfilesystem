load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "status",
    srcs = [
        "status.cc",
    ],
    hdrs = [
        "status.h",
    ],
    visibility = ["//cfilesystem/plugins:__subpackages__"],
    deps = [
        "//cfilesystem/plugins:interface_header",
    ],
    alwayslink = 1,
)
