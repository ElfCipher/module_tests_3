cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(sqrsolver)

enable_testing()
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

set(HEADERS
    ./solver.h
)

set(SOURCES
    ./solver.cpp
    ./main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

gtest_discover_tests(${PROJECT_NAME})