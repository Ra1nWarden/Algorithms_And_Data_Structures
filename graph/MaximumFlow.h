#ifndef ALGORITHM_MAXIMUM_FLOW_H_
#define ALGORITHM_MAXIMUM_FLOW_H_

#include <vector>
#define MAXN 1000 // Maximum number of vertices

using namespace std;

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f);
};

struct EdmondsKarp {
  int n, m; // Number of nodes and edges
  vector<Edge> edges; // Edges vector that saves information of all edges
  vector<int> graph[MAXN]; // Adjacency list that saves index to edges vector
  int a[MAXN]; // Minimum flow in the augmenting path from source to i
  int p[MAXN]; // Parent pointer array to retrieve path
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int cap);
  // Run Edmond Karp's algorithm to find the maximum flow from s to t
  int maxFlow(int s, int t);
};

#endif
