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
    if(sgn((poly[i] - p) ^ (poly[(i + 1) % n] - p)) < 0) // switch to > 0 if poly is sorted clockwise
      return -1;
    else if(PointOnSeg(p, Line(poly[i], poly[(i + 1) % n])))
      return 0;
  }
  return 1;
}
