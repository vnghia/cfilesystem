"""BoringSSL"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_boringssl():
    """loads BoringSSL"""

    if "boringssl" not in native.existing_rules():
        http_archive(
            name = "boringssl",
            strip_prefix = "boringssl-bdbe37905216bea8dd4d0fdee93f6ee415d3aa15",
            urls = [
                "https://github.com/google/boringssl/archive/bdbe37905216bea8dd4d0fdee93f6ee415d3aa15.tar.gz",
            ],
            sha256 = "ce183cb587c0a0f5982e441dff91cb5456d4c85cfa3fb12816e7a93f20645e51",
        )
