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

#endif
