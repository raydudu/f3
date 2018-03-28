#include <assert.h>
#include <windows.h>

#include "../freespace.h"

uint64_t get_freespace(const char *path) {
    DWORD lpSectorsPerCluster;
    DWORD lpBytesPerSector;
    DWORD lpNumberOfFreeClusters;
    DWORD lpTotalNumberOfClusters;

    assert(GetDiskFreeSpace(path, &lpSectorsPerCluster, &lpBytesPerSector, &lpNumberOfFreeClusters, &lpTotalNumberOfClusters));

    return lpSectorsPerCluster * lpBytesPerSector * lpNumberOfFreeClusters;
}