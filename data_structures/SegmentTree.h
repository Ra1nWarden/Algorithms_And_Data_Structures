#ifndef DATA_STRUCTURE_SEGMENT_TREE_H_
#define DATA_STRUCTURE_SEGMENT_TREE_H_

// define MAXN according to maximum length of the array
// remember to leave some room for the maxium value
#define MAXN 101

using namespace std;

struct Node {
  // For each node
  // the leftmost index, rightmost index and v
  // v can be max/min/sum etc
  int l, r, v;
  Node() {};
};

// Everything in this struct can be global
struct SegmentTree {
  Node segTree[MAXN * 4]; // 4 is enough
  int addv[MAXN * 4]; // An array to keep track of adding array
  SegmentTree();
  // i start from 1 (node index)
  // l and r are the left/right-most index for the node
  void build(int i, int l, int r);
  // i is the node index starting from 1
  // k is the element index
  // val is the new value
  void update(int i, int k, int val);
  // i is the node index starting from 1
  // l and r are the query range (inclusive)
  int query(int i, int l, int r);
  
  // Range update and range query
  // Add val at node i from l to r
  void add_range(int i, int l, int r, int val);
  // Range query
  // Query at index i from l to r and add is the sum of addv array so far
  int query(int i, int l, int r, int add);
};

#endif
