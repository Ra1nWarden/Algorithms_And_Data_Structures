#ifndef ALGORITHM_MAXIMUM_FLOW_H_
#define ALGORITHM_MAXIMUM_FLOW_H_

#include <vector>
#define MAXN 1000 // Maximum number of vertices

using namespace std;

struct Edge {
  int from, to, cap, flow, cost; // No need for cost if only using maximum flow algorithm
  Edge(int u, int v, int c, int f);
  Edge(int u, int v, int c, int f, int w); // Minimum cost maximum flow algorithm constructor
};

struct EdmondsKarp {
  int n, m; // Number of nodes and edges
  vector<Edge> edges; // Edges vector that saves information of all edges
  vector<int> graph[MAXN]; // Adjacency list that saves index to edges vector
  int a[MAXN]; // Minimum flow in the augmenting path from source to i
  int p[MAXN]; // Parent pointer array to retrieve path (This saves the index of edges NOT vertices)
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int cap);
  // Run Edmond Karp's algorithm to find the maximum flow from s to t
  int maxFlow(int s, int t);
};

struct MinimumCostMaximumFlow {
  int n, m; // Number of nodes and edges
  vector<Edge> edges;
  vector<int> graph[MAXN];
  int inq[MAXN];
  int d[MAXN];
  int a[MAXN];
  int p[MAXN];
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int cap, int cost);
  // Bellman-Ford for finding augmenting path (Actual algorithm implemented is SPFA)
  bool bellmanFord(int s, int t, int& flow, long long& cost);
  // Run minimum cost maximum flow algorithm from s to t
  int minimumCostMaximumFlow(int s, int t, long long& cost);
};

#endif
