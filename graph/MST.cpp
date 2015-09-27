#include "MST.h"
#include <algorithm>
#include <cstdlib>
#define INF 2000000000

using namespace std;

int Kruskal::find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

int Kruskal::kruskal() {
  int ans = 0;
  for(int i = 0; i < n; i++)
    p[i] = i;
  for(int i = 0; i < m; i++)
    r[i] = i;
  Comparator cmp;
  cmp.k = this;
  sort(r, r+m, cmp);
  for(int i = 0; i < m; i++) {
    int e = r[i];
    int x = find(u[e]);
    int y = find(v[e]);
    if(x != y) {
      ans += w[e];
      p[x] = y;
    }
  }
  return ans;
}

Point::Point() {}

bool Point::operator<(const Point& rhs) const {
  if(x != rhs.x)
    return x < rhs.x;
  return y < rhs.y;
}

void Node::init() {
  min_val = INF;
  pos = -1;
}

int BIT::lowbit(int x) {
  return x & (-x);
}

void BIT::update(int i, int val, int pos) {
  while(i > 0) {
    if(val < bit[i].min_val) {
      bit[i].min_val = val;
      bit[i].pos = pos;
    }
    i -= lowbit(i);
  }
}

int BIT::query(int i, int m) {
  int min_val = INF, pos = -1;
  while(i <= m) {
    if(bit[i].min_val < min_val) {
      min_val = bit[i].min_val;
      pos = bit[i].pos;
    }
    i += lowbit(i);
  }
  return pos;
}

bool Edge::operator<(const Edge& edge) const {
  return d < edge.d;
}

int UnionFindSet::findSet(int x) {
  return fa[x] == x ? x : fa[x] = findSet(fa[x]);
}

void UnionFindSet::init(int n) {
  for(int i = 0; i < n; i++)
    fa[i] = i;
}

void UnionFindSet::unionSet(int x, int y) {
  fa[x] = y;
}

ManhattanMST::ManhattanMST() : total(0), n(0) {}

void ManhattanMST::addPoint(int x, int y) {
  points[n].x = x;
  points[n].y = y;
  points[n].id = n;
  n++;
}

int ManhattanMST::dist(const Point& a, const Point& b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

void ManhattanMST::addEdge(int u, int v, int d) {
  edge[total].u = u;
  edge[total].v = v;
  edge[total++].d = d;
}

int ManhattanMST::manhattanMST() {
  int a[MAXN], b[MAXN];
  total = 0;
  for(int dir = 0; dir < 4; dir++) {
    if(dir == 1 || dir == 3) {
      for(int i = 0; i < n; i++)
	swap(points[i].x, points[i].y);
    } else if(dir == 2) {
      for(int i = 0; i < n; i++)
	points[i].x = -points[i].x;
    }
    sort(points, points+n);
    for(int i = 0; i < n; i++)
      a[i] = b[i] = points[i].y - points[i].x;
    sort(b, b+n);
    int m = unique(b, b+n) - b;
    for(int i = 1; i <= m; i++)
      binary_indexed_tree.bit[i].init();
    for(int i = n-1; i >= 0; i--) {
      int pos = lower_bound(b, b+m, a[i]) - b + 1;
      int ans = binary_indexed_tree.query(pos, m);
      if(ans != -1) {
	addEdge(points[i].id, points[ans].id, dist(points[i], points[ans]));
      }
      binary_indexed_tree.update(pos, points[i].x + points[i].y, i);
    }
  }
  int res = 0;
  sort(edge, edge+total);
  union_find_set.init(n);
  int left = n - 1;
  for(int i = 0; i < total; i++) {
    int u = edge[i].u, v = edge[i].v;
    int fu = union_find_set.findSet(u), fv = union_find_set.findSet(v);
    if(fu != fv) {
      res += edge[i].d;
      union_find_set.unionSet(fu, fv);
      left--;
      if(left == 0)
	break;
    }
  }
  return res;
}
