#ifndef ALGORITHM_SHORTEST_PATH_H_
#define ALGORITHM_SHORTEST_PATH_H_

#include <utility>
#include <vector>
#define MAXN 1000 // Maximum number of vertices
#define INF 2000000000

using namespace std;

// An edge class that may be used by some of the algorithms
struct Edge {
  int from, to, dist;
  Edge(int u, int v, int d);
};

typedef pair<int, int> HeapNode; // A type that saves (distance, index) for the priority_queue in Dijkstra's algorithm
struct Dijkstra {
  int n, m; // n is the number of vertices and m is the number of edges
  vector<Edge> edges; // Edges vector
  vector<int> graph[MAXN]; // Adjacency list that saves index to edges vector
  bool visited[MAXN]; // Visited mark array
  int d[MAXN]; // Distance array
  int p[MAXN]; // Parent array for path restoration
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int d);
  // Run dijkstra from source s
  void dijkstra(int s);
  // Run dijkstra from source s to desintaion t and save path
  int dijkstra(int s, int t, vector<int>& path);
};

struct BellmanFord {
  int n; // Number of vertices
  int d[MAXN]; // Distance array
  int p[MAXN]; // Parent array for path restoration
  vector<Edge> edges; // Edges vector
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int d);
  // Run Bellman Ford from source s
  bool bellmanFord(int s);
  // Run Bellman Ford from source s to destination t and save path
  bool bellmanFord(int s, int t, int& dist, vector<int>& path);
};

struct SPFA {
  int n, m; // n is the number of vertices and m is the number of edges
  vector<Edge> edges; // Edges vector
  vector<int> graph[MAXN]; // Adjacency list that saves index to edges vector
  bool inQueue[MAXN]; // Visited mark array
  int d[MAXN]; // Distance array
  int p[MAXN]; // Parent array for path restoration
  int cnt[MAXN]; // Count array to count the number of times in queue
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int d);
  // Run SPFA from source s
  bool spfa(int s);
  // Run SPFA from source s to destination t and save path
  bool spfa(int s, int t, int& dist, vector<int>& path);
};

struct FloydWarshall {
  int n; // n is the number of vertices
  int d[MAXN][MAXN]; // Distance 2D array
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int d);
  // Run Floyd Warshall's algorithm to find APSP
  void floydWarshall();
};

#endif
