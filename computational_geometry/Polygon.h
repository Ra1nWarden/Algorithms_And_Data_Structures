#ifndef ALGORITHM_POLYGON_H_
#define ALGORITHM_POLYGON_H_

#include "Point.h"
#include "Line.h"
#define MAXN 1000

using namespace std;

// Returns whether poly[] is convex
// Points can be sorted in both clockwise or coutner-clockwise direction
bool IsConvex(Point poly[], int n);

// Returns whether poly[] (may not be convex) contains point p
int PolygonContainsPoint(Point poly[], int n, Point p);

// Returns whether convex poly[] contains point p
// poly is sorted in counter-clockwise order
// if poly is sorted in clockwise order, switch < 0 to > 0
// IMPORTANT: If there is no constraint on time, use PolygonContainsPoint instead of this method for convex polygons
int ConvexPolygonContainsPoint(Point poly[], int n, Point p);

// Returns area of polygon with points from p array.
double PolygonArea(Point p[], int n);

// Convex Hull Algorithm in .cpp file

#endif
