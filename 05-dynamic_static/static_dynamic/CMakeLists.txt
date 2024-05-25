cmake_minimum_required(VERSION 3.20)

project(xlog)

include_directories(xlog)

# 添加xlog库编译 项目自带预处理变量 xlog_EXPORTS
add_library(xlog SHARED xlog/xlog.cpp)

add_executable(test_xlog test_xlog/test_xlog.cpp xlog)


target_link_libraries(test_xlog xlog)