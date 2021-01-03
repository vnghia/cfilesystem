#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/GetObjectRequest.h>

#include <atomic>
#include <cstdlib>

#include "cfilesystem/plugins/common/status.h"
#include "cfilesystem/plugins/interface_header.h"

constexpr char FS_S3_CLIENT_ALLOCATION_TAG[] = "FS_S3_CLIENT_ALLOCATION_TAG";

namespace {

Aws::Client::ClientConfiguration get_client_configuration() {
  Aws::Client::ClientConfiguration client_configuration;

  const char* endpoint = getenv("FS_AWS_S3_ENDPOINT");
  if (endpoint) client_configuration.endpointOverride = Aws::String(endpoint);

  const char* use_http = getenv("FS_AWS_S3_USE_HTTP");
  if (use_http && use_http[0] == '1')
    client_configuration.scheme = Aws::Http::Scheme::HTTP;

  const char* disable_ssl = getenv("FS_AWS_S3_DISABLE_SSL");
  if (disable_ssl && disable_ssl[0] == '1')
    client_configuration.verifySSL = false;

  return client_configuration;
};

std::shared_ptr<Aws::S3::S3Client> get_s3_client() {
  return Aws::MakeShared<Aws::S3::S3Client>(
      FS_S3_CLIENT_ALLOCATION_TAG, get_client_configuration(),
      Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never, false);
}

void parse_s3_path(const Aws::String& path, Aws::String* bucket,
                   Aws::String* key) {
  size_t scheme_end = path.find("://") + 2;
  size_t bucket_end = path.find("/", scheme_end + 1);

  *bucket = path.substr(scheme_end + 1, bucket_end - scheme_end - 1);
  *key = path.substr(bucket_end + 1);
}

}  // namespace

/* ------------------------------- filesystem ------------------------------- */

struct fs_s3_filesystem {
  fs_s3_filesystem() {
    if (++instance_count == 1) Aws::InitAPI(sdk_options);
    s3_client = get_s3_client();
  }
  ~fs_s3_filesystem() {
    if (--instance_count == 0) Aws::ShutdownAPI(sdk_options);
  }

  static Aws::SDKOptions sdk_options;
  static std::atomic<int> instance_count;
  std::shared_ptr<Aws::S3::S3Client> s3_client;
};

Aws::SDKOptions fs_s3_filesystem::sdk_options{};
std::atomic<int> fs_s3_filesystem::instance_count{0};

void* fs_init(void* status) { return new fs_s3_filesystem{}; }

void fs_cleanup(void* self) {
  auto fs = static_cast<fs_s3_filesystem*>(self);
  delete fs;
}

/* -------------------------------- readable -------------------------------- */

struct fs_s3_readable {
  Aws::String bucket;
  Aws::String key;
};

void* fs_readable_init(void* filesystem, void* status) {
  return new fs_s3_readable();
}

void fs_readable_cleanup(void* filesystem, void* self) {
  auto file = static_cast<fs_s3_readable*>(self);
  delete file;
}

void fs_readable_open(void* filesystem, void* self, const char* path,
                      void* status) {
  auto file = static_cast<fs_s3_readable*>(self);
  parse_s3_path(path, &file->bucket, &file->key);
}

void fs_readable_close(void* filesystem, void* self, void* status) {
  auto file = static_cast<fs_s3_readable*>(self);
  file->bucket.clear();
  file->key.clear();
}

long long fs_readable_read_offset(void* filesystem, void* self,
                                  long long offset, char* buf, long long n,
                                  void* status) {
  auto fs = static_cast<fs_s3_filesystem*>(filesystem);
  auto file = static_cast<fs_s3_readable*>(self);

  Aws::S3::Model::GetObjectRequest get_object_request;
  get_object_request.WithBucket(file->bucket).WithKey(file->key);

  Aws::String range = "bytes=";
  range.append(Aws::Utils::StringUtils::to_string(offset));
  range.append(1, '-');
  range.append(Aws::Utils::StringUtils::to_string(offset + n - 1));
  get_object_request.SetRange(range);

  auto get_object_outcome = fs->s3_client->GetObject(get_object_request);

  long long read = get_object_outcome.GetResult().GetContentLength();
  get_object_outcome.GetResult().GetBody().read(buf, read);
  return read;
}
