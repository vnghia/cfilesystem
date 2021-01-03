"""C99 implementation of the vnd.amazon.event-stream content-type."""

load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "aws_c_event_stream",
    srcs = glob(["source/*.c"]),  # AWS_EVENT_STREAM_SRC
    hdrs = glob([
        "include/aws/event-stream/*.h",  # AWS_EVENT_STREAM_HEADERS
        "include/aws/event-stream/private/*.h",  # AWS_EVENT_STREAM_PRIV_HEADERS
    ]),
    includes = ["include"],
    deps = [
        "@aws_c_common",
        "@aws_c_io",
        "@aws_checksums",
    ],
)
