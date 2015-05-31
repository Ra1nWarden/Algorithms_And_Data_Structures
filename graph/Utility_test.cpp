#include "gtest/gtest.h"
#include "Utility.h"
#include <algorithm>

using namespace std;

TEST(Toposort, Test1) {
  Toposort test(5);
  test.adjMat[1][2] = true;
  test.adjMat[1][3] = true;
  test.adjMat[2][3] = true;
  test.adjMat[3][4] = true;
  test.adjMat[2][5] = true;
  ASSERT_TRUE(test.toposort());
  // checker
  int ranks[6];
  for(int i = 0; i < 5; i++) {
    ranks[test.toposorted[i]] = i;
  }
  EXPECT_TRUE(ranks[1] < ranks[2]);
  EXPECT_TRUE(ranks[1] < ranks[3]);
  EXPECT_TRUE(ranks[2] < ranks[3]);
  EXPECT_TRUE(ranks[3] < ranks[4]);
  EXPECT_TRUE(ranks[2] < ranks[5]);
}

TEST(Toposort, Test2) {
  Toposort test(5);
  test.adjMat[1][2] = true;
  test.adjMat[1][3] = true;
  test.adjMat[4][5] = true;
  ASSERT_TRUE(test.toposort());
  // checker
  int ranks[6];
  for(int i = 0; i < 5; i++) {
    ranks[test.toposorted[i]] = i;
  }
  EXPECT_TRUE(ranks[1] < ranks[2]);
  EXPECT_TRUE(ranks[1] < ranks[3]);
  EXPECT_TRUE(ranks[4] < ranks[5]);
}

TEST(Toposort, Test3) {
  Toposort test(5);
  test.adjMat[1][2] = true;
  test.adjMat[1][3] = true;
  test.adjMat[4][5] = true;
  test.adjMat[5][3] = true;
  ASSERT_TRUE(test.toposort());
  // checker
  int ranks[6];
  for(int i = 0; i < 5; i++) {
    ranks[test.toposorted[i]] = i;
  }
  EXPECT_TRUE(ranks[1] < ranks[2]);
  EXPECT_TRUE(ranks[1] < ranks[3]);
  EXPECT_TRUE(ranks[4] < ranks[5]);
  EXPECT_TRUE(ranks[5] < ranks[3]);
}

TEST(Toposort, CycleDetection1) {
  Toposort test(5);
  test.adjMat[1][2] = true;
  test.adjMat[2][3] = true;
  test.adjMat[3][1] = true;
  EXPECT_FALSE(test.toposort());
}

TEST(Toposort, CycleDetection2) {
  Toposort test(5);
  test.adjMat[1][2] = true;
  test.adjMat[2][3] = true;
  test.adjMat[3][4] = true;
  test.adjMat[4][5] = true;
  test.adjMat[5][2] = true;
  EXPECT_FALSE(test.toposort());
}

TEST(Euler, DirectedEulerPositive) {
  Euler test(5);
  test.adjList[1].push_back(2);
  test.adjList[2].push_back(3);
  test.adjList[3].push_back(4);
  test.adjList[4].push_back(5);
  test.adjList[5].push_back(2);
  EXPECT_TRUE(test.isEulerDirected());
}

TEST(Euler, DirectedEulerNegative) {
  Euler test(5);
  test.adjList[1].push_back(2);
  test.adjList[2].push_back(3);
  test.adjList[3].push_back(4);
  test.adjList[3].push_back(5);
  test.adjList[4].push_back(5);
  test.adjList[5].push_back(2);
  EXPECT_FALSE(test.isEulerDirected());
}

TEST(Euler, UndirectedEulerPositive) {
  Euler test(5);
  test.adjMat[1][2] = test.adjMat[2][1] = true;
  test.adjMat[2][3] = test.adjMat[3][2] = true;
  test.adjMat[3][4] = test.adjMat[4][3] = true;
  test.adjMat[2][4] = test.adjMat[4][2] = true;
  test.adjMat[2][5] = test.adjMat[5][2] = true;
  EXPECT_TRUE(test.isEulerUndirected());
}

TEST(Euler, UndirectedEulerNegative) {
  Euler test(5);
  test.adjMat[1][2] = test.adjMat[2][1] = true;
  test.adjMat[2][3] = test.adjMat[3][2] = true;
  test.adjMat[3][4] = test.adjMat[4][3] = true;
  test.adjMat[2][4] = test.adjMat[4][2] = true;
  EXPECT_FALSE(test.isEulerUndirected());
}

TEST(TransitiveClosure, PositiveTest) {
  TransitiveClosure test;
  test.init(5);
  test.addEdge(1, 0);
  test.addEdge(0, 3);
  test.addEdge(3, 2);
  test.transitiveClosure();
  EXPECT_TRUE(test.d[1][2]);
  EXPECT_TRUE(test.d[0][2]);
}

TEST(TransitiveClosure, NegativeTest) {
  TransitiveClosure test;
  test.init(5);
  test.addEdge(1, 0);
  test.addEdge(0, 3);
  test.addEdge(3, 2);
  test.addEdge(4, 2);
  test.transitiveClosure();
  EXPECT_FALSE(test.d[4][0]);
  EXPECT_FALSE(test.d[3][4]);
  EXPECT_FALSE(test.d[0][1]);
}

TEST(BipartiteTest, PositiveTestSingleComponent) {
  Bipartite test(4);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 3);
  EXPECT_TRUE(test.isBipartite(2));
}

TEST(BipartiteTest, PositiveTestMultipleComponent) {
  Bipartite test(6);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(3, 4);
  test.addEdge(4, 5);
  EXPECT_TRUE(test.isBipartite(1));
  EXPECT_TRUE(test.isBipartite(4));
}

TEST(BipartiteTest, NegativeTest) {
  Bipartite test(3);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(0, 2);
  EXPECT_FALSE(test.isBipartite(1));
}
