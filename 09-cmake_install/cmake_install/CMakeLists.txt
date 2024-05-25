cmake_minimum_required(VERSION 3.20)

project(cmake_install)

# 静态库 导出 .lib .a
file(WRITE include/slib.h "void slib();")
# 私有头文件
file(WRITE include/slib_pri.h "#define PRI")

file(WRITE slib.cpp "void slib(){}")

add_library(slib STATIC slib.cpp include/slib.h include/slib_pri.h)

set_target_properties(slib PROPERTIES
PUBLIC_HEADER include/slib.h
)

set_target_properties(slib PROPERTIES
PRIVATE_HEADER include/slib_pri.h
)


# 动态库 需要导出 不然 windows 不产生 .lib 文件
#[[
windows .lib .dll
linux .so
mac .dylib
]]
file(WRITE include/dlib.h [=[
#ifdef _WIN32
__declspec(dllexport)
#endif
void dlib();
]=])

file(WRITE dlib.cpp [=[
#include "dlib.h"
void dlib(){}
]=])

add_library(dlib SHARED dlib.cpp include/dlib.h)
target_include_directories(dlib PUBLIC include)

# 执行程序 引用动态库和静态库

file(WRITE main.cpp [=[
#include "dlib.h"
#include "slib.h"

int main()
{
  dlib();
  slib();
  return 0;
}

]=])

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} dlib)
target_link_libraries(${PROJECT_NAME} slib)


#####################
# 安装目标 CMAKE_INSTALL_PREFIX
# set(CMAKE_INSTALL_PREFIX "./out")
install(TARGETS slib dlib ${PROJECT_NAME} DESTINATION bin)

# 默认安装路径
#[[
linux /usr/local
windows c:/program files(x86)
windows 默认安装 release 版本
]]


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

install(TARGETS dlib slib 
RUNTIME DESTINATION bin 
ARCHIVE DESTINATION lib
# 头文件的安装
PUBLIC_HEADER DESTINATION include # 公开头文件 
PRIVATE_HEADER DESTINATION inc # 内部头文件
)


# debug release 不同输出路径
#[[
windows 编译过程
cmake -S . -B win -DCMAKE_INSTALL_PREFIX=win_out
cmake --build win --config Debug
cmake --install win --config Debug

Linux 编译过程 Debug Release
]]
install(TARGETS ${PROJECT_NAME}
CONFIGURATIONS Debug
RUNTIME DESTINATION debug/bin

)

install(TARGETS ${PROJECT_NAME}
CONFIGURATIONS Release RelWithDebInfo MinSizeRel
RUNTIME DESTINATION release/bin
)


