cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(file-writing LANGUAGES CXX)

file(WRITE output.txt "hello cmake,1,你好 cmake\n")
file(APPEND output.txt "this is additional content.")

file(TOUCH example.txt) # 更新文件时间 没有不创建
file(TOUCH_NOCREATE example.txt) # 更新文件时间 没有则创建

file(GENERATE OUTPUT generate.txt INPUT template.txt) # 根据模版生成输出文件

# error
set(content "cmake")
file(CONFIGURE OUTPUT generate2.txt CONTENT "hello ${content}") # 根据模版和变量值

