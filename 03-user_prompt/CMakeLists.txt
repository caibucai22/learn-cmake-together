cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(recipe-03 LANGUAGES CXX)

option(USE_LIBRARY "Compile sources into a library" OFF)

include(CMakeDependentOption)

cmake_dependent_option(
  MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
  "USE_LIBRARY" ON
)

cmake_dependent_option(
  MAKE_STATIC_LIBRARY "Compile sources into a shared library" ON
  "USE_LIBRARY" ON
)

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

