#include "Triangle.h"

using namespace std;

double AreaHeron(double a, double b, double c) {
  double s = 0.5 * (a + b + c);
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double AreaPoint(Point a, Point b, Point c) {
  return fabs((b - a) ^ (c - a) * 0.5);
}

double InnerRadius(double area, double perimeter) {
  return area / (perimeter * 0.5);
}

double OuterRadius(double area, double a, double b, double c) {
  return (a * b * c) / (4 * area);
}

Point OuterCircleCenter(Point a, Point b, Point c) {
  double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
  double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
  double d = a1 * b2 - a2 * b1;
  return Point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
}

double CosineRule(double a, double b, double angle) {
  return sqrt(a * a + b * b - cos(angle) * 2 * a * b);
}

double SineRule(double a, double A, double B) {
  return a / sin(A) * sin(B);
}
