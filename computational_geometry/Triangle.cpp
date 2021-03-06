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

int TriangleContainsPoint(Point a, Point b, Point c, Point p) {
  if(PointOnSeg(p, Line(a, b)) || PointOnSeg(p, Line(b, c)) || PointOnSeg(p, Line(a, c)))
    return 0;
  int turn1 = turn(a, p, b);
  int turn2 = turn(b, p, c);
  int turn3 = turn(c, p, a);
  if(turn1 == turn2 && turn2 == turn3)
    return 1;
  else
    return -1;
}

Point CenterOfMass(Point a, Point b, Point c) {
  return (a + b + c) / 3;
}

Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
  double Bx = p2.x - p1.x;
  double By = p2.y - p1.y;
  double Cx = p3.x - p1.x;
  double Cy = p3.y - p1.y;
  double D = 2 * (Bx * Cy - By * Cx);
  double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
  double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;
  Point p(cx, cy);
  return Circle(p, dist(p, p1));
}

Circle InscribedCircle(Point p1, Point p2, Point p3) {
  double a = dist(p2, p3);
  double b = dist(p3, p1);
  double c = dist(p1, p2);
  Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
  return Circle(p, DistanceToLine(p, Line(p1, p2)));
}
