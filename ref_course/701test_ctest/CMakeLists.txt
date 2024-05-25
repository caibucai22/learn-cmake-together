# 701test_ctest/CMakeLists.txt

cmake_minimum_required(VERSION 3.22)

project(test_ctest)

file(WRITE test_ctest.cpp [=[

#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
  if(argc <=1 ) // 没有传递参数
    return -1;
  cout<<argv[1]<<endl;
  return 0;
}
]=])

add_executable(test_ctest test_ctest.cpp)

 
# 测试用例
add_test(NAME test_return_-1 #
COMMAND test_ctest 

)

add_test(NAME test_return_0 #
COMMAND test_ctest test_return_0
)

##################
add_test(NAME test_success # 测试控制台输出
COMMAND test_ctest success

)

set_tests_properties(test_success
PROPERTIES
PASS_REGULAR_EXPRESSION success #成功字符串匹配正则

)

add_test(NAME test_failed # 测试控制台输出
COMMAND test_ctest failed

) 
set_tests_properties(test_failed
PROPERTIES
FAIL_REGULAR_EXPRESSION failed #成功字符串匹配正则

)




enable_testing()