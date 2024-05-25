
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

