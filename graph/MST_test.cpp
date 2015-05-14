#include "gtest/gtest.h"
#include "MST.h"

TEST(Kruskal, Test1) {
  Kruskal sol;
  sol.n = 4;
  sol.m = 5;
  int weights[] = {1, 2, 3, 4, 1};
  int heads[] = {0, 1, 2, 3, 0};
  int tails[] = {1, 2, 3, 0, 2};
  memcpy(sol.w, weights, sizeof weights);
  memcpy(sol.u, heads, sizeof heads);
  memcpy(sol.v, tails, sizeof tails);
  EXPECT_EQ(5, sol.kruskal());
}

TEST(Kruskal, Test2) {
  Kruskal sol;
  sol.n = 4;
  sol.m = 5;
  int weights[] = {1, 2, 3, 4, 4};
  int heads[] = {0, 1, 2, 3, 0};
  int tails[] = {1, 2, 3, 0, 2};
  memcpy(sol.w, weights, sizeof weights);
  memcpy(sol.u, heads, sizeof heads);
  memcpy(sol.v, tails, sizeof tails);
  EXPECT_EQ(6, sol.kruskal());
}

TEST(Kruskal, Test3) {
  Kruskal sol;
  sol.n = 4;
  sol.m = 5;
  int weights[] = {1, 2, 3, 4, 1};
  int heads[] = {0, 1, 2, 3, 3};
  int tails[] = {1, 2, 3, 0, 0};
  memcpy(sol.w, weights, sizeof weights);
  memcpy(sol.u, heads, sizeof heads);
  memcpy(sol.v, tails, sizeof tails);
  EXPECT_EQ(4, sol.kruskal());
}
