cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(01-hello-cmake LANGUAGES CXX)

add_executable(hello-world hello-world.cpp)