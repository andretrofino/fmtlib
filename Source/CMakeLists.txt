cmake_minimum_required(VERSION 3.6.0)

project(fmtlib_tests CXX)

set(fmtlib_tests_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Tests.cpp
)

add_executable(fmtlib_tests ${fmtlib_tests_SOURCE})