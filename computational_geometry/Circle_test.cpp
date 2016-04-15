#include "gtest/gtest.h"
#include "Circle.h"

using namespace std;

TEST(Circle, LineIntersectionTestOne) {
  Point center(1, 1);
  Circle circle(center, 1);
  Line tangent(Point(0, 0), Point(1, 0));
  vector<Point> intersections;
  int points = circle.getLineIntersection(tangent, intersections);
  EXPECT_EQ(1, points);
  ASSERT_EQ(1, intersections.size());
  EXPECT_EQ(Point(1, 0), intersections[0]);
}

TEST(Circle, LineIntersectionTestTwo) {
  Point center(1, 1);
  Circle circle(center, 1);
  Line tangent(Point(0, 1), Point(1, 1));
  vector<Point> intersections;
  int points = circle.getLineIntersection(tangent, intersections);
  EXPECT_EQ(2, points);
  ASSERT_EQ(2, intersections.size());
  EXPECT_EQ(Point(0, 1), intersections[1]);
  EXPECT_EQ(Point(2, 1), intersections[0]);
}

TEST(Circle, LineIntersectionTestThree) {
  Point center(1, 1);
  Circle circle(center, 1);
  Line tangent(Point(0, 3), Point(3, 3));
  vector<Point> intersections;
  EXPECT_EQ(0, circle.getLineIntersection(tangent, intersections));
}

TEST(Circle, CircleIntersectionTestOne) {
  Point p1(1, 0);
  Point p2(5, 0);
  Circle c1(p1, 1);
  Circle c2(p2, 3);
  vector<Point> points;
  int cnt = c1.getCircleIntersection(c2, points);
  EXPECT_EQ(1, cnt);
  ASSERT_EQ(1, points.size());
  EXPECT_EQ(Point(2, 0), points[0]);
}

TEST(Circle, CircleIntersectionTestTwo) {
  Point p1(1, 0);
  Point p2(3, 0);
  Circle c1(p1, 4);
  Circle c2(p2, 2);
  vector<Point> points;
  int cnt = c1.getCircleIntersection(c2, points);
  EXPECT_EQ(1, cnt);
  ASSERT_EQ(1, points.size());
  EXPECT_EQ(Point(5, 0), points[0]);
}

TEST(Circle, CircleIntersectionTestThree) {
  Point p1(1, 0);
  Point p2(3, 0);
  Circle c1(p1, 5);
  Circle c2(p2, 1);
  vector<Point> points;
  int cnt = c1.getCircleIntersection(c2, points);
  EXPECT_EQ(0, cnt);
}

TEST(Circle, CircleIntersectionTestFour) {
  Point p1(1, 0);
  Point p2(5, 0);
  Circle c1(p1, 1);
  Circle c2(p2, 2);
  vector<Point> points;
  int cnt = c1.getCircleIntersection(c2, points);
  EXPECT_EQ(0, cnt);
}

TEST(Circle, CircleIntersectionTestFive) {
  Point p1(1, 0);
  Point p2(5, 0);
  Circle c1(p1, sqrt(10));
  Circle c2(p2, sqrt(2));
  vector<Point> points;
  int cnt = c1.getCircleIntersection(c2, points);
  EXPECT_EQ(2, cnt);
  EXPECT_EQ(Point(4, 1), points[1]);
  EXPECT_EQ(Point(4, -1), points[0]);
}

TEST(Circle, CircleIntersectionTestSix) {
  Point p1(1, 0);
  Point p2(1, 0);
  Circle c1(p1, sqrt(10));
  Circle c2(p2, sqrt(10));
  vector<Point> points;
  int cnt = c1.getCircleIntersection(c2, points);
  EXPECT_EQ(-1, cnt);
}

TEST(Circle, LineTangentsTestOne) {
  Point p(5, 0);
  Circle c(p, 3);
  Point pp(4, 0);
  vector<Line> tangents;
  int cnt = c.getLineTangents(pp, tangents);
  EXPECT_EQ(0, cnt);
}

TEST(Circle, LineTangentsTestTwo) {
  Point p(5, 0);
  Circle c(p, 3);
  Point pp(1, 0);
  vector<Line> tangents;
  int cnt = c.getLineTangents(pp, tangents);
  EXPECT_EQ(2, cnt);
}

TEST(Circle, LineTangentsTestThree) {
  Point p(5, 0);
  Circle c(p, 3);
  Point pp(2, 0);
  vector<Line> tangents;
  int cnt = c.getLineTangents(pp, tangents);
  EXPECT_EQ(1, cnt);
}

TEST(Circle, CircleTangentsTestOne) {
  Point p(5, 0);
  Circle c1(p, 1);
  Circle c2(p, 1);
  vector<Line> tangents;
  int cnt = c1.getCircleTangents(c2, tangents);
  EXPECT_EQ(-1, cnt);
}

TEST(Circle, CircleTangentsTestTwo) {
  Point p(5, 0);
  Circle c1(p, 2);
  Circle c2(p, 1);
  vector<Line> tangents;
  int cnt = c1.getCircleTangents(c2, tangents);
  EXPECT_EQ(0, cnt);
}

TEST(Circle, CircleTangentsTestThree) {
  Point p1(5, 0);
  Point p2(3, 0);
  Circle c1(p1, 1);
  Circle c2(p2, 3);
  vector<Line> tangents;
  int cnt = c1.getCircleTangents(c2, tangents);
  EXPECT_EQ(1, cnt);
}

TEST(Circle, CircleTangentsTestFour) {
  Point p1(5, 0);
  Point p2(2, 0);
  Circle c1(p1, 2);
  Circle c2(p2, 2);
  vector<Line> tangents;
  int cnt = c1.getCircleTangents(c2, tangents);
  EXPECT_EQ(2, cnt);
}

TEST(Circle, CircleTangentsTestFive) {
  Point p1(5, 0);
  Point p2(2, 0);
  Circle c1(p1, 1);
  Circle c2(p2, 2);
  vector<Line> tangents;
  int cnt = c1.getCircleTangents(c2, tangents);
  EXPECT_EQ(3, cnt);
}

TEST(Circle, CircleTangentsTestSix) {
  Point p1(6, 0);
  Point p2(2, 0);
  Circle c1(p1, 1);
  Circle c2(p2, 2);
  vector<Line> tangents;
  int cnt = c1.getCircleTangents(c2, tangents);
  EXPECT_EQ(4, cnt);
}

TEST(Circle, AngleOnCircleTestOne) {
  Point center(1, 1);
  Circle circle(center, sqrt(2));
  EXPECT_EQ(Point(0, 0), circle.angleOnCircle(5 * PI / 4));
}

TEST(Circle, AngleOnCircleTestTwo) {
  Point center(2, 2);
  Circle circle(center, 2);
  EXPECT_EQ(Point(2, 0), circle.angleOnCircle(3 * PI / 2));
}
