"""Cross-Platform HW accelerated CRC32c and CRC32 with fallback to efficient SW implementations"""

load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "aws_checksums",
    srcs = glob([
        "source/*.c",  # AWS_CHECKSUMS_SRC
        "source/generic/*.c",  # AWS_ARCH_SRC
    ]),
    hdrs = glob([
        "include/aws/checksums/private/*.h",  # AWS_CHECKSUMS_PRIV_HEADERS
        "include/aws/checksums/*.h",  # AWS_CHECKSUMS_HEADERS
    ]),
    includes = ["include"],
    deps = [
        "@aws_c_common",
    ],
)
