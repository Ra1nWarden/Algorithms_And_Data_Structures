#include "gtest/gtest.h"
#include "SplayTree.h"

using namespace std;

void checkEqual(const vector<int>& v, int* arr) {
  for(int i = 0; i < v.size(); i++)
    EXPECT_EQ(arr[i], v[i]);
}

TEST(SplayTree, SplitTest) {
  SplayTree tree;
  tree.init(10);
  Node* left, *right;
  split(tree.root, 5, left, right);
  vector<int> l, r;
  traverse(left, l);
  traverse(right, r);
  int lv[] = {1,2,3,4,5};
  int rv[] = {6,7,8,9,10};
  checkEqual(l, lv);
  checkEqual(r, rv);
}

TEST(SplayTree, MergeTest) {
  SplayTree tree;
  tree.init(10);
  SplayTree tree2;
  tree2.init(5);
  vector<int> c;
  traverse(merge(tree.root, tree2.root), c);
  int expected[] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
  checkEqual(c, expected);
}

TEST(SplayTree, SplitMergeTest) {
  SplayTree tree1, tree2;
  tree1.init(10);
  tree2.init(6);
  Node* left, *right;
  split(tree1.root, 4, left, right);
  Node* all = merge(merge(left, tree2.root), right);
  vector<int> c;
  traverse(all, c);
  int expected[] = {1,2,3,4,1,2,3,4,5,6,5,6,7,8,9,10};
  checkEqual(c, expected);
}

TEST(SplayTree, SplitMergeReverseTest) {
  SplayTree tree1, tree2;
  tree1.init(10);
  tree2.init(6);
  Node* left, *right;
  split(tree1.root, 4, left, right);
  right->flip = 1;
  Node* all = merge(merge(left, tree2.root), right);
  vector<int> c;
  traverse(all, c);
  int expected[] = {1,2,3,4,1,2,3,4,5,6,10,9,8,7,6,5};
  checkEqual(c, expected);
}

TEST(SplayTree, SplitAllTest) {
  SplayTree tree;
  tree.init(10);
  Node* left, *right;
  split(tree.root, 10, left, right);
  EXPECT_EQ(NULL, right);
  int expected[] = {1,2,3,4,5,6,7,8,9,10};
  vector<int> c;
  traverse(left, c);
  checkEqual(c, expected);
}
