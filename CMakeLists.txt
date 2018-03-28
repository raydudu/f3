cmake_minimum_required(VERSION 3.6)

project(f3)

set(CMAKE_C_STANDARD 99)

link_libraries(m)

if (APPLE)
    add_definitions(-D_DARWIN_C_SOURCE)
endif(APPLE)

if(UNIX AND NOT APPLE) # Linux?
    add_definitions(-D_GNU_SOURCE)
endif(UNIX AND NOT APPLE)


add_executable(${PROJECT_NAME}write f3write.c utils.c utils.h version.h)
add_executable(${PROJECT_NAME}read f3read.c utils.c utils.h version.h)

#[[
# TODO need libudev
# TODO need libparted
add_executable(${PROJECT_NAME}probe
        libutils.c libutils.h
        libdevs.c libdevs.h
        libprobe.c libprobe.h
        utils.c utils.h
        f3probe.c
        version.h
        )

add_executable(${PROJECT_NAME}brew
        libutils.c libutils.h
        libdevs.c libdevs.h
        f3brew.c
        )

add_executable(${PROJECT_NAME}fix
        utils.c utils.h
        f3fix.c
        version.h
        )]]
