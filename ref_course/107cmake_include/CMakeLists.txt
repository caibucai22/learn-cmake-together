cmake_minimum_required(VERSION 3.20)

project("cmake_include")

message("begin include")
include("cmake/test_cmake.cmake")

include("cmake/test_cmake2.cmake" OPTIONAL) # 不存在 不报错

include("cmake/test_cmake2.cmake" OPTIONAL 
          RESULT_VARIABLE ret) # 不存在 不报错 rel 返回值

message("ret = ${ret}") # NOTFOUND

include("cmake/test_cmake.cmake" OPTIONAL 
          RESULT_VARIABLE ret) # 不存在 不报错 rel 返回值

message("ret = ${ret}") # NOTFOUND

message("end include")