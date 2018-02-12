# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB SOURCES_CPP ${CMAKE_SOURCE_DIR}/*.cpp)

add_executable(csvParser ${SOURCES_CPP})
