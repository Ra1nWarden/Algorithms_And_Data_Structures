#ifndef DATA_STRUCTURE_SPLAY_TREE_H_
#define DATA_STRUCTURE_SPLAY_TREE_H_

#include <vector>

struct Node {
  Node* ch[2];
  // s is the size of subtree.
  // v is the value saved on the node.
  // flip is a marker which can be other things. (Here refers to reverse action.)
  int s, v, flip;
  int cmp(int k) const;
  void maintain();
  void pushdown();
  Node();
};

// Maximum number of nodes in the splay tree.
const int maxn = 1000;

struct SplayTree {
  int n;
  Node nodes[maxn];
  Node* root;
  // Build tree based on size and optionally an array.
  Node* build(int sz);
  // init calls build. Use this method to get a new tree.
  void init(int sz);
};

// Splay tree related operations.
void rotate(Node*& o, int d);
void splay(Node*& o, int k);
Node* merge(Node* left, Node* right);
// k in split should be positive (non-zero).
void split(Node* o, int k, Node*& left, Node*& right);
// Traverse the tree in-order.
// If the values saved on nodes are not int, change the return type to vector<T>
void traverse(Node* o, std::vector<int>& ans);

#endif
