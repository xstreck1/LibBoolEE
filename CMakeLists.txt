project(LibBoolEE)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)


include_directories(.)

set(CMAKE_BUILD_TYPE Release)

add_definitions(-DBUILD_SHARED=1)
add_library(LibBoolEE SHARED LibBoolEE.cpp)


add_definitions(-DBUILD_SHARED=0)
add_executable(LibBoolEE_test test.cpp LibBoolEE.cpp)
target_link_libraries(LibBoolEE_test LibBoolEE)