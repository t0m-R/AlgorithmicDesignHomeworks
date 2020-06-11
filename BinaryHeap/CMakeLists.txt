cmake_minimum_required (VERSION 2.6)

project(BinaryHeap)

set(CMAKE_BUILD_TYPE Release)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)


file(GLOB SOURCES
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")

add_executable(heap ${SOURCES})
