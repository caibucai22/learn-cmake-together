#405cmake_debug_release/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_debug_release)

#静态库
# src/
#    slib.cpp
#    dlib.cpp
#    main.cpp
# bin
#   debug
#       main
#       dlib.dll [windows]       
#   release
# lib
#   debug
#       slib.lib [windows]
#       dlib.lib [windows]
#       dlib.so
#       slib.a
#   release


file(WRITE src/slib.cpp [=[
void SLib(){}
]=])

#[[
Debug
	-g
Release
	-O3
RelWithDebInfo
	-O2 -g
MinSizeRel 
	-O3
1) Linux mac 控制方法，vs项目不可用
    CMAKE_BUILD_TYPE
    linux默认为空，既不是debug也不是release
    set(CMAKE_BUILD_TYPE Debug)    
    -O3 -DNDEBUG 
    cmake -S . -B build -D CMAKE_BUILD_TYPE=Release    

    -O2 -g -DNDEBUG
    cmake -S . -B build -D CMAKE_BUILD_TYPE=RelWithDebInfo

    -Os -DNDEBUG 
    cmake -S . -B build -D CMAKE_BUILD_TYPE=MinSizeRel
2） windows vs nmake
    vs在生成阶段无法控制配置（自动生成4种）
    cmake --build win --config Release
    cmake --build win --config RelWithDebInfo
]]


if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Debug) 
endif()


message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

# 生成静态库
add_library(slib STATIC src/slib.cpp)

#输出路径
set(OUT_LIB_PATH ${CMAKE_SOURCE_DIR}/lib)
set(OUT_EXE_PATH ${CMAKE_SOURCE_DIR}/bin) # 执行程序和dll


set_target_properties(slib PROPERTIES
# 静态库和lib文件文件的输出 
ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release
)

#####################################
# 动态库
file(WRITE include/dlib.h [=[

#ifndef _WIN32 //linux mac unix Android
    #define XCPP_API
#else //windows
    //动态库
    #ifdef dlib_EXPORTS
        #define XCPP_API __declspec(dllexport) //库项目调用
    #else
        #define XCPP_API __declspec(dllimport) //调用库项目调用
    #endif
#endif

XCPP_API void DLib();
]=])

file(WRITE src/dlib.cpp [=[
#include "dlib.h"
void DLib(){}
]=])

#生成动态库
add_library(dlib SHARED src/dlib.cpp include/dlib.h)

target_include_directories(dlib PUBLIC include)

#动态库属性
set_target_properties(dlib PROPERTIES
# windows lib文件文件的输出 
ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release

# windos dll文件输出路径
RUNTIME_OUTPUT_DIRECTORY ${OUT_EXE_PATH}
RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_EXE_PATH}/debug
RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_EXE_PATH}/release

#linux .so 和mac
LIBRARY_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release

#windows pdb调试文件
PDB_OUTPUT_DIRECTORY ${OUT_LIB_PATH}/pdb
PDB_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/pdb

#debug 版本加后缀
DEBUG_POSTFIX "d"
)

#####################################
# 执行程序
file(WRITE src/main.cpp [=[
#include "dlib.h"
void SLib();
int main()
{
    DLib();
    SLib();
    return 0;
}
]=])
add_executable(main src/main.cpp)
target_link_libraries(main slib dlib)

set_target_properties(main PROPERTIES
# windos linux执行文件输出路径
RUNTIME_OUTPUT_DIRECTORY ${OUT_EXE_PATH}
RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_EXE_PATH}/debug
RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_EXE_PATH}/release


#调试路径 工作目录
#VS_DEBUGGER_WORKING_DIRECTORY  ${OUT_EXE_PATH}
# $<CONFIG:Debug> 0 1 
#$<IF:1,debug,release> 满足条件 返回debug
#$<IF:0,debug,release> 不满足条件 返回release
VS_DEBUGGER_WORKING_DIRECTORY $<IF:$<CONFIG:Debug>,debug,release>
)

if(MSVC)
set_target_properties(main PROPERTIES
#debug 版本加后缀
DEBUG_POSTFIX "d"
)
endif()