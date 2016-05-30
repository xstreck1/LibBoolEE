project(LibBoolEE)
cmake_minimum_required(VERSION 2.4)

include_directories(.)

set(CMAKE_BUILD_TYPE Release)

add_definitions(-DBUILD_SHARED=1)
add_library(LibBoolEE SHARED LibBoolEE.cpp)


add_definitions(-DBUILD_SHARED=0)
add_executable(LibBoolEE_test test.cpp LibBoolEE.cpp)
target_link_libraries(LibBoolEE_test LibBoolEE)