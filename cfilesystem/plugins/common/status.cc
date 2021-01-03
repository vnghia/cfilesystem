#include "cfilesystem/plugins/common/status.h"

#include "cfilesystem/plugins/interface_header.h"

void* fs_status_new() { return new fs_status{}; }

int fs_status_code(void* self) {
  auto st = static_cast<fs_status*>(self);
  return st->code;
}

const char* fs_status_name(void* self) {
  auto st = static_cast<fs_status*>(self);
  return st->name.c_str();
}

const char* fs_status_message(void* self) {
  auto st = static_cast<fs_status*>(self);
  return st->msg.c_str();
}

void fs_status_set(void* self, int code, const char* name, const char* msg) {
  auto st = static_cast<fs_status*>(self);
  st->code = code;
  if (name) st->name = name;
  if (msg) st->msg = msg;
}

void fs_status_clear(void* self) {
  auto st = static_cast<fs_status*>(self);
  st->code = 0;
  st->name.clear();
  st->msg.clear();
}

void fs_status_delete(void* self) {
  auto st = static_cast<fs_status*>(self);
  delete st;
}
