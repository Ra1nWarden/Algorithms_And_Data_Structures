#include "gtest/gtest.h"
#include "MaximumFlow.h"

TEST(EdmondsKarp, Test1) {
  EdmondsKarp test;
  test.init(6);
  test.addEdge(0, 1, 16);
  test.addEdge(0, 2, 13);
  test.addEdge(1, 2, 10);
  test.addEdge(2, 1, 4);
  test.addEdge(1, 3, 12);
  test.addEdge(3, 2, 9);
  test.addEdge(2, 4, 14);
  test.addEdge(4, 3, 7);
  test.addEdge(3, 5, 20);
  test.addEdge(4, 5, 4);
  EXPECT_EQ(23, test.maxFlow(0, 5));
}

TEST(EdmondsKarp, Test2) {
  EdmondsKarp test;
  test.init(4);
  test.addEdge(0, 1, 10);
  test.addEdge(0, 2, 20);
  test.addEdge(1, 3, 5);
  test.addEdge(2, 3, 25);
  EXPECT_EQ(25, test.maxFlow(0, 3));
}
