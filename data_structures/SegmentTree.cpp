#include "SegmentTree.h"
#include <algorithm>
#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1)|1
#define MID(x, y) ((x+y)>>1)

using namespace std;

SegmentTree::SegmentTree() {};

void SegmentTree::build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  /*
    There are multiple ways to build the tree.
    Here, I am initializing everything to 0 and use update to insert values.
    It is also fine to initialize the tree with values in the array in build().
   */
  segTree[i].v = 0; // Initialize v to 0.
  if(l == r)
    return;
  build(LEFT(i), l, MID(l, r));
  build(RIGHT(i), MID(l, r)+1, r);
}

void SegmentTree::update(int i, int k, int val) {
  /*
    For sum type of segment tree, it can be done with BIT.
    If segment tree is still used, update can be simplified to
    segTree[i] += val;
    where val is the offset being added which is different from
    the meaning of the val here.
   */
  if(segTree[i].l == k && segTree[i].r == k) {
    segTree[i].v = val;
    return;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(k <= mid)
    update(LEFT(i), k, val);
  else
    update(RIGHT(i), k, val);
  // This function can be done at the beginning of ths method.
  // Depending on data maintained in the tree, call min/max/add, etc
  segTree[i].v = min(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
}

int SegmentTree::query(int i, int l, int r) {
  if(segTree[i].l == l && segTree[i].r == r)
    return segTree[i].v;
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid)
    return query(LEFT(i), l, r);
  else if (l > mid)
    return query(RIGHT(i), l, r);
  else
    // Depending on data maintained in the tree, call min/max/add, etc
    return min(query(LEFT(i), l, mid), query(RIGHT(i), mid+1, r));
}
