cmake_minimum_required(VERSION 3.20)

project(xlog)

include_directories("xlog")

#cmakelists.txt 路径
message("${CMAKE_CURRENT_LIST_DIR}")


# linux .so 库输出路径 默认 -B build目录下

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/../lib")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/../../lib")

# 执行程序和dll 动态库pdb调试文件 输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

# 归档输出路径 静态库 .lib 动态库.lib地址文件 linux静态库.a 静态库pdb?exp调试文件
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

set(BUILD_SHARED_LIBS OFF)
#添加xlog库编译 项目自带预处理变量 xlog_EXPORTS
add_definitions(-Dxlog_STATIC)


add_library(xlog xlog/xlog.cpp)

# 创建动态库
add_library(xlog_d SHARED xlog/xlog.cpp)

#执行文件
add_executable(test_xlog test_xlog/test_xlog.cpp)

target_link_libraries(test_xlog xlog)