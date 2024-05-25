cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(file_path)

file(TOUCH 1.txt)
file(MAKE_DIRECTORY files)
file(TOUCH files/2.txt)

file(REAL_PATH 1.txt abs_path BASE_DIRECTORY ${PROJECT_SOURCE_DIR}) # BASE_DIRECTORY 指定参考目录
message("the absolute path of 1.txt is ${abs_path}")

file(REAL_PATH files/2.txt abs_path2)
message("the absolute path of files/2.txt is ${abs_path2}")

file(RELATIVE_PATH rel_path ${PROJECT_SOURCE_DIR} "E:/CppProjects/CMake_Cookbook_Demos/file_process/file-path/1.txt")
message("the relative path ref ${PROJECT_SOURCE_DIR} is ${rel_path}")


file(TO_NATIVE_PATH "files/2.txt" native_path)
message("the native path of files/2.txt is ${native_path}")

file(TO_CMAKE_PATH "files/2.txt" cmake_path)
message("the cmake path of files/2.txt is ${cmake_path}")

