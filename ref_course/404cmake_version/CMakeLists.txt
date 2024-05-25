#404cmake_version/CMakeLists.txt
#只在Linux演示 动态库有版本号
#windows 无效

cmake_minimum_required(VERSION 3.22)

project(cmake_version)

file(WRITE a.cpp [=[ 
void A(){};

]=])


file(WRITE main.cpp [=[ 
int main(){return 0;}

]=])

add_library(a SHARED a.cpp)
#liba.so liba.so.15 liba.so.2.0.1

set_target_properties(a PROPERTIES
VERSION "2.0.1"
SOVERSION "15"
# NO_SONAME ON # 不生成库的符号链接
)

add_executable(main main.cpp)

target_link_libraries(main  a)

set_target_properties(main PROPERTIES
VERSION "2.0.1"
# SOVERSION "15" # 对可执行文件无效
)

