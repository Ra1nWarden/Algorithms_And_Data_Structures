#include "gtest/gtest.h"
#include "Polygon.h"

using namespace std;

Point concavePoly[] = {Point(0, 0), Point(5, 0), Point(5, 5), Point(4, 5), Point(3, 4), Point(2, 5), Point(0, 5)};
Point convexPoly[] = {Point(0, 0), Point(5, 0), Point(5, 5), Point(4, 5.7), Point(3, 6), Point(2, 5.7), Point(0, 5)};

Point rectanglePoly[] = {Point(0, 0), Point(5, 0), Point(5, 1), Point(4, 1), Point(4, 5), Point(2, 5), Point(2, 2), Point(0, 2)};

Point p1(3, 5);
Point p2(5, 2);

TEST(Polygon, IsConvex) {
  EXPECT_TRUE(IsConvex(convexPoly, 7));
  EXPECT_FALSE(IsConvex(concavePoly, 7));
}

TEST(Polygon, PolygonContainsPointInside) {
  EXPECT_EQ(1, PolygonContainsPoint(convexPoly, 7, p1));
  EXPECT_EQ(1, PolygonContainsPoint(concavePoly, 7, Point(2, 2)));
  EXPECT_EQ(1, PolygonContainsPoint(rectanglePoly, 8, Point(1, 1)));
}

TEST(Polygon, PolygonContainsPointOnTheSide) {
  EXPECT_EQ(0, PolygonContainsPoint(convexPoly, 7, p2));
  EXPECT_EQ(0, PolygonContainsPoint(convexPoly, 7, convexPoly[2]));
  EXPECT_EQ(0, PolygonContainsPoint(concavePoly, 7, p2));
  EXPECT_EQ(0, PolygonContainsPoint(concavePoly, 7, concavePoly[2]));
  EXPECT_EQ(0, PolygonContainsPoint(rectanglePoly, 8, Point(2, 2)));
}

TEST(Polygon, PolygonContainsPointOutside) {
  EXPECT_EQ(-1, PolygonContainsPoint(concavePoly, 7, p1));
  EXPECT_EQ(-1, PolygonContainsPoint(convexPoly, 7, Point(4, 6)));
  EXPECT_EQ(-1, PolygonContainsPoint(rectanglePoly, 8, Point(5, 2)));
}

TEST(Polygon, ConvextPolygonContainsPointInside) {
  EXPECT_EQ(1, ConvexPolygonContainsPoint(convexPoly, 7, p1));
}

TEST(Polygon, ConvextPolygonContainsPointOnTheSide) {
  EXPECT_EQ(0, ConvexPolygonContainsPoint(convexPoly, 7, p2));
}

TEST(Polygon, ConvextPolygonContainsPointOutside) {
  EXPECT_EQ(-1, ConvexPolygonContainsPoint(convexPoly, 7, Point(4, 6)));
}

TEST(Polygon, AreaPolygon) {
  EXPECT_EQ(24, PolygonArea(concavePoly, 7));
  EXPECT_EQ(27.75, PolygonArea(convexPoly, 7));
  EXPECT_EQ(15, PolygonArea(rectanglePoly, 8));
}
