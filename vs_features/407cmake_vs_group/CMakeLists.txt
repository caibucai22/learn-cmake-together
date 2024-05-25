#407cmake_vs_group/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

project(cmake_vs_group)


# message("CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
# message("CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
# message("CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

# message("===============")
# message("===============")

# message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
# message("CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
# message("CMAKE_CURRENT_LIST_DIR = ${CMAKE_CURRENT_LIST_DIR}")
# message("EXECUTABLE_OUTPUT_PATH = ${EXECUTABLE_OUTPUT_PATH}")
# message("LIBRARY_OUTPUT_PATH = ${LIBRARY_OUTPUT_PATH}")












file(WRITE main.cpp [=[
int main()
{
  return 0;
}

]=])

file(WRITE a.cpp "")
file(WRITE b.cpp "")
file(WRITE a.h "")
file(WRITE b.h "")


add_executable(vs_group main.cpp a.cpp b.cpp a.h b.h)

source_group(src FILES a.cpp b.cpp)
source_group(include FILES b.h)
# 后面src 路径 会去掉 root 内容 显示剩下的路径
source_group(TREE . PREFIX include/inc FILES a.h )

