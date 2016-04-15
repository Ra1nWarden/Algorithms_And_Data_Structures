#include "Circle.h"
#include "Point.h"

Circle::Circle(Point c, double r) : center(c), radius(r) {}

int Circle::getLineIntersection(Line l, vector<Point>& intersections) {
  double dist = DistanceToLine(center, l);
  int sg = sgn(dist - radius);
  if(sg < 0) {
    Point foot = PointToLine(center, l);
    double offset = sqrt(radius * radius - dist * dist);
    Point unit = l.unit();
    intersections.push_back(foot + unit * offset);
    intersections.push_back(foot - unit * offset);
    return 2;
  } else if(sg == 0) {
    Point foot = PointToLine(center, l);
    intersections.push_back(foot);
    return 1;
  } else {
    return 0;
  }
}

int Circle::getCircleIntersection(Circle c, vector<Point>& intersections) {
  double cc = dist(c.center, center);
  if(sgn(cc) == 0) {
    if(sgn(c.radius - radius) == 0)
      return -1;
    return 0;
  }
  if(sgn(radius + c.radius - cc) < 0)
    return 0;
  if(sgn(fabs(radius - c.radius) - cc) > 0)
    return 0;
  Point dir = c.center - center;
  double a = atan2(dir.y, dir.x);
  double da = acos((radius * radius + cc * cc - c.radius * c.radius) / (2 * radius * cc));
  Point p1 = angleOnCircle(a - da), p2 = angleOnCircle(a + da);
  intersections.push_back(p1);
  if(p1 == p2)
    return 1;
  intersections.push_back(p2);
  return 2;
}

int Circle::getLineTangents(Point p, vector<Line>& tangents) {
  Point u = center - p;
  double dis = dist(u);
  int sg = sgn(dis - radius);
  if(sg < 0) {
    return 0;
  } else if(sg == 0) {
    u.transXY(PI / 2);
    tangents.push_back(Line(p, p+u));
    return 1;
  } else {
    double a = asin(radius / dis);
    u.transXY(a);
    tangents.push_back(Line(p, p+u));
    u.transXY(-2 * a);
    tangents.push_back(Line(p, p+u));
    return 2;
  }
}

int Circle::getCircleTangents(Circle c, vector<Line>& tangents) {
  int cnt = 0;
  if(radius < c.radius) {
    return c.getCircleTangents(*this, tangents);
  }
  double d2 = (center.x - c.center.x) * (center.x - c.center.x) + (center.y - c.center.y) * (center.y - c.center.y);
  double rdiff = radius - c.radius;
  double rsum = radius + c.radius;
  if(sgn(d2 - rdiff * rdiff) < 0)
    return 0;
  double base = atan2(c.center.y - center.y, c.center.x - center.x);
  if(sgn(d2) == 0 && sgn(radius - c.radius) == 0)
    return -1;
  if(sgn(d2 - rdiff * rdiff) == 0) {
    Line l1(angleOnCircle(base), c.angleOnCircle(base));
    cnt++;
    tangents.push_back(l1);
    return cnt;
  }
  double ang = acos((radius - c.radius) / sqrt(d2));
  Line l2(angleOnCircle(base + ang), c.angleOnCircle(base + ang));
  cnt++;
  tangents.push_back(l2);
  Line l3(angleOnCircle(base - ang), c.angleOnCircle(base - ang));
  cnt++;
  tangents.push_back(l3);
  if(sgn(d2 - rsum * rsum) == 0) {
    Line l4(angleOnCircle(base), c.angleOnCircle(PI + base));
    cnt++;
    tangents.push_back(l4);
  } else if(sgn(d2 - rsum * rsum) > 0) {
    ang = acos((radius + c.radius) / sqrt(2));
    Line l5(angleOnCircle(base + ang), c.angleOnCircle(PI + base + ang));
    cnt++;
    tangents.push_back(l5);
    Line l6(angleOnCircle(base - ang), c.angleOnCircle(PI + base - ang));
    cnt++;
    tangents.push_back(l6);
  }
  return cnt;
}

Point Circle::angleOnCircle(double a) {
  return Point(center.x + cos(a) * radius, center.y + sin(a) * radius);
}
