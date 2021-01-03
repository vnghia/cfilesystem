#ifndef CFILESYSTEM_PLUGINS_COMMON_STATUS_H_
#define CFILESYSTEM_PLUGINS_COMMON_STATUS_H_

#include <string>

struct fs_status {
  int code = 0;
  std::string name;
  std::string msg;
};

#endif  // CFILESYSTEM_PLUGINS_COMMON_STATUS_H_