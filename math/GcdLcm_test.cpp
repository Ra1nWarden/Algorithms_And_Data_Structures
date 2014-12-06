#include "gtest/gtest.h"
#include "GcdLcm.h"

TEST(GreatestCommonDivisor, CoprimeOne) {
  EXPECT_EQ(1, GreatestCommonDivisor(1, 2));
}

TEST(GreatestCommonDivisor, CoprimeTwo) {
  EXPECT_EQ(1, GreatestCommonDivisor(3, 2));
}

TEST(GreatestCommonDivisor, CoprimeThree) {
  EXPECT_EQ(1, GreatestCommonDivisor(8, 9));
}

TEST(GreatestCommonDivisor, MultipleOne) {
  EXPECT_EQ(2, GreatestCommonDivisor(2, 4));
}

TEST(GreatestCommonDivisor, MultipleTwo) {
  EXPECT_EQ(2, GreatestCommonDivisor(4, 6));
}

TEST(LeastCommonMultiple, CoprimeOne) {
  EXPECT_EQ(2, LeastCommonMultiple(1, 2));
}

TEST(LeastCommonMultiple, CoprimeTwo) {
  EXPECT_EQ(10, LeastCommonMultiple(2, 5));
}

TEST(LeastCommonMultiple, MultipleOne) {
  EXPECT_EQ(15, LeastCommonMultiple(5, 15));
}

TEST(LeastCommonMultiple, MultipleTwo) {
  EXPECT_EQ(24, LeastCommonMultiple(6, 8));
}

TEST(SolveDiophantine, TestOne) {
  // 2x + 3y = 7
  pair<int, int> sol = SolveDiophantine(2, 3, 7);
  EXPECT_EQ(7, sol.first * 2 + sol.second * 3);
}

TEST(SolveDiophantine, TestTwo) {
  // 3x + 7y = 26
  pair<int, int> sol = SolveDiophantine(3, 7, 26);
  EXPECT_EQ(26, sol.first * 3 + sol.second * 7);
}

TEST(SolveDiophantine, TestThree) {
  // 10x + 5y = 50
  pair<int, int> sol = SolveDiophantine(10, 5, 50);
  EXPECT_EQ(50, sol.first * 10 + sol.second * 5);
}

TEST(SolveDiophantine, NegativeOne) {
  // -x + 3y = 6
  pair<int, int> sol = SolveDiophantine(-1, 3, 6);
  EXPECT_EQ(6, sol.first * -1 + sol.second * 3);
}

TEST(SolveDiophantine, NegativeTwo) {
  // -3x - 2y = -8
  pair<int, int> sol = SolveDiophantine(-3, -2, -8);
  EXPECT_EQ(-8, sol.first * -3 + sol.second * -2);
}

TEST(SolveDiophantine, ZeroOne) {
  // 0x + 2y = 8
  pair<int, int> sol = SolveDiophantine(0, 2, 8);
  EXPECT_EQ(8, sol.first * 0 + sol.second * 2);
}

TEST(SolveDiophantine, ZeroTwo) {
  // x + 2y = 0
  pair<int, int> sol = SolveDiophantine(1, 2, 0);
  EXPECT_EQ(0, sol.first * 1 + sol.second * 2);
}

