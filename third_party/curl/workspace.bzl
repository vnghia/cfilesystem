"""Curl"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_curl():
    """loads Curl"""

    if "curl" not in native.existing_rules():
        http_archive(
            name = "curl",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/curl:curl.BUILD",
            strip_prefix = "curl-7.69.1",
            urls = [
                "https://curl.haxx.se/download/curl-7.69.1.tar.gz",
            ],
            sha256 = "01ae0c123dee45b01bbaef94c0bc00ed2aec89cb2ee0fd598e0d302a6b5e0a98",
        )
