cmake_minimum_required(VERSION 3.20)

project(test_xlog)

include_directories("../xlog") # 头文件路径

# 指定库查找路径 windows 自动找 ../xlog/build/Debug ../xlog/build/Release
link_directories("../xlog/build")

add_executable(test_xlog test_xlog.cpp)

# 去哪找 找哪个

#指定加载的库
target_link_libraries(test_xlog xlog)


