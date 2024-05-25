#702test_gtest/CMakeLists.txt

cmake_minimum_required(VERSION 3.22)
project(gtest_fetch)


file(WRITE gtest_fetch.cpp [=[

#include <gtest/gtest.h>

TEST(MyTest, MyTestDownload)
{
  EXPECT_EQ(7*6,42);
}

TEST(MyTest, MyTestUpload)
{
  EXPECT_EQ(7*6,1);
}

int main(int argc,char* argv[])
{
  // 初始化 gtest
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

]=])

# 使用fetchcontent 下载安装google test
include(FetchContent)

# 下载代码
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# cdn
# FetchContent_Declare(
#   googletest
#   URL http://cdn.tarsyun.com/src/release-1.11.0.tar.gz
# )

# 编译安装
FetchContent_MakeAvailable(googletest)

#[[
cmake -S . -B build
cmake --build build
cmake --install build --prefix=./ --config Debug
]]

add_executable(gtest_fetch gtest_fetch.cpp)

# 设置gtest 库 头文件自动推导
target_link_libraries(
  gtest_fetch
  GTest::gtest_main
)

# 联合ctest和gtest

include(GoogleTest)
gtest_discover_tests(gtest_fetch)


# 打开才能运行ctest
enable_testing()

