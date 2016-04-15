#ifndef ALGORITHM_CIRCLE_H_
#define ALGORITHM_CIRCLE_H_

#include "Point.h"
#include "Line.h"
#include <vector>

using namespace std;

struct Circle {
  Point center;
  double radius;
  Circle(Point c, double r);
  int getLineIntersection(Line l, vector<Point>& intersections);
  // -1 means two circles overlap
  int getCircleIntersection(Circle c, vector<Point>& intersections);
  int getLineTangents(Point p, vector<Line>& tangents);
  // -1 means two circles overlap
  int getCircleTangents(Circle c, vector<Line>& tangents);
  Point angleOnCircle(double a);
};

#endif
