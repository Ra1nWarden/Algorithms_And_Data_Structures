#ifndef DATA_STRUCTURE_BINARY_INDEX_TREE_H_
#define DATA_STRUCTURE_BINARY_INDEX_TREE_H_

// define MAXN according to maximum length of the array
// remember to leave some room for the maximum value
#define MAXN 101

using namespace std;

int lowbit(int x);

// All functions and fields can be made global
struct BinaryIndexTree {
  // always leave C[0] to be zero, start using from index 1
  int C[MAXN];
  BinaryIndexTree();
  // sometimes long long is needed
  int sum(int x); // [0, x]
  // x is indexed from 1
  void add(int x, int d);
};

/**
 * Range update, single query: build BIT on delta array (delta[i] = v[i] - v[i-1])
 * Range update, range query: build two BITs for delta and delta * index
 * Formula: (index + 1) * query on delta BIT - query on (delta * index) BIT
 * More details: http://blog.csdn.net/zars19/article/details/54620021
 */

struct BinaryIndexTree2D {
  int C[MAXN][MAXN];
  BinaryIndexTree2D();
  int sum(int x, int y); // [(0, 0), (x, y)]
  // x and y are both indexed from 1
  void add(int x, int y, int d);
};

#endif
