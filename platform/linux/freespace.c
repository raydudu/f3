#include <assert.h>
#include <sys/statvfs.h>

#include "../freespace.h"

/*TODO static inline */
uint64_t get_freespace(const char *path) {
    struct statvfs fs;
    assert(!statvfs(path, &fs));
    return (uint64_t)fs.f_frsize * (uint64_t)fs.f_bfree;
}
