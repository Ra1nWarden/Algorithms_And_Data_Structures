#include "gtest/gtest.h"
#include "PermutationAndCombination.h"

TEST(Factorial, Zero) {
  EXPECT_EQ(1, Factorial(0));
}

TEST(Factorial, One) {
  EXPECT_EQ(1, Factorial(1));
}

TEST(Factorial, Five) {
  EXPECT_EQ(120, Factorial(5));
}

TEST(Permutation, ZeroPZero) {
  EXPECT_EQ(1, Perm(0, 0));
}

TEST(Permutation, OnePZero) {
  EXPECT_EQ(1, Perm(1, 0));
}

TEST(Permutation, OnePOne) {
  EXPECT_EQ(1, Perm(1, 1));
}

TEST(Permutation, TenPOne) {
  EXPECT_EQ(10, Perm(10, 1));
}

TEST(Permutation, FivePermThree) {
  EXPECT_EQ(60, Perm(5, 3));
}

TEST(Combination, ZeroCZero) {
  EXPECT_EQ(1, Combi(0, 0));
}

TEST(Combination, OneCZero) {
  EXPECT_EQ(1, Combi(1, 0));
}

TEST(Combination, OneCTwo) {
  EXPECT_EQ(0, Combi(1, 2));
}

TEST(Combination, TwoCTwo) {
  EXPECT_EQ(1, Combi(2, 2));
}

TEST(Combination, FiveCTwo) {
  EXPECT_EQ(10, Combi(5, 2));
}

TEST(Catalan, Zero) {
  EXPECT_EQ(1, Catalan(0));
  EXPECT_EQ(1, CatalanR(0));
}

TEST(Catalan, One) {
  EXPECT_EQ(1, Catalan(1));
  EXPECT_EQ(1, CatalanR(1));
}

TEST(Catalan, Twelve) {
  EXPECT_EQ(208012, Catalan(12));
  EXPECT_EQ(208012, CatalanR(12));
}

TEST(Derangement, Zero) {
  EXPECT_EQ(1, Derangement(0));
}

TEST(Derangement, One) {
  EXPECT_EQ(0, Derangement(1));
}

TEST(Derangement, Ten) {
  EXPECT_EQ(1334961, Derangement(10));
}
