#include "gtest/gtest.h"
#include "GcdLcm.h"

TEST(GreatestCommonDivisor, CoprimeOne) {
  EXPECT_EQ(GreatestCommonDivisor(1, 2), 1);
}

TEST(GreatestCommonDivisor, CoprimeTwo) {
  EXPECT_EQ(GreatestCommonDivisor(3, 2), 1);
}

TEST(GreatestCommonDivisor, CoprimeThree) {
  EXPECT_EQ(GreatestCommonDivisor(8, 9), 1);
}

TEST(GreatestCommonDivisor, MultipleOne) {
  EXPECT_EQ(GreatestCommonDivisor(2, 4), 2);
}

TEST(GreatestCommonDivisor, MultipleTwo) {
  EXPECT_EQ(GreatestCommonDivisor(4, 6), 2);
}

TEST(LeastCommonMultiple, CoprimeOne) {
  EXPECT_EQ(LeastCommonMultiple(1, 2), 2);
}

TEST(LeastCommonMultiple, CoprimeTwo) {
  EXPECT_EQ(LeastCommonMultiple(2, 5), 10);
}

TEST(LeastCommonMultiple, MultipleOne) {
  EXPECT_EQ(LeastCommonMultiple(5, 15), 15);
}

TEST(LeastCommonMultiple, MultipleTwo) {
  EXPECT_EQ(LeastCommonMultiple(6, 8), 24);
}

TEST(SolveDiophantine, TestOne) {
  // 2x + 3y = 7
  pair<int, int> sol = SolveDiophantine(2, 3, 7);
  EXPECT_EQ(sol.first * 2 + sol.second * 3, 7);
}

TEST(SolveDiophantine, TestTwo) {
  // 3x + 7y = 26
  pair<int, int> sol = SolveDiophantine(3, 7, 26);
  EXPECT_EQ(sol.first * 3 + sol.second * 7, 26);
}

TEST(SolveDiophantine, TestThree) {
  // 10x + 5y = 50
  pair<int, int> sol = SolveDiophantine(10, 5, 50);
  EXPECT_EQ(sol.first * 10 + sol.second * 5, 50);
}

TEST(SolveDiophantine, NegativeOne) {
  // -x + 3y = 6
  pair<int, int> sol = SolveDiophantine(-1, 3, 6);
  EXPECT_EQ(sol.first * -1 + sol.second * 3, 6);
}

TEST(SolveDiophantine, NegativeTwo) {
  // -3x - 2y = -8
  pair<int, int> sol = SolveDiophantine(-3, -2, -8);
  EXPECT_EQ(sol.first * -3 + sol.second * -2, -8);
}

TEST(SolveDiophantine, ZeroOne) {
  // 0x + 2y = 8
  pair<int, int> sol = SolveDiophantine(0, 2, 8);
  EXPECT_EQ(sol.first * 0 + sol.second * 2, 8);
}

TEST(SolveDiophantine, ZeroTwo) {
  // x + 2y = 0
  pair<int, int> sol = SolveDiophantine(1, 2, 0);
  EXPECT_EQ(sol.first * 1 + sol.second * 2, 0);
}

