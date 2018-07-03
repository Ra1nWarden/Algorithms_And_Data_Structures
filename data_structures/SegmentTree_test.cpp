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

TEST(SegmentTree, QueryPoint) {
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

TEST(SegmentTree, RangeAddQueryOne) {
  setupTree();
  seg.add_range(1, 0, 2, 3);
  EXPECT_EQ(2, seg.query(1, 0, 2, 0));
  seg.add_range(1, 2, 4, -1);
  EXPECT_EQ(-1, seg.query(1, 1, 4, 0));
  seg.add_range(1, 4, 6, -3);
  EXPECT_EQ(-5, seg.query(1, 0, 6, 0));
}

TEST(SegmentTree, RangeAddQueryTwo) {
  setupTree();
  seg.add_range(1, 0, 2, -3);
  EXPECT_EQ(-4, seg.query(1, 0, 2, 0));
  seg.add_range(1, 2, 4, 1);
  EXPECT_EQ(-1, seg.query(1, 1, 4, 0));
  seg.add_range(1, 4, 6, 1);
  EXPECT_EQ(-4, seg.query(1, 0, 6, 0));
}

TEST(SegmentTree, RangeAddQueryThree) {
  setupTree();
  seg.add_range(1, 0, 0, -1);
  seg.add_range(1, 1, 3, -2);
  seg.add_range(1, 0, 2, 1);
  EXPECT_EQ(-2, seg.query(1, 0, 3, 0));
}

SegmentTree seg2;
int v2[] = {4, 2, 1, 0, 3, 2, 1};
int n2 = 7;

void setupTree2() {
  seg2.build(1, 0, n2 - 1);
  for(int i = 0; i < n2; i++) {
    seg2.update(1, i, v2[i]);
  }
}

TEST(SegmentTree, RangeUpdateQueryOne) {
  setupTree2();
  seg2.update_range(1, 0, 2, 3);
  EXPECT_EQ(3, seg2.update_range_query(1, 0, 2));
  seg2.update_range(1, 2, 4, 1);
  EXPECT_EQ(1, seg2.update_range_query(1, 1, 4));
  seg2.update_range(1, 4, 6, 0);
  EXPECT_EQ(0, seg2.update_range_query(1, 0, 6));
}

TEST(SegmentTree, RangeUpdateQueryTwo) {
  setupTree2();
  seg2.update_range(1, 1, 2, 2);
  EXPECT_EQ(2, seg2.update_range_query(1, 0, 2));
  seg2.update_range(1, 2, 4, 1);
  EXPECT_EQ(1, seg2.update_range_query(1, 1, 4));
  seg2.update_range(1, 3, 6, 0);
  EXPECT_EQ(0, seg2.update_range_query(1, 0, 6));
}

TEST(SegmentTree, RangeUpdateQueryThree) {
  setupTree2();
  seg2.update_range(1, 0, 0, 4);
  seg2.update_range(1, 1, 2, 1);
  seg2.update_range(1, 0, 2, 2);
  EXPECT_EQ(0, seg2.update_range_query(1, 0, 3));
}

TEST(SegmentTree, RangeUpdateQueryFour) {
  setupTree2();
  seg2.update_range(1, 0, 6, 4);
  EXPECT_EQ(4, seg2.update_range_query(1, 0, 6));
  seg2.update_range(1, 1, 5, 2);
  EXPECT_EQ(2, seg2.update_range_query(1, 0, 6));
  seg2.update_range(1, 0, 6, 0);
  EXPECT_EQ(0, seg2.update_range_query(1, 0, 6));
  seg2.update_range(1, 4, 6, 2);
  EXPECT_EQ(0, seg2.update_range_query(1, 0, 6));
  seg2.update_range(1, 0, 3, 1);
  EXPECT_EQ(1, seg2.update_range_query(1, 0, 6));
}

