cmake_minimum_required(VERSION 3.20)

project("auto_src_h")

#[[
108_auto_src_h
  CMakeLists.txt
  main.cpp
  src
    xlog.cpp
    xthread.cc
    xtest.c
  include
    xlog.h
    xthread.hpp
]]
#头文件加载
set(INCLUDE_PATH "./include")
include_directories(${INCLUDE_PATH})

# 找到当前目录下源码写入
aux_source_directory("." M_SRC)

aux_source_directory("./src" SRC)


# 读取所有头文件
file(GLOB H_FILE "${INCLUDE_PATH}/*.h*")

add_executable(${PROJECT_NAME} ${M_SRC} ${SRC} ${H_FILE})