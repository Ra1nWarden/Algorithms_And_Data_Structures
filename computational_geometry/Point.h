#ifndef ALGORITHM_POINT_H_
#define ALGORITHM_POINT_H_

#include <cmath>

using namespace std;

// Adjust the epsilon if necessary
const double EPS = 1e-6;
const double PI = acos(-1.0);

int sgn(double x);

struct Point {
  double x, y;
  Point();
  Point(double _x, double _y);
  Point operator+(const Point& b) const;
  Point operator-(const Point& b) const;
  Point operator*(double m) const;
  Point operator/(double m) const;
  // cross product
  double operator^(const Point& b) const;
  // dot product
  double operator*(const Point& b) const;
  bool operator<(const Point& b) const;
  bool operator==(const Point& b) const;
  // rotate with respect to origin with B in radiant
  void transXY(double B);
  // rotate with respect to point p
  void transXY(double B, Point p);
};

// return distance between a and b
double dist(Point a, Point b);
// return distance between p and origin
double dist(Point p);

// return the angle between two points (vectors)
// from a to b in counter-clockwise direction
double angle(Point a, Point b);

// return unit normal vector
Point normal(Point A);

// determines whether p -> q -> r is a left/right turn
// 1 -> left turn
// -1 -> right turn
// 0 -> collinear
int turn(Point p, Point q, Point r);

#endif
