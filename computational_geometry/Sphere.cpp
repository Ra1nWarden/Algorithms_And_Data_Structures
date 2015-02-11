#include "Sphere.h"

using namespace std;

double DistanceSurface(double pLat, double pLong, double qLat, double qLong, double radius) {
  pLat *= PI / 180;
  pLong *= PI / 180;
  qLat *= PI / 180;
  qLong *= PI / 180;
  return radius * acos(cos(pLat) * cos(pLong) * cos(qLat) * cos(qLong) +
		       cos(pLat) * sin(pLong) * cos(qLat) * sin(qLong) +
		       sin(pLat) * sin(qLat));
}

double DistanceSpace(double pLat, double pLong, double qLat, double qLong, double radius) {
  pLat *= PI / 180;
  pLong *= PI / 180;
  qLat *= PI / 180;
  qLong *= PI / 180;
  return radius * sqrt(2 - 2 * (cos(pLat) * cos(qLat) * cos(pLong - qLong) + sin(pLat) * sin(qLat)));
}
