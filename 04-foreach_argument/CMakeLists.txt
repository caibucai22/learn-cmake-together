cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(foreach_argument LANGUAGES CXX)

list(APPEND files a.cpp b.cpp)

math(EXPR cnt "0")
foreach(file ${files})
  # message(STATUS "file_${cnt} ${file}")
  math(EXPR cnt "${cnt}+1")
endforeach()

foreach(i RANGE 10)
  # message(STATUS "${i}")
endforeach(i RANGE 10)

foreach(i RANGE 0 10 2)
  message(STATUS "${i}")
endforeach(i RANGE 10)


