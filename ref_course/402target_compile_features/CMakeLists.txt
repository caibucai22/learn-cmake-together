#402target_compile_features/CMakeLists.txt
cmake_minimum_required(VERSION 3.25)

project(compile_features)

file(WRITE main.cpp [=[

int main()
{

  return 0;
}

]=])

add_executable(main main.cpp)

# target_compile_features(main PRIVATE cxx_std_17)

# vs2022有效 ubuntu20.04 无效
target_compile_features(main PRIVATE cxx_std_23)

# 支持的特征数组
message("CMAKE_CXX_COMPILE_FEATURES = ${CMAKE_CXX_COMPILE_FEATURES}" ) 

foreach(var IN LISTS CMAKE_CXX_COMPILE_FEATURES)
message(${var})  
endforeach(var IN LISTS CMAKE_CXX_COMPILE_FEATURES)

# 判断特性是否支持
set(f1 cxx_std_23)

if(f1 IN_LIST CMAKE_CXX_COMPILE_FEATURES)
  message("support ${f1} feature")
  target_compile_features(main PRIVATE ${f1})
else()
  message("don't support ${f1} feature")
endif()
