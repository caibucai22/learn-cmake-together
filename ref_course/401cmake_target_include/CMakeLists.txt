cmake_minimum_required(VERSION 3.22)

project(cmake_target_include)

file(WRITE a.cpp [=[
#include <iostream>
void A()
{
#ifdef A_VAR
std::cout<<"In A "<<A_VAR<<std::endl;  
#endif
}
]=])

# 静态库
add_library(A STATIC a.cpp)

# PUBLIC  /I\A_PUBLIC
#[[
public 改变
INCLUDE_DIRECTORIES 当前目标使用的属性
INTERFACE_INCLUDE_DIRECTORIES 依赖当前目标所使用的属性

PRIVATE 改变 INCLUDE_DIRECTORIES
INTERFACE 改变 INTERFACE_INCLUDE_DIRECTORIES 
]]

# 相对路径会转绝对路径
target_include_directories(A PUBLIC "/A_PUBLIC")
target_include_directories(A PRIVATE "/A_PRIVATE")
target_include_directories(A INTERFACE "/A_INTERFACE")

# 设定A库的宏
target_compile_definitions(A PUBLIC A_VAR=123)

# 打印属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS A PROPERTIES 
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES)


#
file(WRITE b.cpp [=[
#include <iostream>
void A();
void B(){
  A();
#ifdef A_VAR
  std::cout<<"In B "<<A_VAR<<std::endl;  
#endif
// std::cout<<"In B "<<STATIC<<std::endl;  // 报错 只提供给 调用接口的，自己无法使用
}

]=])

add_library(B STATIC b.cpp)
# B->A
target_link_libraries(B PUBLIC A)
target_include_directories(B PUBLIC "/B_PUBLIC")

# 设定B库的宏 STATIC 标志B库编译时不需要 
target_compile_definitions(B INTERFACE STATIC=1)

# 打印属性 无法打印继承属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS B PROPERTIES 
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES)

#CMAKE 原生属性调试接口
set(CMAKE_DEBUG_TARGET_PROPERTIES 
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES)


file(WRITE main.cpp [=[
#include <iostream>
int main()
{
  void B();
  B();
  std::cout<<"In main "<< STATIC << std::endl;
  return 0;
}

]=])
# A public interface -> B -> main
# main->B->A
add_executable(main main.cpp)

target_link_libraries(main PUBLIC B)
