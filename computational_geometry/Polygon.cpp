#include "Polygon.h"
#include <cstring>

bool IsConvex(Point poly[], int n) {
  bool s[3];
  memset(s, false, sizeof s);
  for(int i = 0; i < n; i++) {
    s[sgn( (poly[(i + 1) % n] - poly[i]) ^ (poly[(i + 2) % n] - poly[i]) ) + 1] = true;
    if(s[0] && s[2])
      return false;
  }
  return true;
}

int PolygonContainsPoint(Point poly[], int n, Point p) {
  int cnt;
  Line ray, side;
  cnt = 0;
  ray.s = p;
  ray.e.y = p.y;
  ray.e.x = -100000000000.0;

  for(int i = 0; i < n; i++) {
    side.s = poly[i];
    side.e = poly[(i + 1) % n];
    
    if(PointOnSeg(p, side))
      return 0;

    if(sgn(side.s.y - side.e.y) == 0)
      continue;

    if(PointOnSeg(side.s, ray)) {
      if(sgn(side.s.y - side.e.y) > 0)
	cnt++;
    }
    else if(PointOnSeg(side.e, ray)) {
      if(sgn(side.e.y - side.s.y) > 0)
	cnt++;
    } else if(SegIntersectSeg(ray, side)) {
      cnt++;
    }
  }

  if(cnt % 2 == 1)
    return 1;
  else
    return -1;
}

int ConvexPolygonContainsPoint(Point poly[], int n, Point p) {
  for(int i = 0; i < n; i++) {
    if(sgn((poly[i] - p) ^ (poly[(i + 1) % n] - p)) < 0) // switch to > 0 if poly is sorted clockwise4
      return -1;
    else if(PointOnSeg(p, Line(poly[i], poly[(i + 1) % n])))
      return 0;
  }
  return 1;
}

double PolygonArea(Point p[], int n) {
  double res = 0;
  for(int i = 0; i < n; i++) {
    res += (p[i] ^ p[(i+1) % n]) / 2;
  }
  return fabs(res);
}



// Convex Hull Algorithm
// Result of indices is stored in Stack in counter-clockwise order
// WARNING: NO UNIT TEST FOR THIS ALGORITHM
// TODO: Write test for this
Point list[MAXN];
int Stack[MAXN], top;

bool _cmp(Point p1, Point p2) {
  double tmp = (p1 - list[0]) ^ (p2 - list[0]);
  if(sgn(tmp) > 0)
    return true;
  else if(sgn(tmp) == 0 && sgn(dist(p1, list[0]) - dist(p2, list[0])) <= 0) // Ignoring collinear point, to include them, use < instead of <=
    return true;
  else
    return false;
}

void GrahamScan(int n) {
  Point p0 = list[0];
  int k = 0;
  for(int i = 1; i < n; i++) {
    if((p0.y > list[i].y) || (p0.y == list[i].y && p0.x > list[i].x)) {
      p0 = list[i];
      k = i;
    }
  }
  swap(list[k], list[0]);
  sort(list + 1, list + n, _cmp);
  if(n == 1) {
    top = 1;
    Stack[0] = 0;
    return;
  }
  Stack[0] = 0;
  Stack[1] = 1;
  top = 2;
  if(n == 2) {
    return;
  }
  for(int i = 2; i < n; i++) {
    while(top > 1 &&
	  sgn((list[Stack[top - 1]] - list[Stack[top - 2]]) ^ (list[i] - list[Stack[top - 2]])) <= 0)
      top--;
    Stack[top++] = i;
  }
}


