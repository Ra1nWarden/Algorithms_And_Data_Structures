#ifndef ALGORITHM_GRAPH_UTILITY_H_
#define ALGORITHM_GRAPH_UTILITY_H_

#include <map>
#include <vector>

// Maxmimum number of nodes.
// If this is too large, try to rewrite dfs() with stack
#define MAXN 100

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

#endif
