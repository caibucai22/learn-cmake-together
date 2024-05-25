# 506export_my_package/CMakeLists.txt

cmake_minimum_required(VERSION 3.22)

project(export_my_package) # -Dversion1.1
# cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/home/.../xcpp -Dversion1.1
# cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/home/.../xcpp1.1 -Dversion1.1


if(NOT version)
set(version 1.0)
endif()

file(WRITE include/slib.h "void slib();")
file(WRITE slib.cpp.in [=[

#include <iostream>
#include "slib.h"
void slib()
{
  std::cout<<"${version} in slib func\n" <<std::endl;
}
]=])
# 替换文件中的变量
configure_file("slib.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/slib.cpp")

add_library(slib STATIC slib.cpp)
# 导出头文件 file glob
set_target_properties(slib PROPERTIES PUBLIC_HEADER include/slib.h)

#[[
Target "slib" INTERFACE_INCLUDE_DIRECTORIES property contains path:

    "E:/my-github-repos/learn-cmake-together/ref_course/506export_my_package/include"

  which is prefixed in the source directory.

]]
# target_include_directories(slib PUBLIC include) # PUBLIC 第三方调用时 也可以导入头文件
# 路径被两次引用 1 编译slib 库时 2 export 写入config时
target_include_directories(slib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # 仅在编译时有效
$<INSTALL_INTERFACE:${version}/include> # 只在install 时有值 绝对路径/include
) 

install(TARGETS slib
EXPORT slib
RUNTIME DESTINATION ${version}/bin
LIBRARY DESTINATION ${version}/lib
ARCHIVE DESTINATION ${version}/lib
PUBLIC_HEADER DESTINATION include
)

install(EXPORT slib FILE slibConfig.cmake DESTINATION config/slib-${version})
# <packagename>Config.cmake
# slibConfig.cmake

# 写入版本信息 slibConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${CMAKE_INSTALL_PREFIX}/config/slib-${version}/slibConfigVersion.cmake
  VERSION ${version}
  COMPATIBILITY SameMajorVersion #版本兼容问题 cmake.org.cn
)
