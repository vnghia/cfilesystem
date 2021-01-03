"""AWS library for S3 filesystem"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_aws_sdk_cpp():
    """loads AWS library for S3 filesystem"""

    if "aws_c_cal" not in native.existing_rules():
        http_archive(
            name = "aws_c_cal",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/aws:aws_c_cal.BUILD",
            strip_prefix = "aws-c-cal-0.4.5",
            urls = [
                "https://github.com/awslabs/aws-c-cal/archive/v0.4.5.tar.gz",
            ],
            sha256 = "0d5525045c836e0deb3b10b4832d69d3a79fd36cb9c8cd0a4f376e28e1c6ec2f",
        )

    if "aws_c_common" not in native.existing_rules():
        http_archive(
            name = "aws_c_common",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/aws:aws_c_common.BUILD",
            strip_prefix = "aws-c-common-0.4.63",
            urls = [
                "https://github.com/awslabs/aws-c-common/archive/v0.4.63.tar.gz",
            ],
            sha256 = "6184de1b3502a8e3f078b9e4105e9cdf95d103a94c81774c314645dfb1bd5a2e",
        )

    if "aws_c_event_stream" not in native.existing_rules():
        http_archive(
            name = "aws_c_event_stream",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/aws:aws_c_event_stream.BUILD",
            strip_prefix = "aws-c-event-stream-0.2.6",
            urls = [
                "https://github.com/awslabs/aws-c-event-stream/archive/v0.2.6.tar.gz",
            ],
            sha256 = "bae0c762b6a4b779a0db0f4730512da6cb500e76681ffdcb9f7286d8e26e547a",
        )

    if "aws_c_io" not in native.existing_rules():
        http_archive(
            name = "aws_c_io",
            strip_prefix = "aws-c-io-0.7.0",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/aws:aws_c_io.BUILD",
            urls = [
                "https://github.com/awslabs/aws-c-io/archive/v0.7.0.tar.gz",
            ],
            sha256 = "f23a8e2a37d43ca1b85883e7a5498eb3474ee63cbc2a5b760bb9ff8aaf3b2492",
        )

    if "aws_checksums" not in native.existing_rules():
        http_archive(
            name = "aws_checksums",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/aws:aws_checksums.BUILD",
            strip_prefix = "aws-checksums-0.1.10",
            urls = [
                "https://github.com/awslabs/aws-checksums/archive/v0.1.10.tar.gz",
            ],
            sha256 = "c9d0100a5743765fc8034e34e2310f77f59b1adab6f2e2f2d4d2a3bd81b2a36d",
        )

    if "aws_s2n" not in native.existing_rules():
        http_archive(
            name = "aws_s2n",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/aws:aws_s2n.BUILD",
            strip_prefix = "s2n-0.10.19",
            urls = [
                "https://github.com/awslabs/s2n/archive/v0.10.19.tar.gz",
            ],
            sha256 = "8a5340c98013a5fa92a9f2ace5d30b194d8b4889e9b53a1f1e2b6b99ba38de3a",
        )

    if "aws_sdk_cpp" not in native.existing_rules():
        http_archive(
            name = "aws_sdk_cpp",
            build_file = "@com_github_vnvo2409_cfilesystem//third_party/aws:aws_sdk_cpp.BUILD",
            strip_prefix = "aws-sdk-cpp-1.8.114",
            urls = [
                "https://github.com/aws/aws-sdk-cpp/archive/1.8.114.tar.gz",
            ],
            sha256 = "92b707b2d6aadfc4e9486b2522204e597726f31b32c684e44e6c31bfa2bc9374",
        )
