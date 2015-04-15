#include "Utility.h"
#include <cstring>
#include <stack>
#include <map>

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

Euler::Euler() {
  memset(adjMat, false, sizeof adjMat);
  adjList.clear();
};

Euler::Euler(int node) : n(node) {
  memset(adjMat, false, sizeof adjMat);
  adjList.clear();
}

bool Euler::singleConnected() {
  // Assuming 1 to n are all valid nodes.
  int cc = 0;
  bool visited[MAXN];
  memset(visited, false, sizeof visited);
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      cc++;
      stack<int> s;
      visited[i] = true;
      s.push(i);
      while(!s.empty()) {
	int next = s.top();
	s.pop();
	for(int j = 1; j <= n; j++) {
	  if(adjMat[next][j] && !visited[j]) {
	    visited[j] = true;
	    s.push(j);
	  }
	}
      }
    }
  }
  return cc == 1;
}

bool Euler::isEulerDirected() {
  // Use adjList and adjMat for this case.
  // A directed graph is eulerian if the graph is connected and either of the following is true
  // 1. All in-degree equals to out-degree for each node
  // 2. There are two nodes where in-degree does not equal to out-degree differ. One has in-degree one larger than out-degree (entrance). The other has out-degree one larger than in-degree (exit).
  int indegree[MAXN];
  int outdegree[MAXN];
  memset(indegree, 0, sizeof indegree);
  memset(outdegree, 0, sizeof outdegree);

  // Assuming adjList contains directed edges only.
  // Update adjMat and check for single connected component.
  for(map<int, vector<int> >::iterator itr = adjList.begin(); itr != adjList.end(); itr++) {
    int u = itr->first;
    for(int i = 0; i < itr->second.size(); i++) {
      int v = itr->second[i];
      outdegree[u]++;
      indegree[v]++;
      adjMat[u][v] = adjMat[v][u] = true;
    }
  }

  if(!singleConnected()) {
    return false;
  }

  bool entrance = false;
  bool exit = false;
  // Nodes are 1-based.
  for(int i = 1; i <= n; i++) {
    if(indegree[i] != outdegree[i]) {
      if(indegree[i] > outdegree[i]) {
	if(indegree[i] == outdegree[i] + 1) {
	  if(!entrance) {
	    entrance = true;
	  } else {
	    return false;
	  }
	} else {
	  return false;
	}
      } else {
	if(outdegree[i] == indegree[i] + 1) {
	  if(!exit) {
	    exit = true;
	  } else {
	    return false;
	  }
	} else {
	  return false;
	}
      }
    }
  }
  return true;
}

bool Euler::isEulerUndirected() {
  // use adjMat for this case.
  // A undirected graph is eulerian if the graph is connected and either of the following is true
  // 1. All nodes have even degrees.
  // 2. All nodes except two have even degrees.
  if(!singleConnected())
    return false;
  int degree[MAXN];
  memset(degree, 0, sizeof degree);
  // Assuming nodes are 1-based.
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(adjMat[i][j]) {
	degree[i]++;
	degree[j]++;
      }
    }
  }
  int oddcount = 0;
  for(int i = 1; i <= n; i++) {
    if(degree[i] % 2 == 1)
      oddcount++;
  }
  return oddcount == 0 || oddcount == 2;
}
