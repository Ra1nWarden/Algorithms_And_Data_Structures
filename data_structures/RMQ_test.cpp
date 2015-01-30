#include "gtest/gtest.h"
#include "RMQ.h"

TEST(RMQ, Test1) {
  int v1[] = {1, 2, -1, 3, 4, 0, -2};
  RMQ rmq(v1, 7);
  EXPECT_EQ(1, rmq.query(0, 0));
  EXPECT_EQ(-1, rmq.query(0, 2));
  EXPECT_EQ(-1, rmq.query(0, 5));
  EXPECT_EQ(-2, rmq.query(0, 6));
}

TEST(RMQ, Test2) {
  int v1[] = {-2, -3, -1, 3, -4, 0, 2};
  RMQ rmq(v1, 7);
  EXPECT_EQ(-3, rmq.query(1, 1));
  EXPECT_EQ(-3, rmq.query(1, 3));
  EXPECT_EQ(-4, rmq.query(2, 4));
  EXPECT_EQ(0, rmq.query(5, 6));
}
