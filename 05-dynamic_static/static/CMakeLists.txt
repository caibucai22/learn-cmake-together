cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(recipe-03 LANGUAGES CXX)

add_library(message
  STATIC
    Message.hpp
    Message.cpp
)

add_executable(hello-world hello-world.cpp)

target_link_libraries(hello-world message)
