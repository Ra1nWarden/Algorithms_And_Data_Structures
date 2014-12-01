#include "gtest/gtest.h"

TEST(SimpleTest, True) {
  EXPECT_EQ(1, 1);
}

TEST(SimpleTest, Assert) {
  ASSERT_TRUE(true);
}
