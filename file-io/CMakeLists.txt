cmake_minimum_required(VERSION 3.13)  # CMake version check
project(file-io)         # Create project

set(SOURCE_FILES file-io-posix.c)

add_library(file-io ${SOURCE_FILES})
