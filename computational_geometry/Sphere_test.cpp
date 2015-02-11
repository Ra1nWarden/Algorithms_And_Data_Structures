#include "gtest/gtest.h"
#include "Sphere.h"

double radius = 6371009;
double pLat = 43.466667;
double pLong = -80.516667;
double qLat = 30.058056;
double qLong = 31.228889;
double pqSurface = 9293520.903338;
double pqSpace = 8491188.316096;

void doubleEq(double x, double y) {
  EXPECT_TRUE(fabs(x - y) < 1e-6);
}

TEST(DistanceSurface, TEST1) {
  doubleEq(pqSurface, DistanceSurface(pLat, pLong, qLat, qLong, radius));
}

TEST(DistanceSpace, TEST1) {
  doubleEq(pqSpace, DistanceSpace(pLat, pLong, qLat, qLong, radius));
}
