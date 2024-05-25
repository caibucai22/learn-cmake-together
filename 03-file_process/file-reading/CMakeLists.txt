cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(file-process LANGUAGES CXX)

# file reading

file(READ test.txt content)

file(STRINGS test.txt strs)

# file(HASH SHA1 test.txt ret) # error

file(TIMESTAMP test.txt time)



message("the content is ${content}")

foreach(itm ${strs})
  message("itm is ${itm}")
endforeach()

message("the hash value of test.txt is ${ret}")

message("the timestamp of test.txt is ${time}")

add_executable(main main.cpp)

# error
# file(GET_RUNTIME_DEPENDENCIES main RESOLVED_DEPENDENCIES_VAR my_dependencies)

foreach(dependency ${my_dependencies})
  message("depend on ${dependency}")
endforeach()


