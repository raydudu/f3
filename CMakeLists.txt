cmake_minimum_required(VERSION 3.2)
project(f3 C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)

include_directories(.)

add_executable(f3write f3write.c utils.c utils.h)
target_link_libraries(f3write PRIVATE m)

add_executable(f3read f3read.c utils.c utils.h)

pkg_check_modules(UDEV libudev)
if (UDEV_FOUND)
    add_executable(f3probe f3probe.c
            libutils.c libutils.h
            libdevs.c libdevs.h
            libprobe.c libprobe.h
            utils.c utils.h)
    target_include_directories(f3probe PRIVATE ${UDEV_INCLUDE_DIRS})
    target_link_libraries(f3probe PRIVATE m ${UDEV_LIBRARIES})

    add_executable(f3brew f3brew.c
            libutils.c libutils.h
            libdevs.c libdevs.h)
    target_include_directories(f3brew PRIVATE ${UDEV_INCLUDE_DIRS})
    target_link_libraries(f3brew PRIVATE m ${UDEV_LIBRARIES})
else()
    message("libudev not found, f3probe and f3brew will not be built")
endif()

pkg_check_modules(PARTED libparted)
if (PARTED_FOUND)
    add_executable(f3fix f3fix.c
            utils.c utils.h)
    target_include_directories(f3fix PRIVATE ${PARTED_INCLUDE_DIRS})
    target_link_libraries(f3fix PRIVATE ${PARTED_LIBRARIES})
else()
    message("libparted not found, f3fix will not be built")
endif()
