# 507find_package/CMakeLists.txt

cmake_minimum_required(VERSION 3.22)
project(findpkg)

if(NOT version)
set(version 1)
endif()

file(WRITE main.cpp [=[

#include "slib.h"
#include <iostream>

using namespace std;
int main()
{
  cout<<"in main"<<endl;
  slib();
  return 0;
}

]=])

message("find package ${version}")
# cmake -S . -B build -DCMAKE_PREFIX_PATH=/home/.../xcpp -Dversion1.1
find_package(slib ${version})
#[[
CMake Warning at CMakeLists.txt:21 (find_package):
  By not providing "Findslib.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "slib", but
  CMake did not find one.

  Could not find a package configuration file provided by "slib" with any of
  the following names:

    slibConfig.cmake
    slib-config.cmake

  Add the installation prefix of "slib" to CMAKE_PREFIX_PATH or set
  "slib_DIR" to a directory containing one of the above files.  If "slib"
  provides a separate development package or SDK, be sure it has been
  installed.
]]
message("slib_found = ${slib_FOUND}")
if(slib_FOUND)
message("find slib success!")
endif()

add_executable(main main.cpp)

target_link_libraries(main slib)

get_target_property(inc slib INTERFACE_INCLUDE_DIRECTORIES)

message("INTERFACE_INCLUDE_DIRECTORIES = ${inc}")