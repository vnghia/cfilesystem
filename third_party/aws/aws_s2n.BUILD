"""s2n is a C99 implementation of the TLS/SSL protocols"""

load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "aws_s2n",
    srcs = glob([
        "crypto/*.c",  # CRYPTO_SRC
        "error/*.c",  # ERROR_SRC
        "pq-crypto/*.c",  # PQ_SRC
        "stuffer/*.c",  # STUFFER_SRC
        "tls/*.c",  # TLS_SRC
        "utils/*.c",  # UTILS_SRC
    ]),
    hdrs = glob([
        "api/*.h",  # API_HEADERS
        "crypto/*.h",  # CRYPTO_HEADERS
        "error/*.h",  # ERROR_HEADERS
        "pq-crypto/*.h",  # PQ_HEADERS
        "stuffer/*.h",  # STUFFER_HEADERS
        "tls/*.h",  # TLS_HEADERS
        "tls/extensions/*.h",  # TLS_EXTENSIONS_HEADERS
        "utils/*.h",  # UTILS_HEADERS
    ]),
    defines = ["S2N_NO_PQ"],
    includes = [
        ".",
        "api",
    ],
    linkopts = select({
        # OS_LIBS
        "@bazel_tools//src/conditions:darwin": [
            "-lc",
            "-lpthread",
        ],
        "//conditions:default": [
            "-ldl",
            "-lpthread",
            "-lrt",
        ],
        "@bazel_tools//src/conditions:freebsd": [
            "-lthr",
        ],
    }),
    local_defines = [
        "_POSIX_C_SOURCE=200809L",
        "_FORTIFY_SOURCE=2",
    ],
    deps = [
        "@boringssl//:crypto",
    ],
)
