#include "gtest/gtest.h"
#include "Point.h"

const Point p1(1.5, 2.5);
const Point p2(0, 4);
const Point p3(3, 4);
const Point p4(6, 4);

void doubleEq(double x, double y) {
  EXPECT_EQ(0, sgn(x - y));
}

TEST(Point, PointAdditionInteger) {
  Point p4 = p2 + p3;
  doubleEq(3, p4.x);
  doubleEq(8, p4.y);
}

TEST(Point, PointAdditionDecimal) {
  Point p4 = p1 + p3;
  doubleEq(4.5, p4.x);
  doubleEq(6.5, p4.y);
}

TEST(Point, PointSubtractionInteger) {
  Point p4 = p2 - p3;
  doubleEq(-3, p4.x);
  doubleEq(0, p4.y);
}

TEST(Point, PointSubtractionDecimal) {
  Point p4 = p1 - p3;
  doubleEq(-1.5, p4.x);
  doubleEq(-1.5, p4.y);
}

TEST(Point, PointMultiplication) {
  Point p4 = p1 * 2;
  doubleEq(3, p4.x);
  doubleEq(5, p4.y);
}

TEST(Point, PointDivision) {
  Point p4 = p1 / 0.5;
  doubleEq(3, p4.x);
  doubleEq(5, p4.y);
}

TEST(Point, CrossProduct) {
  double crs = p1 ^ p2;
  doubleEq(6, crs);
}

TEST(Point, DotProduct) {
  double dot = p1 * p3;
  doubleEq(14.5, dot);
}

TEST(Point, OperatorLessThan) {
  EXPECT_TRUE(p2 < p1);
  Point p4(3, 3.5);
  EXPECT_TRUE(p4 < p3);
}

TEST(Point, OperatorEquals) {
  Point p4(1.5, 2.5);
  EXPECT_TRUE(p1 == p4);
}

TEST(Point, TransXY) {
  Point p4(p3);
  p4.transXY(PI / 2);
  doubleEq(-4, p4.x);
  doubleEq(3, p4.y);
}

TEST(Point, Distance) {
  doubleEq(5, dist(p3));
}

TEST(Point, Normal) {
  Point p4 = normal(p3);
  doubleEq(1.0, dist(p4));
  double k1 = p3.y / p3.x;
  double k2 = p4.y / p4.x;
  doubleEq(-1, k1 * k2);
}

TEST(Point, LeftTurn) {
  EXPECT_EQ(1, turn(p2, p1, p3));
}

TEST(Point, RightTurn) {
  EXPECT_EQ(-1, turn(p3, p1, p2));
}

TEST(Point, Collinear) {
  EXPECT_EQ(0, turn(p2, p3, p4));
  EXPECT_EQ(0, turn(p2, p4, p3));
  EXPECT_EQ(0, turn(p3, p2, p4));
}
