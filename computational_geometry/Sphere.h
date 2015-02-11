#ifndef ALGORITHM_SPHERE_H_
#define ALGORITHM_SPHERE_H_

#include "Point.h"

using namespace std;

// All lats and longs are in degrees
double DistanceSurface(double pLat, double pLong, double qLat, double qLong, double radius);

double DistanceSpace(double pLat, double pLong, double qLat, double qLong, double radius);

#endif
