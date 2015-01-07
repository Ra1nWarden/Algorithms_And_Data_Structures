#include "gtest/gtest.h"
#include "UnionFindSet.h"

TEST(UnionFindSet, Initialization) {
  UnionFindSet u(5);
  for(int i = 0; i < 5; i++) {
    ASSERT_EQ(i, u.p[i]);
  }
}

TEST(UnionFindSet, Transitivity) {
  UnionFindSet u(5);
  u.UnionSet(0, 1);
  u.UnionSet(1, 2);
  EXPECT_TRUE(u.SameSet(0, 2));
}

TEST(UnionFindSet, FindSetTest) {
  UnionFindSet u(2);
  u.UnionSet(0, 1);
  EXPECT_EQ(1, u.p[0]);
}

// 1 2 3 5
// 4 6
// 7
TEST(UnionFindSet, Application1) {
  UnionFindSet u(8); // 7 + 1
  u.UnionSet(1, 2);
  u.UnionSet(3, 5);
  u.UnionSet(1, 5);
  u.UnionSet(4, 6);
  EXPECT_TRUE(u.SameSet(1, 2));
  EXPECT_TRUE(u.SameSet(2, 3));
  EXPECT_TRUE(u.SameSet(3, 5));
  EXPECT_FALSE(u.SameSet(1, 4));
  EXPECT_TRUE(u.SameSet(4, 6));
  EXPECT_FALSE(u.SameSet(6, 7));
  EXPECT_FALSE(u.SameSet(1, 7));
}
