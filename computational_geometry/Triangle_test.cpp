#include "gtest/gtest.h"
#include "Triangle.h"

const Point p1(0, 0);
const Point p2(0, 4);
const Point p3(3, 0);
const Point p4(0, 3);

void doubleEQ(double x, double y) {
  EXPECT_EQ(0, sgn(x - y));
}

TEST(Triangle, AreaHeron) {
  doubleEQ(AreaHeron(3, 4, 5), 6);
}

TEST(Triangle, AreaPoint1) {
  doubleEQ(AreaPoint(p1, p2, p3), 6);
}

TEST(Triangle, AreaPoint2) {
  doubleEQ(AreaPoint(p1, p3, p4), 4.5);
}

TEST(Triangle, InnerRadius) {
  doubleEQ(InnerRadius(AreaPoint(p1, p2, p3), 12), 1);
}

TEST(Triangle, OuterRadius) {
  doubleEQ(OuterRadius(AreaPoint(p1, p3, p4), 3, 3, 3 * sqrt(2)), 1.5 * sqrt(2));
}

TEST(Triangle, OuterCircleCenter) {
  Point o = OuterCircleCenter(p1, p3, p4);
  doubleEQ(o.x, 1.5);
  doubleEQ(o.y, 1.5);
}

TEST(Triangle, CosineRule1) {
  doubleEQ(CosineRule(3, 4, PI / 2), 5);
}

TEST(Triangle, CosineRule2) {
  doubleEQ(CosineRule(3, 3, PI / 3), 3);
}

TEST(Triangle, SineRule1) {
  doubleEQ(SineRule(12, PI / 2, PI / 6), 6);
}

TEST(Triangle, SineRule2) {
  doubleEQ(SineRule(2 * sqrt(2), PI / 2, PI / 4), 2);
}

TEST(Triangle, TriangleContainsPointInside) {
  EXPECT_EQ(1, TriangleContainsPoint(p1, p2, p3, Point(1, 2)));
  EXPECT_EQ(1, TriangleContainsPoint(p1, p3, p4, Point(1, 1))); 
}

TEST(Triangle, TriangleContainsPointOnTheSide) {
  EXPECT_EQ(0, TriangleContainsPoint(p1, p2, p3, Point(1.5, 2)));
  EXPECT_EQ(0, TriangleContainsPoint(p1, p3, p4, Point(1, 2)));
}

TEST(Triangle, TriangleContainsPointOutside) {
  EXPECT_EQ(-1, TriangleContainsPoint(p1, p2, p3, Point(4, 4)));
  EXPECT_EQ(-1, TriangleContainsPoint(p1, p3, p4, Point(2, 2)));
}


