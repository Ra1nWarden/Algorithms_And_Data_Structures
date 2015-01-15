#include "BinaryIndexTree.h"
#include <cstring>

using namespace std;

int lowbit(int x) {
  return x & (-x);
}

BinaryIndexTree::BinaryIndexTree() {
  memset(C, 0, sizeof C);
}

int BinaryIndexTree::sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}

void BinaryIndexTree::add(int x, int d) {
  while(x <= MAXN) {
    C[x] += d;
    x += lowbit(x);
  }
}

BinaryIndexTree2D::BinaryIndexTree2D() {
  memset(C, 0, sizeof C);
}

int BinaryIndexTree2D::sum(int x, int y) {
  int ret = 0;
  for(int i = x; i > 0; i -= lowbit(i)) {
    for(int j = y; j > 0; j -= lowbit(j)) {
      ret += C[i][j];
    }
  }
  return ret;
}

void BinaryIndexTree2D::add(int x, int y, int d) {
  for(int i = x; i < MAXN; i += lowbit(i)) {
    for(int j = y; j < MAXN; j += lowbit(j)) {
      C[i][j] += d;
    }
  }
}
