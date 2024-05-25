cmake_minimum_required(VERSION 3.20)

project(cmake_exp)

add_executable(cmake_exp cmake_exp.cpp)

#[[
逻辑运算符
$<BOOL:string>
$<NOT:condition>
$<AND:conditions>
$<OR:conditions>
]]

target_compile_definitions(cmake_exp PUBLIC "$<$<BOOL:ON>:TEST1=123>")

# 测试生成表达式的方式
# 利用cmake错误来查看
# target_include_directories(cmake_exp PUBLIC "$<BOOL:TRUE>")
# target_include_directories(cmake_exp PUBLIC "$<OR:1,0>")

set(LIB OFF)

#LIB等于OFF 时，显示STATIC ON 显示空
# target_include_directories(cmake_exp PUBLIC "$<$<NOT:$<BOOL:${LIB}>>:STATIC>")

#在配置阶段不处理生成表达式
#message($<$<NOT:$<BOOL:${LIB}>>:STATIC>)

#生成一个定义目标 
#cmake 生成表达式调试方法 官方推荐
# cmake -E echo "生成表达式"

# add_custom_target(gen COMMAND ${CMAKE_COMMAND} -E echo "$<$<NOT:$<BOOL:${LIB}>>:STATIC>")


#字符串比较
# $<STREQUAL:string1,string2>
# $<EQUAL:value1,value2>
# target_include_directories(cmake_exp PUBLIC "$<STREQUAL:${LIB},OFF>")
# target_include_directories(cmake_exp PUBLIC "$<EQUAL:123,123>")

#变量查询
# $<CONFIG:cfgs>
# $<CONFIG> Debug Release
# $<CONFIG:Debug,Release> 配置项是 debug release 之一返回1
# target_include_directories(cmake_exp PUBLIC "$<CONFIG:Debug,Release>")


# $<PLATFORM_ID:platform_ids> 系统名称 
message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")

# target_include_directories(cmake_exp PUBLIC "$<PLATFORM_ID:Windows,Linux>")


# $<IF:condition,true_string,false_string>

# target_include_directories(cmake_exp PUBLIC "$<IF:$<BOOL:${LIB}>,ON,OFF>")

# set(conf "Debug")
# set(exp "$<STREQUAL:$<LOWER_CASE:${conf}>,debug>")


# 目标相关查询
# 生成目标的全路径
# set(exp "$<TARGET_FILE:cmake_exp>")
# target_include_directories(cmake_exp PUBLIC "${exp}")
# 获取目标属性
set(exp "$<TARGET_PROPERTY:cmake_exp,NAME>")

add_custom_target(gen COMMAND ${CMAKE_COMMAND} -E echo "${exp}")

