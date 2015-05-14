#include "gtest/gtest.h"
#include "ShortestPath.h"

TEST(Dijkstra, DirectedDistanceTest) {
  Dijkstra sol;
  sol.init(5);
  sol.addEdge(0, 1, 10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, 5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(0, 4, 5);
  sol.dijkstra(0);
  int distances[] = {0, 10, 15, 25, 5};
  for(int i = 0; i < 5; i++)
    EXPECT_EQ(distances[i], sol.d[i]);
}

TEST(Dijkstra, UndirectedDistanceTest) {
  Dijkstra sol;
  sol.init(5);
  sol.addEdge(0, 1, 10);
  sol.addEdge(1, 0, 10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 0, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(4, 2, 5);
  sol.addEdge(1, 2, 5);
  sol.addEdge(2, 1, 5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 2, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(4, 3, 20);
  sol.addEdge(0, 4, 5);
  sol.addEdge(4, 0, 5);
  sol.dijkstra(0);
  int distances[] = {0, 10, 10, 20, 5};
  for(int i = 0; i < 5; i++)
    EXPECT_EQ(distances[i], sol.d[i]);
}

TEST(Dijkstra, PathTest1) {
  Dijkstra sol;
  sol.init(5);
  sol.addEdge(0, 1, 10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, 5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(0, 4, 5);
  vector<int> path;
  int ans = sol.dijkstra(0, 3, path);
  ASSERT_EQ(25, ans);
  int expected[] = {0, 1, 2, 3};
  ASSERT_EQ(4, path.size());
  for(int i = 0; i < 4; i++)
    EXPECT_EQ(expected[i], path[i]);
}

TEST(Dijkstra, PathTest2) {
  Dijkstra sol;
  sol.init(5);
  sol.addEdge(0, 1, 10);
  sol.addEdge(1, 0, 10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 0, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(4, 2, 5);
  sol.addEdge(1, 2, 5);
  sol.addEdge(2, 1, 5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 2, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(4, 3, 20);
  sol.addEdge(0, 4, 5);
  sol.addEdge(4, 0, 5);
  vector<int> path;
  int ans = sol.dijkstra(0, 3, path);
  ASSERT_EQ(20, ans);
  int expected[] = {0, 4, 2, 3};
  ASSERT_EQ(4, path.size());
  for(int i = 0; i < 4; i++)
    EXPECT_EQ(expected[i], path[i]);
}

TEST(BellmanFord, DistanceTest1) {
  BellmanFord sol;
  sol.init(5);
  sol.addEdge(0, 1, 20);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, -5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(0, 4, -5);
  ASSERT_TRUE(sol.bellmanFord(0));
  int distances[] = {0, 20, 15, 25, -5};
  for(int i = 0; i < 5; i++)
    EXPECT_EQ(distances[i], sol.d[i]);
}

TEST(BellmanFord, DistanceTest2) {
  BellmanFord sol;
  sol.init(5);
  sol.addEdge(0, 1, -10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, 20);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, -5);
  sol.addEdge(0, 4, 20);
  ASSERT_TRUE(sol.bellmanFord(0));
  int distances[] = {0, -10, 10, 20, 15};
  for(int i = 0; i < 5; i++)
    EXPECT_EQ(distances[i], sol.d[i]);
}

TEST(BellmanFord, NegativeTest) {
  BellmanFord sol;
  sol.init(5);
  sol.addEdge(0, 1, 20);
  sol.addEdge(0, 2, -10);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, -5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(4, 0, -5);
  EXPECT_FALSE(sol.bellmanFord(0));
}

TEST(BellmanFord, PathTest1) {
  BellmanFord sol;
  sol.init(5);
  sol.addEdge(0, 1, 20);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, -5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(0, 4, -5);
  vector<int> path;
  int dist;
  ASSERT_TRUE(sol.bellmanFord(0, 2, dist, path));
  ASSERT_EQ(3, path.size());
  ASSERT_EQ(15, dist);
  int expected[] = {0, 1, 2};
  for(int i = 0; i < 3; i++)
    EXPECT_EQ(expected[i], path[i]);
}

TEST(BellmanFord, PathTest2) {
  BellmanFord sol;
  sol.init(5);
  sol.addEdge(0, 1, -10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, 20);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, -5);
  sol.addEdge(0, 4, 20);
  vector<int> path;
  int dist;
  ASSERT_TRUE(sol.bellmanFord(0, 3, dist, path));
  ASSERT_EQ(4, path.size());
  ASSERT_EQ(20, dist);
  int expected[] = {0, 1, 2, 3};
  for(int i = 0; i < 4; i++)
    EXPECT_EQ(expected[i], path[i]);
}

TEST(SPFA, DistanceTest1) {
  SPFA sol;
  sol.init(5);
  sol.addEdge(0, 1, 20);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, -5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(0, 4, -5);
  ASSERT_TRUE(sol.spfa(0));
  int distances[] = {0, 20, 15, 25, -5};
  for(int i = 0; i < 5; i++)
    EXPECT_EQ(distances[i], sol.d[i]);
}

TEST(SPFA, DistanceTest2) {
  SPFA sol;
  sol.init(5);
  sol.addEdge(0, 1, -10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, 20);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, -5);
  sol.addEdge(0, 4, 20);
  ASSERT_TRUE(sol.spfa(0));
  int distances[] = {0, -10, 10, 20, 15};
  for(int i = 0; i < 5; i++)
    EXPECT_EQ(distances[i], sol.d[i]);
}

TEST(SPFA, NegativeTest) {
  SPFA sol;
  sol.init(5);
  sol.addEdge(0, 1, 20);
  sol.addEdge(0, 2, -10);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, -5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(4, 0, -5);
  EXPECT_FALSE(sol.spfa(0));
}

TEST(SPFA, PathTest1) {
  SPFA sol;
  sol.init(5);
  sol.addEdge(0, 1, 20);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, -5);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, 20);
  sol.addEdge(0, 4, -5);
  vector<int> path;
  int dist;
  ASSERT_TRUE(sol.spfa(0, 2, dist, path));
  ASSERT_EQ(3, path.size());
  ASSERT_EQ(15, dist);
  int expected[] = {0, 1, 2};
  for(int i = 0; i < 3; i++)
    EXPECT_EQ(expected[i], path[i]);
}

TEST(SPFA, PathTest2) {
  SPFA sol;
  sol.init(5);
  sol.addEdge(0, 1, -10);
  sol.addEdge(0, 2, 20);
  sol.addEdge(2, 4, 5);
  sol.addEdge(1, 2, 20);
  sol.addEdge(2, 3, 10);
  sol.addEdge(3, 4, -5);
  sol.addEdge(0, 4, 20);
  vector<int> path;
  int dist;
  ASSERT_TRUE(sol.spfa(0, 3, dist, path));
  ASSERT_EQ(4, path.size());
  ASSERT_EQ(20, dist);
  int expected[] = {0, 1, 2, 3};
  for(int i = 0; i < 4; i++)
    EXPECT_EQ(expected[i], path[i]);
}
