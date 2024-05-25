#403cmake_object/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)

project(cmake_object)

# a.cpp b.cpp => testa
# main.cpp libtesta.so => main

file(WRITE a.cpp [=[
#include <iostream>
void A(){std::cout<<"A\n";}
]=])

file(WRITE b.cpp [=[
#include <iostream>
void B(){std::cout<<"B\n";}
]=])

file(WRITE main.cpp [=[
#include <iostream>
void A();
void B();
int main(){
  A();
  B();
  std::cout<<"main\n";}
]=])

# object 对象 a.cpp.o b.cpp.o
add_library(testa_obj OBJECT a.cpp b.cpp)

# 1
if(NOT MSVC)
target_compile_options(testa_obj PRIVATE "-fPIC")
endif()

# 2
# 是否加 -fPIC ON 添加
# set_target_properties(testa_obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

# obj -> so/lib
# 用生成器表达式获取 object 对象
# add_library(testa testa_obj) # Cannot find source file testa_obj

# add_library shared 会自动添加 -fpIC
add_library(testa SHARED $<TARGET_OBJECTS:testa_obj>)

add_executable(main main.cpp) # link 找不到 testa.lib

target_link_libraries(main testa)