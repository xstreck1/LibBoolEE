project(LibBoolEE)
cmake_minimum_required(VERSION 2.4)

include_directories(.)

set(CMAKE_BUILD_TYPE Release)

add_library(LibBoolEE LibBoolEE.cpp)

add_executable(LibBoolEE_test test.cpp LibBoolEE.cpp)
target_link_libraries(LibBoolEE_test LibBoolEE)