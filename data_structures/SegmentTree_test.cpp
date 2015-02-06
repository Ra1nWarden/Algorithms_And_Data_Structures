#include "gtest/gtest.h"
#include "SegmentTree.h"

using namespace std;

SegmentTree seg;
int v[] = {-1, 2, 1, 0, 3, -2, 1};
int n = 7;

void setupTree() {
  seg.build(1, 0, n - 1);
  for(int i = 0; i < n; i++) {
    seg.update(1, i, v[i]);
  }
}

TEST(SegmentTree, QueryPoint){
  setupTree();
  for(int i = 0; i < n; i++) {
    EXPECT_EQ(v[i], seg.query(1, i, i));
  }
}

TEST(SegmentTree, QueryRange) {
  setupTree();
  EXPECT_EQ(-1, seg.query(1, 0, 1));
  EXPECT_EQ(-1, seg.query(1, 0, 3));
  EXPECT_EQ(-2, seg.query(1, 0, 5));
  EXPECT_EQ(0, seg.query(1, 1, 3));
  EXPECT_EQ(1, seg.query(1, 1, 2));
}

TEST(SegmentTree, UpdateQuery) {
  setupTree();
  seg.update(1, 0, 3);
  EXPECT_EQ(1, seg.query(1, 0, 2));
  seg.update(1, 2, -1);
  EXPECT_EQ(-1, seg.query(1, 1, 4));
  seg.update(1, 4, -3);
  EXPECT_EQ(-3, seg.query(1, 0, 6));
}
