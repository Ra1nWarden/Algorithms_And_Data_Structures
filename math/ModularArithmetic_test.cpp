#include "gtest/gtest.h"
#include "ModularArithmetic.h"

TEST(PowerModular, TestOne) {
  int a = 15;
  int n = 2;
  int m = 8;
  EXPECT_EQ(1, PowerModular(a, n, m));
}

TEST(PowerModular, TestTwo) {
  int a = 21;
  int n = 5;
  int m = 19;
  EXPECT_EQ(13, PowerModular(a, n, m));
}

TEST(PowerModular, TestThree) {
  int a = 13;
  int n = 6;
  int m = 11;
  EXPECT_EQ(9, PowerModular(a, n, m));
}

TEST(SolveModularEquation, PositiveTestOne) {
  int a = 3;
  int b = 1;
  int n = 4;
  int x;
  ASSERT_TRUE(SolveModularEquation(a, b, n, x));
  EXPECT_EQ(b, (a * x) % n);
}

TEST(SolveModularEquation, PositiveTestTwo) {
  int a = 3;
  int b = 6;
  int n = 9;
  int x;
  ASSERT_TRUE(SolveModularEquation(a, b, n, x));
  EXPECT_EQ(b, (a * x) % n);
}

TEST(SolveModularEquation, PositiveTestThree) {
  int a = 2;
  int b = 12;
  int n = 13;
  int x;
  ASSERT_TRUE(SolveModularEquation(a, b, n, x));
  EXPECT_EQ(b, (a * x) % n);
}

TEST(SolveModularEquation, PositiveTestFour) {
  int a = 7;
  int b = 6;
  int n = 13;
  int x;
  ASSERT_TRUE(SolveModularEquation(a, b, n, x));
  EXPECT_EQ(b, (a * x) % n);
}

TEST(SolveModularEquation, NegativeTestOne) {
  int a = 6;
  int b = 3;
  int n = 8;
  int x;
  ASSERT_FALSE(SolveModularEquation(a, b, n, x));
}

TEST(SolveModularEquation, NegativeTestTwo) {
  int a = 2;
  int b = 1;
  int n = 4;
  int x;
  ASSERT_FALSE(SolveModularEquation(a, b, n, x));
}
