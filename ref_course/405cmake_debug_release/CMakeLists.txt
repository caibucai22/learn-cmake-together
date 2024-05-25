#405cmake_debug_release/CMakeLists.txt

cmake_minimum_required(VERSION 3.22)
project(cmake_debug_release)

#[[
src/
  slib.cpp
  dlib.cpp
  main.cpp
bin/
  debug
    main
    dlib.dll
  release
lib
  debug
    slib.lib
    dlib.lib
    dlib.so
    slib.a
  release
]]

file(WRITE src/slib.cpp [=[

void slib(){}

]=])



#[[


1) linux mac 控制方法 vs项目不可用
  CMAKE_BUILD_TYPE
  linux 默认为空, 既不是debug也不是release
  set()
  cmake -D CMAKE_BUILD_TYPE=Release

2) windows vs nmake
    vs 在生成阶段无法控制配置 自动生成4种 编译器选择
    cmake --build win --config Release 
]]


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()
message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

add_library(slib STATIC src/slib.cpp)

#配置输出路径
set(OUT_LIB_PATH ${CMAKE_SOURCE_DIR}/lib)
set(OUT_EXE_PATH ${CMAKE_SOURCE_DIR}/bin)

set_target_properties(slib PROPERTIES
#
ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release
)

#动态库
file(WRITE include/dlib.h [=[

#ifndef _WIN32 // linux mac unix android
  #define XCPP_API
#else // windows

  #ifdef dlib_EXPORTS
    #define XCPP_API __declspec(dllexport) // 库项目调用
  #else
    #define XCPP_API __declspec(dllimport) // 调用库项目调用
  #endif

#endif

XCPP_API void dlib();

]=])

file(WRITE src/dlib.cpp [=[
#include "dlib.h"

void dlib(){}

]=])

add_library(dlib SHARED src/dlib.cpp include/dlib.h)

target_include_directories(dlib PUBLIC include) # 

set_target_properties(dlib PROPERTIES
# windows lib 文件的输出
ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release

# windows dll文件输出路径
RUNTIME_OUTPUT_DIRECTORY ${OUT_EXE_PATH}
RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_EXE_PATH}/debug
RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_EXE_PATH}/release


#linux .so 和 mac
LIBRARY_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release

# windows pdb 文件
PDB_OUTPUT_DIRECTORY ${OUT_LIB_PATH}/pdb
PDB_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/pdb


# debug 版本加后缀
DEBUG_POSTFIX "d"

)





# 执行程序
file(WRITE src/main.cpp [=[
#include "dlib.h"
void slib();
int main()
{
  dlib();
  slib();


  return 0;
}

]=])

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include)
target_link_libraries(main slib dlib)

set_target_properties(main PROPERTIES

# windows/linux 执行文件输出路径
RUNTIME_OUTPUT_DIRECTORY ${OUT_EXE_PATH}
RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_EXE_PATH}/debug
RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_EXE_PATH}/release

# 调试路径
VS_DEBUGGER_WORKING_DIRECTORY ${OUT_EXE_PATH}
# debug release 利用生成器表达式 判断CONFIG 来确定
VS_DEBUGGER_WORKING_DIRECTORY ${OUT_EXE_PATH}/$<IF:$<CONFIG:Debug>,debug,release>
)

if(MSVC)
set_target_properties(main PROPERTIES
# windows debug 版本加后缀
DEBUG_POSTFIX "d"

)
endif()