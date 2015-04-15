#include "Utility.h"
#include <cstring>

using namespace std;

bool Toposort::dfs(int u) {
  visited[u] = DFS_GREY;
  // Assume the indices of the vertices start from 1 to n.
  for(int v = 1; v <= n; v++) {
    if(adjMat[u][v]) {
      if(visited[v] == DFS_GREY)
	return false; // There exists a cycle in the graph.
      else if(visited[v] == DFS_WHITE && !dfs(v))
	return false;
    }
  }
  visited[u] = DFS_BLACK;
  toposorted[--t] = u;
  return true;
}

bool Toposort::toposort() {
  t = n;
  memset(visited, DFS_WHITE, sizeof visited);
  // Assume the indices of the vertices start from 1 to n.
  for(int u = 1; u <= n; u++) {
    if(visited[u] == DFS_WHITE)
      if(!dfs(u))
	return false;
  }
  return true;
}

Toposort::Toposort() {
  memset(adjMat, false, sizeof adjMat);
}

Toposort::Toposort(int nodes) : n(nodes) {
  memset(adjMat, false, sizeof adjMat);
}
