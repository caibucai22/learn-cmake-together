cmake_minimum_required(VERSION 3.20)

project(program_structure)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

add_subdirectory(log)

add_subdirectory(utils)

add_executable(${PROJECT_NAME} main.cpp)

# 指定包含目录
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/log ${CMAKE_CURRENT_LIST_DIR}/utils)

target_link_libraries(${PROJECT_NAME} log utils)