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

void TransitiveClosure::init(int n) {
  this->n = n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      d[i][j] = i == j;
    }
  }
}

void TransitiveClosure::addEdge(int from, int to) {
  d[from][to] = true;
}

void TransitiveClosure::transitiveClosure() {
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
      }
    }
  }
}

Bipartite::Bipartite(int n) {
  this->n = n;
  for(int i = 0; i < n; i++)
    graph[i].clear();
  memset(color, 0, sizeof color);
}

void Bipartite::addEdge(int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}

bool Bipartite::isBipartite(int u) {
  if(!color[u])
    color[u] = 1;
  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if(color[v] == color[u]) {
      return false;
    }
    if(!color[v]) {
      color[v] = 3 - color[u];
      if(!isBipartite(v)) {
	return false;
      }
    }
  }
  return true;
}

Edge::Edge(int u, int v) {
  from = u;
  to = v;
}

ArticulationPointAndBridge::ArticulationPointAndBridge(int n) {
  this->n = n;
  edges.clear();
  for(int i = 0; i < n; i++)
    graph[i].clear();
  memset(pre, 0, sizeof pre);
  memset(low, 0, sizeof low);
  memset(cutPoint, false, sizeof cutPoint);
  memset(cutBridge, false, sizeof cutBridge);
  dfs_clock = 0;
}

void ArticulationPointAndBridge::addEdge(int from, int to) {
  edges.push_back(Edge(from, to));
  edges.push_back(Edge(to, from));
  graph[from].push_back(edges.size() - 2);
  graph[to].push_back(edges.size() - 1);
}

int ArticulationPointAndBridge::dfs(int u, int fa) {
  int lowu = pre[u] = ++dfs_clock;
  int child = 0;
  for(int i = 0; i < graph[u].size(); i++) {
    Edge& e= edges[graph[u][i]];
    int v = e.to;
    if(!pre[v]) {
      child++;
      int lowv = dfs(v, u);
      lowu = min(lowu, lowv);
      if(lowv >= pre[u]) {
	cutPoint[u] = true;
	if(lowv > pre[u])
	  cutBridge[graph[u][i]] = cutBridge[graph[u][i]^1] = true;
      }
    } else if(pre[v] < pre[u] && v != fa) {
      lowu = min(lowu, pre[v]);
    }
  }
  if(fa < 0 && child == 1)
    cutPoint[u] = false;
  low[u] = lowu;
  return lowu;
}


bool ArticulationPointAndBridge::isCutPoint(int u) {
  if(!pre[u])
    dfs(u, -1);
  return cutPoint[u];
}

bool ArticulationPointAndBridge::isCutBridge(int v) {
  Edge& edge = edges[v];
  if(!pre[edge.from])
    dfs(edge.from, -1);
  return cutBridge[v];
}

Tarjan::Tarjan(int n) {
  this->n = n;
  for(int i = 0; i < n; i++)
    graph[i].clear();
  dfs_clock = scc_cnt = 0;
  memset(sccno, 0, sizeof sccno);
  memset(pre, 0, sizeof pre);
}

void Tarjan::addEdge(int u, int v) {
  graph[u].push_back(v);
}

void Tarjan::dfs(int u) {
  pre[u] = lowlink[u] = ++dfs_clock;
  s.push(u);
  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if(!pre[v]) {
      dfs(v);
      lowlink[u] = min(lowlink[u], lowlink[v]);
    } else if(!sccno[v]) {
      lowlink[u] = min(lowlink[u], pre[v]);
    }
  }
  if(lowlink[u] == pre[u]) {
    scc_cnt++;
    while(true) {
      int x = s.top();
      s.pop();
      sccno[x] = scc_cnt;
      if(x == u)
	break;
    }
  }
}

void Tarjan::tarjan() {
  for(int i = 0; i < n; i++) {
    if(!pre[i])
      dfs(i);
  }
}

TreeDecomposition::TreeDecomposition(vector<vector<int> > adj) {
  tree = adj;
  // Assuming 0 is root
  fa[0] = 0;
  depth[0] = 0;
  dfs1(0);
  cnt = 0;
  dfs2(0, 0); // Path head for root is root itself
}

void TreeDecomposition::dfs1(int u) {
  son[u] = -1;
  size[u] = 1;
  for(int i = 0; i < tree[u].size(); i++) {
    int v = tree[u][i];
    if(v == fa[u])
      continue;
    fa[v] = u;
    depth[v] = depth[u] + 1;
    dfs1(v);
    size[u] += size[v];
    if(son[u] == -1 || size[v] > size[son[u]])
      son[u] = v;
  }
}

void TreeDecomposition::dfs2(int u, int t) {
  top[u] = t;
  dfn[u] = cnt;
  rank[cnt] = u;
  cnt++;
  if(son[u] == -1) // Leaf node
    return;
  dfs2(son[u], t);
  for(int i = 0; i < tree[u].size(); i++) {
    int v = tree[u][i];
    if(v == fa[u] || v == son[u])
      continue;
    dfs2(v, v);
  }
}
