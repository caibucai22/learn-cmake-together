# 507find_package/CMakeLists.txt

cmake_minimum_required(VERSION 3.22)
project(findpkg)


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

set(slib_DIR "E:\\my-github-repos\\learn-cmake-together\\ref_course\\506export_my_package\\out\\config")
find_package(slib)
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