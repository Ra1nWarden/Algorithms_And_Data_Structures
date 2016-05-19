#ifndef ALGORITHM_TRIANGLE_H_
#define ALGORITHM_TRIANGLE_H_

#include "Point.h"
#include "Line.h"
#include "Circle.h"

using namespace std;

// Do not use this if coordinates of the three points are provided
double AreaHeron(double a, double b, double c);
// A more precise calculation of area of triangle
double AreaPoint(Point a, Point b, Point c);
// Radius of inner circle given the area and perimeter
double InnerRadius(double area, double perimeter);
// Radius of outer circle given the area and length of the sides
double OuterRadius(double area, double a, double b, double c);
// Origin of outer radius
Point OuterCircleCenter(Point a, Point b, Point c);
// Returns the length of other side c
double CosineRule(double a, double b, double angle); // angle is the angle between side a and side b
// Returns the length of side B
double SineRule(double a, double A, double B); // A is the angle opposite of side A
// Returns whether the triangle ABC contains point p
// -1 -> p is not in the triangle
// 0 -> p is on the side of the triangle
// 1 -> p is inside the triangle
int TriangleContainsPoint(Point a, Point b, Point c, Point p);
// Center of mass of triangle
Point CenterOfMass(Point a, Point b, Point c);
// Find circumscribed circle given the points
Circle CircumscribedCircle(Point p1, Point p2, Point p3);
// Find inscribed circle given the points
Circle InscribedCircle(Point p1, Point p2, Point p3);

#endif
