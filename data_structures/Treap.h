#ifndef DATA_STRUCTURE_TREAP_H_
#define DATA_STRUCTURE_TREAP_H_

// Treap node
struct Node {
  // 0 -> left 1 -> right
  Node* ch[2];
  // r is random key that follows heap property.
  // v is value that follows BST property.
  // s is the total subtree size.
  int r, v, s;
  Node(int v);
  bool operator<(const Node& rhs) const;
  int cmp(int x) const;
  void maintain();
};

// Treap operations
void rotate(Node*& o, int d);
void insert(Node*& o, int x);
// Call find(o, x) before calling remove.
void remove(Node*& o, int x);
bool find(Node* o, int x);
int kth(Node* o, int k);
// Duplicates are allowed and the rank is calcualted as the worst one.
// For example, 5, 4, 4, 3, 2, 1. Rank of 4 is 2.
// To make rank of 4 become 3, change the insert judging condition to < instead of <=.
int rank(Node* o, int x);

// Memory management
void recycle(Node*& x);

#endif
