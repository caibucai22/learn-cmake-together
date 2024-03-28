cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(file-lock-test)

message(STATUS "testing file lock")

file(TOUCH_NOCREATE "temp.txt")


message(STATUS "Directory arg is used to determined  whether object to be locked is a folder")
message(STATUS "RELEASE arg explicitly specify whether the file is freed.")
message(STATUS "GUARD arg decides level of lock for file. support function file process ")
message(STATUS "RESULT_VARIABLE arg if it exists, the result will be saved in  a following defined variable, or if lock failed, a fatal error will happen")
message(STATUS "TIMEOUT arg limit the time of trying lock. if it beyonds, a error will happen.")


file(LOCK "./temp.txt" GUARD FUNCTION RESULT_VARIABLE result TIMEOUT 3)
