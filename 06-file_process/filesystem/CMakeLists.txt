cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(filesystem)

file(TOUCH 1.txt)
file(TOUCH 2.txt)
file(TOUCH 3.txt )

file(GLOB my_files *.txt)

file(MAKE_DIRECTORY files)
file(TOUCH files/4.txt)
file(TOUCH files/5.txt)

file(GLOB_RECURSE all_files *.txt)


math(EXPR cnt "0")
foreach(file ${all_files})
  message("file_${cnt}: ${file}")
  math(EXPR cnt "${cnt}+1")
endforeach(file ${all_files})

file(REMOVE 1.txt)
file(REMOVE_RECURSE files/4.txt)

file(RENAME 2.txt 2_rename.txt)

file(TOUCH 2_temp.txt)
file(RENAME 2_temp.txt 2.txt)

file(COPY_FILE 2.txt 2_copy.txt)
file(COPY 2.txt DESTINATION files/2.txt)

file(INSTALL 2.txt DESTINATION ${CMAKE_PREFIX_PATH}/)

file(SIZE 2.txt size_var)
message("the size of 2.txt is ${size_var}")

if(LINUX)
  file(READ_SYMLINK)
  file(CREATE_LINK)
  file(CHMOD)
  file(CHMOD_RECURSE)
endif()