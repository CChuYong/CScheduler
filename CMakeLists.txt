cmake_minimum_required(VERSION 3.21)
project(CScheduler)

set(CMAKE_CXX_STANDARD 14)

add_library(CScheduler task.cpp scheduler.cpp scheduler.h time_utils.cpp time_utils.h)
add_executable(test.out test/test.cpp task.cpp scheduler.cpp time_utils.cpp)
