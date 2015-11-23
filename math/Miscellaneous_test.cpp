#include "gtest/gtest.h"
#include "Miscellaneous.h"
#include <cmath>

using namespace std;

int f0(int x) {
  return 1;
}

// 1 -> 2 -> 3 -> 4 -> 5 -> 3 -> 4 -> 5 ...
int f1(int x) {
  if(x < 5)
    return x + 1;
  else
    return 3;
}

TEST(FloydCycle, ConstantOne) {
  pair<int, int> result = FloydCycleFinding(f0, 1);
  EXPECT_EQ(make_pair(0, 1), result);
}

TEST(FloydCycle, ConstantZero) {
  pair<int, int> result = FloydCycleFinding(f0, 0);
  EXPECT_EQ(make_pair(1, 1), result);
}

TEST(FloydCycle, IncreaseOne) {
  pair<int, int> result = FloydCycleFinding(f0, 1);
  EXPECT_EQ(make_pair(0, 1), result);
}

TEST(FloydCycle, IncreaseTwo) {
  pair<int, int> result = FloydCycleFinding(f1, 1);
  EXPECT_EQ(make_pair(2, 3), result);
}

TEST(GaussElimination, PositiveTestOne) {
  GaussElimination sol;
  double mat[2][2] = {{1, 1}, {2, 4}};;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[2] = {5, 16};
  for(int i = 0; i < 2; i++)
    sol.x[i] = rhs[i];
  sol.equ = 2;
  sol.var = 2;
  EXPECT_TRUE(sol.Gauss());
  EXPECT_TRUE(fabs(sol.x[0] - 2) < eps);
  EXPECT_TRUE(fabs(sol.x[1] - 3) < eps);
}

TEST(GaussElimination, PositiveTestTwo) {
  GaussElimination sol;
  double mat[3][3] = {{1, 1, 1}, {2, 4, 3}, {2, 2, 5}};
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[3] = {9, 28, 30};
  for(int i = 0; i < 3; i++)
    sol.x[i] = rhs[i];
  sol.equ = 3;
  sol.var = 3;
  EXPECT_TRUE(sol.Gauss());
  EXPECT_TRUE(fabs(sol.x[0] - 2) < eps);
  EXPECT_TRUE(fabs(sol.x[1] - 3) < eps);
  EXPECT_TRUE(fabs(sol.x[2] - 4) < eps);
}

TEST(GaussElimination, PositiveTestThree) {
  GaussElimination sol;
  double mat[3][3] = {{1, 1, 1}, {2, 4, 3}, {2, 2, 5}};
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[3] = {9, 26, 24};
  for(int i = 0; i < 3; i++)
    sol.x[i] = rhs[i];
  sol.equ = 3;
  sol.var = 3;
  EXPECT_TRUE(sol.Gauss());
  EXPECT_TRUE(fabs(sol.x[0] - 4) < eps);
  EXPECT_TRUE(fabs(sol.x[1] - 3) < eps);
  EXPECT_TRUE(fabs(sol.x[2] - 2) < eps);
}

TEST(GaussElimination, NegativeTestOne) {
  GaussElimination sol;
  double mat[2][2] = {{1, 2}, {2, 4}};
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[2] = {4, 8};
  for(int i = 0; i < 2; i++)
    sol.x[i] = rhs[i];
  sol.equ = 2;
  sol.var = 2;
  EXPECT_FALSE(sol.Gauss());
}

TEST(GaussElimination, NegativeTestTwo) {
  GaussElimination sol;
  double mat[2][2] = {{1, 2}, {0, 0}};
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[2] = {4, 0};
  for(int i = 0; i < 2; i++)
    sol.x[i] = rhs[i];
  sol.equ = 2;
  sol.var = 2;
  EXPECT_FALSE(sol.Gauss());
}

TEST(GaussElimination, NegativeTestThree) {
  GaussElimination sol;
  double mat[3][3] = {{1, 2, 3}, {2, 4, 6}, {1, 1, 1}};
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[3] = {1, 3, 4};
  for(int i = 0; i < 3; i++)
    sol.x[i] = rhs[i];
  sol.equ = 3;
  sol.var = 3;
  EXPECT_FALSE(sol.Gauss());
}


