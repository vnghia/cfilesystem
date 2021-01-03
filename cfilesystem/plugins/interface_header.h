#ifndef CFILESYSTEM_PLUGINS_INTERFACE_HEADER_H_
#define CFILESYSTEM_PLUGINS_INTERFACE_HEADER_H_

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/* --------------------------------- status --------------------------------- */

void* fs_status_new();
int fs_status_code(void* self);
const char* fs_status_name(void* self);
const char* fs_status_message(void* self);
void fs_status_set(void* self, int code, const char* name, const char* msg);
void fs_status_clear(void* self);
void fs_status_delete(void* self);

void fs_status_set_raw(void* self, void* raw);

/* ------------------------------- filesystem ------------------------------- */

void* fs_init(void* status);
void fs_cleanup(void* self);

/* ------------------------------ readable file ----------------------------- */

void* fs_readable_init(void* filesystem, void* status);
void fs_readable_cleanup(void* filesystem, void* self);

void fs_readable_open(void* filesystem, void* self, const char* path,
                      void* status);
void fs_readable_close(void* filesystem, void* self, void* status);

long long fs_readable_read_offset(void* filesystem, void* self,
                                  long long offset, char* buf, long long n,
                                  void* status);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // CFILESYSTEM_PLUGINS_INTERFACE_HEADER_H_
