cmake_minimum_required(VERSION 3.13)  # CMake version check
#set(CMAKE_GENERATOR "Ninja")
set(CMAKE_CXX_COMPILER "clang")
project(main)               # Create project "simple_example"
#set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
include_directories("file-io/include")
add_subdirectory("file-io")

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.c)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})
target_link_libraries(main file-io)