cmake_minimum_required(VERSION 3.6)

project(f3)

set(CMAKE_C_STANDARD 99)

include_directories(platform)

set(F3READ_SRCS
        f3read.c
        utils.c utils.h
        version.h
        )

set(F3WRITE_SRCS
        f3write.c
        utils.c utils.h
        version.h
        )

if (APPLE)
    add_definitions(-D_DARWIN_C_SOURCE)
    link_libraries(m)
endif(APPLE)

if(UNIX AND NOT APPLE) # Linux?
    add_definitions(-D_GNU_SOURCE)
    link_libraries(m)
    set(F3WRITE_SRCS ${F3WRITE_SRCS} platform/freespace.h platform/linux/freespace.c)
endif(UNIX AND NOT APPLE)

if(WIN32 OR WIN64)
    include_directories(platform/win)
    file(GLOB_RECURSE WIN_HEADERS platform/win *.h)
    set(F3READ_SRCS ${F3READ_SRCS} ${WIN_HEADERS} platform/win/time.c)
    set(F3WRITE_SRCS ${F3WRITE_SRCS} ${WIN_HEADERS} platform/win/time.c platform/freespace.h platform/win/freespace.c platform/win/round.c)
endif(WIN32 OR WIN64)

add_executable(${PROJECT_NAME}write ${F3WRITE_SRCS})
add_executable(${PROJECT_NAME}read ${F3READ_SRCS})

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
