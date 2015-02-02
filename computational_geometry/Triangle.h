#ifndef ALGORITHM_TRIANGLE_H_
#define ALGORITHM_TRIANGLE_H_

#include "Point.h"
#include "Line.h"

using namespace std;

// Do not use this if coordinates of the three points are provided
double AreaHeron(double a, double b, double c);
// A more precise calculation of area of triangle
double AreaPoint(Point a, Point b, Point c);
// Radius of inner circle
double InnerRadius(double area, double perimeter);
// Radius of outer circle
double OuterRadius(double area, double a, double b, double c);
// Origin of outer radius
Point OuterCircleCenter(Point a, Point b, Point c);
// Returns the length of other side c
double CosineRule(double a, double b, double angle); // angle is the angle between side a and side b
// Returns the length of side B
double SineRule(double a, double A, double B); // A is the angle opposite of side A

#endif
