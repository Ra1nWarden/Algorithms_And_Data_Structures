#include "UnionFindSet.h"

using namespace std;

UnionFindSet::UnionFindSet(int n) {
  for(int i = 0; i < n; i++) {
    p[i] = i;
  }
}

int UnionFindSet::FindSet(int a) {
  return p[a] == a ? a : FindSet(p[a]);
}

void UnionFindSet::UnionSet(int a, int b) {
  p[FindSet(a)] = FindSet(b);
}

bool UnionFindSet::SameSet(int a, int b) {
  return FindSet(a) == FindSet(b);
}
