cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(set_argument LANGUAGES CXX)

set(setting1 "setting1")

message(STATUS "this is ${setting1}")

set(package_dir "") # 安装后的位置

set(package_root "") # 源码的位置