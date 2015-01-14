#include "gtest/gtest.h"
#include "Line.h"
#include "Point.h"

const Line l1(Point(-1, -1), Point(1, 1));
const Line l2(Point(0, 1), Point(1, 2));
const Line l3(Point(-1, 1), Point(1, -1));

void doubleEq(double x, double y) {
  EXPECT_EQ(0, sgn(x - y));
}

TEST(Line, IntersectOverlap) {
  const Line l4(Point(2, 2), Point(3, 3));
  pair<int, Point> res = l1 & l4;
  EXPECT_EQ(0, res.first);
}

TEST(Line, IntersectParallel) {
  pair<int, Point> res = l1 & l2;
  EXPECT_EQ(1, res.first);
}

TEST(Line, IntersectCross) {
  pair<int, Point> res = l1 & l3;
  EXPECT_EQ(2, res.first);
  doubleEq(0, res.second.x);
  doubleEq(0, res.second.y);
}

TEST(Line, SegIntersectSegPositive) {
  EXPECT_TRUE(SegIntersectSeg(l1, l3));
}

TEST(Line, SegIntersectSegNegative) {
  EXPECT_FALSE(SegIntersectSeg(l1, l2));
}

TEST(Line, LineIntersectSegPositive) {
  Line l4(Point(-10, 10), Point(10, -10));
  EXPECT_TRUE(LineIntersectSeg(l2, l4));
}

TEST(Line, LineIntersectSegNegative) {
  EXPECT_FALSE(LineIntersectSeg(l1, l2));
}

TEST(Line, PointOnSegPositive) {
  EXPECT_TRUE(PointOnSeg(Point(0, 0), l1));
}

TEST(Line, PointOnSegNegative) {
  EXPECT_FALSE(PointOnSeg(Point(2, 2), l1));
}

TEST(Line, PointOnLinePositive) {
  EXPECT_TRUE(PointOnLine(Point(2, 2), l1));
}

TEST(Line, PointOnLineNegative) {
  EXPECT_FALSE(PointOnLine(Point(0, 1), l1));
}

TEST(Line, PointToLine) {
  Point p(0, 4);
  Point intersect = PointToLine(p, l1);
  doubleEq(2, intersect.x);
  doubleEq(2, intersect.y);
}

TEST(Line, PointToSeg) {
  Point p(0, 4);
  Point intersect = PointToSeg(p, l1);
  doubleEq(1, intersect.x);
  doubleEq(1, intersect.y);
}

TEST(Line, DistanceToLine) {
  Point p(0, 4);
  doubleEq(2 * sqrt(2), DistanceToLine(p, l1));
}

TEST(Line, DistanceToSeg) {
  Point p(0, 4);
  doubleEq(sqrt(10), DistanceToSeg(p, l1));
}
