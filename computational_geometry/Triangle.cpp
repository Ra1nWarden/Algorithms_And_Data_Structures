#include "Triangle.h"

using namespace std;

double AreaHeron(double a, double b, double c) {
  double s = 0.5 * (a + b + c);
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double AreaPoint(Point a, Point b, Point c) {
  double res = 0;
  Point p[] = {a, b, c};
  for(int i = 0; i < 3; i++) {
    res += (p[i] ^ p[(i+1) % 3]) / 2;
  }
  return fabs(res);
}

double InnerRadius(double area, double perimeter) {
  return area / (perimeter * 0.5);
}

double OuterRadius(double area, double a, double b, double c) {
  return (a * b * c) / (4 * area);
}

double CosineRule(double a, double b, double angle) {
  return sqrt(a * a + b * b - cos(angle) * 2 * a * b);
}

double SineRule(double a, double A, double B) {
  return a / sin(A) * sin(B);
}
