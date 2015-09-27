#ifndef ALGORITHM_GRAPH_MST_H_
#define ALGORITHM_GRAPH_MST_H_

#define MAXE 100 // Maximum number of edges
#define MAXV 100 // Maximum number of vertices

// All fields can be global
struct Kruskal { 
  int u[MAXE], v[MAXE], w[MAXE]; // Edges u, v are the vertices and w is the weight
  // Helper struct for sorting (FOR TESTING PURPOSE. Define the operator() function as a global cmp function.)
  struct Comparator {
    Kruskal* k;
    // Just rename this function and put it in global scope
    bool operator()(int i , int j) {
      return k->w[i] < k->w[j];
    }
  };
  int r[MAXE]; // Edge number
  int p[MAXV]; // Union find set parent array
  int n, m; // n is the number of vertices and m the number of edges
  // Union Find Set find function
  int find(int x);
  // Returns the total weight of the edges in the MST
  int kruskal();
};

// Manhattan Minimum Spanning Tree related.
#define MAXN 1000

struct Point {
  int x, y, id;
  bool operator<(const Point& rhs) const;
  Point();
};

struct Node {
  int min_val, pos;
  void init();
};

struct BIT {
  Node bit[MAXN];
  void init();
  int lowbit(int x);
  void update(int i, int val, int pos);
  int query(int i, int m);
};

struct Edge {
  int u, v, d;
  bool operator<(const Edge& edge) const;
};

struct UnionFindSet {
  int fa[MAXN];
  int findSet(int x);
  void init(int n);
  void unionSet(int x, int y);
};

struct ManhattanMST {
  BIT binary_indexed_tree;
  Edge edge[MAXN<<2];
  int total;
  UnionFindSet union_find_set;
  Point points[MAXN];
  int n;
  ManhattanMST();
  void addPoint(int x, int y);
  int dist(const Point& a, const Point& b);
  int manhattanMST();
  void addEdge(int u, int v, int d);
};

#endif
