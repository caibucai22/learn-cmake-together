#103message/CMakeLists.txt
#[[
message(arg1 arg2 arg3)
]]
cmake_minimum_required(VERSION 3.20)
project(message)

message("arg1")

message("arg1" "arg2" #[[message 中的注释 ]] "arg3")

#2.3 message 高级使用-指定日志基本

# message(FATAL_ERROR "test fatal error")

# 进程继续 不会生成 add_executable add_library
# message(SEND_ERROR "test send error")

# add_executable(test_message test_message.cpp)

# warning 打印路径和行号
message(WARNING "test warning")

#notice = none
message(NOTICE "test notice")

# status 加前缀 --
message(STATUS "test status")

#verbose 默认不显示 用户需要的详细信息  加前缀 --
message(VERBOSE "test verbose")

# 设置日志显示级别

# cmake -S . -B build --log-level=VERBOSE 

#标准输出重定向到文件log.txt
# cmake -S . -B build --log-level=VERBOSE > log.txt 

#标准错误输出重定向到标准输出
# cmake -S . -B build --log-level=VERBOSE > log.txt 2>&1

# DEBUG 加前缀 --
message(DEBUG "test debug")
# TRACE 加前缀 --
message(TRACE "test trace")

# 2.4 message reporting checks 查找库日志
#[[
CHECK_START
CHECK_PASS
CHECK_FAIL
]]
message("====================================2.4===========================")
#开始查找
message(CHECK_START "查找xcpp")
#查找xcpp代码
# message 消息缩进
set(CMAKE_MESSAGE_INDENT "--")

# 嵌套查找
message(CHECK_START "查找xlog")
message(CHECK_PASS "成功")

message(CHECK_START "查找xthreadpool")
message(CHECK_FAIL "失败")
set(CMAKE_MESSAGE_INDENT "")
#
message(CHECK_FAIL "失败")