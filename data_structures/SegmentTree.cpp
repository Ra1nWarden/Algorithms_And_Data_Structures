#include "SegmentTree.h"
#include <algorithm>
#include <cstring>
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
  memset(addv, 0, sizeof addv);
  memset(setv, -1, sizeof setv); // Assume -1 is never set to any range of nodes
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

void SegmentTree::add_range(int i, int l, int r, int val) {
  if(l == segTree[i].l && r == segTree[i].r) {
    addv[i] += val;
  } else {
    pushdown(i);
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid) {
      add_range(LEFT(i), l, r, val);
      maintain(RIGHT(i));
    }
    else if(l > mid) {
      add_range(RIGHT(i), l, r, val);
      maintain(LEFT(i));
    }
    else {
      add_range(LEFT(i), l, mid, val);
      add_range(RIGHT(i), mid+1, r, val);
    }
  }
  maintain(i);
}

int SegmentTree::query(int i, int l, int r, int add) {
  if(setv[i] >= 0) {
    return setv[i] + addv[i] + add; // Need to add
  }
  if(segTree[i].l == l && segTree[i].r == r) {
    return segTree[i].v + add;
  }
  int mid = MID(segTree[i].l, segTree[i].r);
  if(r <= mid) {
    return query(LEFT(i), l, r, addv[i] + add);
  } else if(l > mid) {
    return query(RIGHT(i), l, r, addv[i] + add);
  } else {
    return min(query(LEFT(i), l, mid, addv[i] + add), query(RIGHT(i), mid+1, r, addv[i] + add));
  }
}

void SegmentTree::update_range(int i, int l, int r, int val) {
  if(l == segTree[i].l && r == segTree[i].r) {
    setv[i] = val;
    addv[i] = 0;
  } else {
    pushdown(i);
    int mid = MID(segTree[i].l, segTree[i].r);
    if(r <= mid) {
      update_range(LEFT(i), l, r, val);
      maintain(RIGHT(i));
    } else if(l > mid) {
      update_range(RIGHT(i), l, r, val);
      maintain(LEFT(i));
    } else {
      update_range(LEFT(i), l, mid, val);
      update_range(RIGHT(i), mid+1, r, val);
    }
  }
  maintain(i);
}

void SegmentTree::pushdown(int i) {
  // Assume all set values are non-negative
  if(setv[i] >= 0) {
    setv[LEFT(i)] = setv[RIGHT(i)] = setv[i];
    setv[i] = -1;
    addv[LEFT(i)] = addv[RIGHT(i)] = 0;
  }
  addv[LEFT(i)] += addv[i];
  addv[RIGHT(i)] += addv[i];
  addv[i] = 0;
}

void SegmentTree::maintain(int i) {
  if(segTree[i].l < segTree[i].r) {
    segTree[i].v = min(segTree[LEFT(i)].v, segTree[RIGHT(i)].v);
  }
  if(setv[i] >= 0) {
    // For sum, this should be setv[i] * (setv[i].r - setv[i].l + 1);
    segTree[i].v = setv[i];
  }
  // For sum, this should be setv[i] * (setv[i].r - setv[i].l + 1);
  segTree[i].v += addv[i];
}
