cmake_minimum_required(VERSION 3.8)
project(task1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pcg_extras.hpp pcg_random.hpp pcg_uint128.hpp task1.cpp task1.h task2.cpp task2.h task3.cpp task3.h)
add_executable(task1 ${SOURCE_FILES})