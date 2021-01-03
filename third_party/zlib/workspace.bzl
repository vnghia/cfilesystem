"""Zlib"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_zlib():
    """loads Zlib"""

    if "zlib" not in native.existing_rules():
        http_archive(
            name = "zlib",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/zlib:zlib.BUILD",
            strip_prefix = "zlib-1.2.11",
            urls = [
                "https://zlib.net/zlib-1.2.11.tar.gz",
            ],
            sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        )
