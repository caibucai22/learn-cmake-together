#406cmake_vs_multithreaded/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

project(test_vs)
file(WRITE slib.cpp [=[
#include<iostream>
void slib()
{
  std::cout<<"slib"<<std::endl;
}
]=])

add_library(slib STATIC slib.cpp)
#静态库使用 MT 
set_target_properties(slib PROPERTIES
MSVC_RUNTIME_LIBRARY "MultiThreaded"
)

# debug release 不同
set_target_properties(slib PROPERTIES
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)

file(WRITE main.cpp [=[
#include<iostream>
int main()
{
  std::cout<<"in main"<<std::endl;
  void slib();
  slib();
  return 0;
}

]=])

# 默认运行时库 MD multiThreadedDLL
add_executable(main main.cpp)

set_target_properties(main PROPERTIES
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)

target_link_libraries(main slib)