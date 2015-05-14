#include "MST.h"
#include <algorithm>

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
