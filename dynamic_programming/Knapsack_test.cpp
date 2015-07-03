#include "Knapsack.h"
#include "gtest/gtest.h"

using namespace std;

TEST(ZeroOneKnapsack, Test1) {
  int weights[] = {7, 3, 5, 10};
  vector<int> weightv(weights, weights+4);
  int values[] = {9, 5, 3, 10};
  vector<int> valuev(values, values+4);
  Knapsack sol(8, weightv, valuev);
  EXPECT_EQ(9, sol.zeroOneKnapsack());
}

TEST(ZeroOneKnapsack, Test2) {
  int weights[] = {7, 3, 5, 10, 4, 8};
  vector<int> weightv(weights, weights+6);
  int values[] = {9, 5, 3, 10, 6, 9};
  vector<int> valuev(values, values+6);
  Knapsack sol(12, weightv, valuev);
  EXPECT_EQ(15, sol.zeroOneKnapsack());
}

TEST(CompleteKnapsack, Test1) {
  int weights[] = {7, 3, 5, 10};
  vector<int> weightv(weights, weights+4);
  int values[] = {9, 5, 3, 10};
  vector<int> valuev(values, values+4);
  Knapsack sol(10, weightv, valuev);
  EXPECT_EQ(15, sol.completeKnapsack());
}

TEST(CompleteKnapsack, Test2) {
  int weights[] = {7, 3, 5, 10, 4, 8};
  vector<int> weightv(weights, weights+6);
  int values[] = {9, 5, 3, 10, 6, 9};
  vector<int> valuev(values, values+6);
  Knapsack sol(20, weightv, valuev);
  EXPECT_EQ(32, sol.completeKnapsack());
}

TEST(MultipleKnapsack, Test1) {
  int weights[] = {7, 3, 5, 10};
  vector<int> weightv(weights, weights+4);
  int values[] = {9, 5, 3, 10};
  vector<int> valuev(values, values+4);
  int counts[] = {3, 2, 3, 1};
  vector<int> countv(counts, counts+4);
  Knapsack sol(10, weightv, valuev, countv);
  EXPECT_EQ(14, sol.multipleKnapsack());
}

TEST(MultipleKnapsack, Test2) {
  int weights[] = {7, 3, 5, 10, 4, 8};
  vector<int> weightv(weights, weights+6);
  int values[] = {9, 5, 3, 10, 6, 9};
  vector<int> valuev(values, values+6);
  int counts[] = {3, 5, 2, 1, 4, 2};
  vector<int> countv(counts, counts+6);
  Knapsack sol(20, weightv, valuev, countv);
  EXPECT_EQ(32, sol.multipleKnapsack());
}

TEST(MultipleFeasibility, Test1) {
  int weights[] = {7, 3, 5, 10};
  vector<int> weightv(weights, weights+4);
  int values[] = {9, 5, 3, 10};
  vector<int> valuev(values, values+4);
  int counts[] = {3, 2, 3, 1};
  vector<int> countv(counts, counts+4);
  Knapsack sol(10, weightv, valuev, countv);
  EXPECT_FALSE(sol.feasibleKnapsack(11));
}

TEST(MultipleFeasibility, Test2) {
  int weights[] = {7, 3, 5, 10, 4, 8};
  vector<int> weightv(weights, weights+6);
  int values[] = {9, 5, 3, 10, 6, 9};
  vector<int> valuev(values, values+6);
  int counts[] = {3, 5, 2, 1, 4, 2};
  vector<int> countv(counts, counts+6);
  Knapsack sol(20, weightv, valuev, countv);
  EXPECT_TRUE(sol.feasibleKnapsack(19));
}
