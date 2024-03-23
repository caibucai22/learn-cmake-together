cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(if_argument LANGUAGES CXX)

set(USE_LIBRARY OFF)

message(STATUS "compile sources into a library ? ${USE_LIBRARY}")

set(BUILD_SHARED_LIBS OFF)

list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
  add_library(message ${_sources})
  add_executable(hello-world hello-world.cpp)
  target_link_libraries(hello-world message)
else()
  add_executable(hello-world hello-world.cpp ${_sources})
endif()