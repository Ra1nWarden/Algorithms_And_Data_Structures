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
  sol.n = 2;
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
  sol.n = 3;
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
  sol.n = 3;
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
  sol.n = 2;
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
  sol.n = 2;
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
  sol.n = 3;
  EXPECT_FALSE(sol.Gauss());
}

TEST(GaussElimination, GaussJordanPositiveOne) {
  GaussElimination sol;
  double mat[2][2] = {{1, 1}, {2, 4}};;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[2] = {5, 16};
  for(int i = 0; i < 2; i++)
    sol.x[i] = rhs[i];
  sol.n = 2;
  sol.GaussJordan();
  EXPECT_TRUE(fabs(sol.x[0] / sol.matrix[0][0] - 2) < eps);
  EXPECT_TRUE(fabs(sol.x[1] / sol.matrix[1][1] - 3) < eps);
}

TEST(GaussElimination, GaussJordanPositiveTwo) {
  GaussElimination sol;
  double mat[3][3] = {{1, 1, 1}, {2, 4, 3}, {2, 2, 5}};
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      sol.matrix[i][j] = mat[i][j];
  double rhs[3] = {9, 28, 30};
  for(int i = 0; i < 3; i++)
    sol.x[i] = rhs[i];
  sol.n = 3;
  sol.GaussJordan();
  EXPECT_TRUE(fabs(sol.x[0] / sol.matrix[0][0] - 2) < eps);
  EXPECT_TRUE(fabs(sol.x[1] / sol.matrix[1][1] - 3) < eps);
  EXPECT_TRUE(fabs(sol.x[2] / sol.matrix[2][2] - 4) < eps);
}

TEST(SimpsonIntegral, TestOne) {
  SimpsonIntegral sol;
  double eps = 1e-6;
  EXPECT_TRUE(fabs(sol.asr(0, 1, eps) - (1.0 / 3)) < eps);
}

TEST(SimpsonIntegral, TestTwo) {
  SimpsonIntegral sol;
  double eps = 1e-5;
  EXPECT_TRUE(fabs(sol.asr(-1, 1, eps) - (2.0 / 3)) < eps);
}

TEST(SimpsonIntegral, TestThree) {
  SimpsonIntegral sol;
  double eps = 1e-4;
  EXPECT_TRUE(fabs(sol.asr(0, 0, eps) - 0) < eps);
}
