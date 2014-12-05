#include "gtest/gtest.h"
#include "PermutationAndCombination.h"

TEST(Factorial, Zero) {
  EXPECT_EQ(Factorial(0), 1);
}

TEST(Factorial, One) {
  EXPECT_EQ(Factorial(1), 1);
}

TEST(Factorial, Five) {
  EXPECT_EQ(Factorial(5), 120);
}

TEST(Permutation, ZeroPZero) {
  EXPECT_EQ(Perm(0, 0), 1);
}

TEST(Permutation, OnePZero) {
  EXPECT_EQ(Perm(1, 0), 1);
}

TEST(Permutation, OnePOne) {
  EXPECT_EQ(Perm(1, 1), 1);
}

TEST(Permutation, TenPOne) {
  EXPECT_EQ(Perm(10, 1), 10);
}

TEST(Permutation, FivePermThree) {
  EXPECT_EQ(Perm(5, 3), 60);
}

TEST(Combination, ZeroCZero) {
  EXPECT_EQ(Combi(0, 0), 1);
}

TEST(Combination, OneCZero) {
  EXPECT_EQ(Combi(1, 0), 1);
}

TEST(Combination, OneCTwo) {
  EXPECT_EQ(Combi(1, 2), 0);
}

TEST(Combination, TwoCTwo) {
  EXPECT_EQ(Combi(2, 2), 1);
}

TEST(Combination, FiveCTwo) {
  EXPECT_EQ(Combi(5, 2), 10);
}

TEST(Catalan, Zero) {
  EXPECT_EQ(Catalan(0), 1);
  EXPECT_EQ(CatalanR(0), 1);
}

TEST(Catalan, One) {
  EXPECT_EQ(Catalan(1), 1);
  EXPECT_EQ(CatalanR(1), 1);
}

TEST(Catalan, Twelve) {
  EXPECT_EQ(Catalan(12), 208012);
  EXPECT_EQ(CatalanR(12), 208012);
}

TEST(Derangement, Zero) {
  EXPECT_EQ(Derangement(0), 1);
}

TEST(Derangement, One) {
  EXPECT_EQ(Derangement(1), 0);
}

TEST(Derangement, Ten) {
  EXPECT_EQ(Derangement(10), 1334961);
}
