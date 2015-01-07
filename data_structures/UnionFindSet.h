#ifndef DATA_STRUCTURE_UNION_FIND_SET_H_
#define DATA_STRUCTURE_UNION_FIND_SET_H_

#define MAXN 100

using namespace std;

struct UnionFindSet {
  // Fields can be set as global variables
  int p[MAXN];
  UnionFindSet();
  UnionFindSet(int n);
  void UnionSet(int a, int b);
  int FindSet(int a);
  bool SameSet(int a, int b);
};

#endif
