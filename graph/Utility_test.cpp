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

TEST(ArticulationPointAndBridge, TestOne) {
  ArticulationPointAndBridge test(5);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 3);
  test.addEdge(3, 4);
  EXPECT_FALSE(test.isCutPoint(0));
  EXPECT_FALSE(test.isCutPoint(4));
  for(int i = 1; i < 4; i++)
    EXPECT_TRUE(test.isCutPoint(i));
  for(int i = 0; i < test.edges.size(); i++)
    EXPECT_TRUE(test.isCutBridge(i));
}

TEST(ArticulationPointAndBridge, TestTwo) {
  ArticulationPointAndBridge test(5);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 3);
  test.addEdge(3, 4);
  test.addEdge(4, 0);
  for(int i = 0; i < 5; i++) {
    EXPECT_FALSE(test.isCutPoint(i));
  }
  for(int i = 0; i < test.edges.size(); i++) {
    EXPECT_FALSE(test.isCutBridge(i));
  }
}

TEST(ArticulationPointAndBridge, TestThree) {
  ArticulationPointAndBridge test(5);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 3);
  test.addEdge(3, 0);
  test.addEdge(0, 4);
  EXPECT_TRUE(test.isCutPoint(0));
  for(int i = 1; i < 5; i++) {
    EXPECT_FALSE(test.isCutPoint(i));
  }
  for(int i = 0; i < test.edges.size() - 2; i++) {
    EXPECT_FALSE(test.isCutBridge(i));
  }
  EXPECT_TRUE(test.isCutBridge(9));
  EXPECT_TRUE(test.isCutBridge(8));
}

TEST(ArticulationPointAndBridge, TestFour) {
  ArticulationPointAndBridge test(4);
  test.addEdge(0, 1);
  test.addEdge(0, 2);
  test.addEdge(0, 3);
  EXPECT_TRUE(test.isCutPoint(0));
  for(int i = 1; i < 4; i++)
    EXPECT_FALSE(test.isCutPoint(i));
  for(int i = 0; i < test.edges.size(); i++)
    EXPECT_TRUE(test.isCutBridge(i));
}

TEST(ArticulationPointAndBridge, TestFive) {
  ArticulationPointAndBridge test(5);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 3);
  test.addEdge(3, 4);
  test.addEdge(4, 2);
  for(int i = 0; i < 5; i++) {
    if(i == 1 || i == 2)
      EXPECT_TRUE(test.isCutPoint(i));
    else
      EXPECT_FALSE(test.isCutPoint(i));
  }
  for(int i = 0; i < test.edges.size(); i++) {
    if(i < 4)
      EXPECT_TRUE(test.isCutBridge(i));
    else
      EXPECT_FALSE(test.isCutBridge(i));
  }
}

TEST(Tarjan, SingleSCC) {
  Tarjan test(5);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 3);
  test.addEdge(3, 4);
  test.addEdge(4, 0);
  test.tarjan();
  EXPECT_EQ(1, test.scc_cnt);
}

TEST(Tarjan, NoSCC) {
  Tarjan test(5);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 3);
  test.addEdge(3, 4);
  test.tarjan();
  EXPECT_EQ(5, test.scc_cnt);
}

TEST(Tarjan, TwoSCC) {
  Tarjan test(5);
  test.addEdge(0, 1);
  test.addEdge(1, 2);
  test.addEdge(2, 0);
  test.addEdge(3, 4);
  test.addEdge(4, 3);
  test.tarjan();
  EXPECT_EQ(2, test.scc_cnt);
  for(int i = 0; i < 5; i++) {
    if(i < 3)
      EXPECT_EQ(1, test.sccno[i]);
    else
      EXPECT_EQ(2, test.sccno[i]);
  }
}

TEST(TreeDecomposition, Tree) {
  vector<int> zero{1, 2, 3};
  vector<int> one{0, 4};
  vector<int> two{0};
  vector<int> three{0, 5, 6};
  vector<int> four{1};
  vector<int> five{3};
  vector<int> six{3};
  vector<vector<int> > adj{zero, one, two, three, four, five, six};
  TreeDecomposition tree_decompose(adj);
  int fa[7] = {0, 0, 0, 0, 1, 3, 3};
  int depth[7] = {0, 1, 1, 1, 2, 2, 2};
  int size[7] = {7, 2, 1, 3, 1, 1, 1};
  int son[7] = {3, 4, -1, 5, -1, -1, -1};
  int top[7] = {0, 1, 2, 0, 1, 0, 6};
  int dfn[7] = {0, 4, 6, 1, 5, 2, 3};
  int rank[7] {0, 3, 5, 6, 1, 4, 2};
  for(int i = 0; i < 7; i++) {
    EXPECT_EQ(fa[i], tree_decompose.fa[i]);
    EXPECT_EQ(depth[i], tree_decompose.depth[i]);
    EXPECT_EQ(size[i], tree_decompose.size[i]);
    EXPECT_EQ(son[i], tree_decompose.son[i]);
    EXPECT_EQ(top[i], tree_decompose.top[i]);
    EXPECT_EQ(dfn[i], tree_decompose.dfn[i]);
    EXPECT_EQ(rank[i], tree_decompose.rank[i]);
  }
  // LCA
  EXPECT_EQ(3, tree_decompose.LCA(5, 6));
  EXPECT_EQ(0, tree_decompose.LCA(4, 6));
  EXPECT_EQ(0, tree_decompose.LCA(2, 1));
  EXPECT_EQ(0, tree_decompose.LCA(0, 1));
}
