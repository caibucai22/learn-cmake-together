#105message_color/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(message_color)
#[[
\033[1;31;40m
\033[0m
显示方式
0
1
4
5
7
8
]]
set(ASCII 27 Esc)

set(R "${Esc}[0;31m")
set(E "${Esc}[m")
message("${R}红色内容${E}" " 默认内容")
message("${B}蓝色内容${E}" " 默认内容")