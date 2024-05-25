#702test_gtest/CMakeLists.txt

cmake_minimum_required(VERSION 3.22)
project(gtest_tar_build_install)


file(WRITE ${PROJECT_NAME}.cpp [=[

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

set(GTEST_PATH ${CMAKE_SOURCE_DIR}/gtest)

if(NOT EXISTS ${GTEST_PATH})
  # 解压文件
  # cmake -E 执行shell
  # PROJECT_BINARY_DIR -B build
  message("tar xf gtest-1.11.0.tar.gz")
  execute_process(COMMAND ${CMAKE_COMMAND}
  -E tar xf ${CMAKE_SOURCE_DIR}/gtest-1.11.0.tar.gz
  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
  )

  # cmake 配置  cmake -S . -B build
  set(GTEST_SOURCE "${PROJECT_BINARY_DIR}/googletest-release-1.11.0")
  message("${CMAKE_COMMAND} -S ${GTEST_SOURCE} -B ${GTEST_SOURCE}/build")

  execute_process(COMMAND ${CMAKE_COMMAND}
  -S ${GTEST_SOURCE} -B ${GTEST_SOURCE}/build
  )

  # 3 编译gtest ->linux
  message("${CMAKE_COMMAND} --build ${GTEST_SOURCE}/build")
  execute_process(COMMAND ${CMAKE_COMMAND} --build ${GTEST_SOURCE}/build)

  # 安装

  message("${CMAKE_COMMAND} --install ${GTEST_SOURCE}/build --prefix=${GTEST_PATH}")
  execute_process(COMMAND ${CMAKE_COMMAND} --install ${GTEST_SOURCE}/build
  --prefix=${GTEST_PATH} --config Debug
  )

endif()



add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

# 查找gtest库 默认找不到 要找config
set(CMAKE_PREFIX_PATH ${GTEST_PATH}/lib/cmake/)
find_package(GTest)
message("GTest = ${GTest_FOUND}")
target_link_libraries(${PROJECT_NAME}
GTest::gtest_main
)

# windows 下 会与运行时库不一致


# 联合ctest和gtest

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})


# 打开才能运行ctest
enable_testing()
