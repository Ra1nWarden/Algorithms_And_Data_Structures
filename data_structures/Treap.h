#ifndef DATA_STRUCTURE_TREAP_H_
#define DATA_STRUCTURE_TREAP_H_

// Treap node
struct Node {
  // 0 -> left 1 -> right
  Node* ch[2];
  // r is random key that follows heap property.
  // v is value that follows BST property.
  // w weight of the node (number of copies of this value).
  // s is the total subtree size.
  int r, v, w, s;
  Node(int v);
  bool operator<(const Node& rhs) const;
  int cmp(int x) const;
  void maintain();
};

// Treap operations
void rotate(Node*& o, int d);
void insert(Node*& o, int x);
void remove(Node*& o, int x);
int kth(Node* o, int k);
int rank(Node* o, int x);

// Memory management
void recycle(Node*& x);

#endif
