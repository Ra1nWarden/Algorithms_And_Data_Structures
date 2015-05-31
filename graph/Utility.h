#ifndef ALGORITHM_GRAPH_UTILITY_H_
#define ALGORITHM_GRAPH_UTILITY_H_

#include <map>
#include <vector>

// Maxmimum number of nodes.
// If this is too large, try to rewrite dfs() with stack
#define MAXN 100
#define MAXE 1000 // Maximum number of edges

// dfs symbols
#define DFS_WHITE 0
#define DFS_GREY -1
#define DFS_BLACK 1

using namespace std;

struct Toposort {
  int visited[MAXN];
  int toposorted[MAXN];
  int t; // The next index to update toposorted.
  int n; // Total number of nodes.
  // This can be replaced by adjacency list, etc.
  bool adjMat[MAXN][MAXN];
  // Replace this dfs() with a stack if necessary.
  // This function works as finding a cycle in directed graph as well.
  bool dfs(int u);
  bool toposort();
  Toposort();
  Toposort(int nodes);
};

struct Euler {
  int n; // Total number of nodes.
  map<int, vector<int> > adjList;
  bool adjMat[MAXN][MAXN];
  bool singleConnected();
  bool isEulerDirected();
  bool isEulerUndirected();
  Euler();
  Euler(int nodes);
};

struct TransitiveClosure {
  int n; // Number of vertices
  bool d[MAXN][MAXN]; // 2D result array
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to);
  // Run transitive closure (similar to Floyd Warshall's APSP)
  void transitiveClosure();
};

struct Bipartite {
  int n; // Number of vertices
  vector<int> graph[MAXN]; // Adjacency List
  int color[MAXN]; // 0: not colored 1: black 2: white
  void addEdge(int u, int v); // utility function for testing purpose
  bool isBipartite(int u); // Returns whether the component with u is bipartite
  Bipartite(int n);
};

struct Edge {
  int from, to;
  Edge(int u, int v);
};

struct ArticulationPointAndBridge {
  vector<Edge> edges; // Edges array
  vector<int> graph[MAXN]; // Ajdacency list with values indicating the indices to edges array
  int n; // Number of nodes
  int pre[MAXN], low[MAXN]; // Array for dfs_clock and an array for the minimum pre value for a vertex and its children
  int dfs_clock; // A clock for counting dfs sequence
  bool cutPoint[MAXN];
  bool cutBridge[MAXE];
  void addEdge(int from, int to);
  ArticulationPointAndBridge(int n);
  int dfs(int u, int fa); // Run dfs with u and fa as the parent node
  bool isCutPoint(int u);
  bool isCutBridge(int v);
};

#endif
