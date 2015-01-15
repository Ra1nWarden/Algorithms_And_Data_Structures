#include "BinaryIndexTree.h"
#include "gtest/gtest.h"

using namespace std;

TEST(BinaryIndexTree, QueryAdd) {
  BinaryIndexTree bit;
  bit.add(1, 1);
  bit.add(3, 1);
  EXPECT_EQ(0, bit.sum(0));
  EXPECT_EQ(1, bit.sum(1));
  EXPECT_EQ(1, bit.sum(2));
  EXPECT_EQ(2, bit.sum(3));
}

TEST(BinaryIndexTree, QuerySub) {
  BinaryIndexTree bit;
  bit.add(1, 1);
  bit.add(3, -1);
  EXPECT_EQ(0, bit.sum(0));
  EXPECT_EQ(1, bit.sum(1));
  EXPECT_EQ(1, bit.sum(2));
  EXPECT_EQ(0, bit.sum(3));
}

TEST(BinaryIndexTree, QueryMix) {
  BinaryIndexTree bit;
  bit.add(1, 1);
  bit.add(3, -1);
  EXPECT_EQ(0, bit.sum(0));
  EXPECT_EQ(1, bit.sum(1));
  EXPECT_EQ(1, bit.sum(2));
  EXPECT_EQ(0, bit.sum(3));
  bit.add(2, 3);
  EXPECT_EQ(0, bit.sum(0));
  EXPECT_EQ(1, bit.sum(1));
  EXPECT_EQ(4, bit.sum(2));
  EXPECT_EQ(3, bit.sum(3));
}

TEST(BinaryIndexTree2D, QueryAdd) {
  BinaryIndexTree2D bit;
  bit.add(1, 1, 1);
  bit.add(3, 2, 3);
  EXPECT_EQ(0, bit.sum(1, 0));
  EXPECT_EQ(1, bit.sum(1, 1));
  EXPECT_EQ(4, bit.sum(3, 2));
  EXPECT_EQ(4, bit.sum(3, 3));
  EXPECT_EQ(1, bit.sum(3, 1));
}

TEST(BinaryIndexTree2D, QuerySub) {
  BinaryIndexTree2D bit;
  bit.add(1, 1, 1);
  bit.add(3, 2, -3);
  EXPECT_EQ(0, bit.sum(1, 0));
  EXPECT_EQ(1, bit.sum(1, 1));
  EXPECT_EQ(-2, bit.sum(3, 2));
  EXPECT_EQ(-2, bit.sum(3, 3));
  EXPECT_EQ(1, bit.sum(3, 1));
}

TEST(BinaryIndexTree2D, QueryMix) {
  BinaryIndexTree2D bit;
  bit.add(1, 1, 1);
  bit.add(3, 2, -3);
  EXPECT_EQ(0, bit.sum(1, 0));
  EXPECT_EQ(1, bit.sum(1, 1));
  EXPECT_EQ(-2, bit.sum(3, 2));
  EXPECT_EQ(-2, bit.sum(3, 3));
  EXPECT_EQ(1, bit.sum(3, 1));
  bit.add(3, 1, -2);
  bit.add(3, 2, 3);
  EXPECT_EQ(0, bit.sum(1, 0));
  EXPECT_EQ(1, bit.sum(1, 1));
  EXPECT_EQ(-1, bit.sum(3, 2));
  EXPECT_EQ(-1, bit.sum(3, 3));
  EXPECT_EQ(-1, bit.sum(3, 1));
}
