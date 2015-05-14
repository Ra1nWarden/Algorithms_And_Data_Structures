#include "ShortestPath.h"
#include <queue>
#include <cstring>
#include <algorithm>

Edge::Edge(int u, int v, int d) : from(u), to(v), dist(d) {}

void Dijkstra::init(int n) {
  this->n = n;
  for(int i = 0; i < n; i++)
    graph[i].clear();
  edges.clear();
}

void Dijkstra::addEdge(int from, int to, int d) {
  edges.push_back(Edge(from, to, d));
  m = edges.size();
  graph[from].push_back(m-1);
}

void Dijkstra::dijkstra(int s) {
  priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > pq;
  for(int i = 0; i < n; i++)
    d[i] = INF;
  d[s] = 0;
  memset(visited, false, sizeof visited);
  pq.push(make_pair(0, s));
  while(!pq.empty()) {
    HeapNode node = pq.top();
    pq.pop();
    int u = node.second;
    if(visited[u])
      continue;
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++) {
      Edge& e = edges[graph[u][i]];
      if(d[e.to] > d[u] + e.dist) {
	d[e.to] = d[u] + e.dist;
	p[e.to] = u;
	pq.push(make_pair(d[e.to], e.to));
      }
    }
  }
}

int Dijkstra::dijkstra(int s, int t, vector<int>& path) {
  priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > pq;
  for(int i = 0; i < n; i++)
    d[i] = INF;
  d[s] = 0;
  memset(visited, false, sizeof visited);
  pq.push(make_pair(0, s));
  while(!pq.empty()) {
    HeapNode node = pq.top();
    pq.pop();
    int u = node.second;
    if(u == t) {
      int entry = t;
      while(entry != s) {
	path.push_back(entry);
	entry = p[entry];
      }
      path.push_back(s);
      reverse(path.begin(), path.end());
      return d[u];
    }
    if(visited[u])
      continue;
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++) {
      Edge& e = edges[graph[u][i]];
      if(d[e.to] > d[u] + e.dist) {
	d[e.to] = d[u] + e.dist;
	p[e.to] = u;
	pq.push(make_pair(d[e.to], e.to));
      }
    }
  }
  return INF; // Not reachable
}

void BellmanFord::init(int n) {
  edges.clear();
  this->n = n;
}

void BellmanFord::addEdge(int from, int to, int d) {
  edges.push_back(Edge(from, to, d));
}

bool BellmanFord::bellmanFord(int s) {
  for(int i = 0; i < n; i++)
    d[i] = INF;
  d[s] = 0;
  for(int i = 0; i < n - 1; i++) {
    bool ok = false;
    for(int j = 0; j < edges.size(); j++) {
      int u = edges[j].from;
      int v = edges[j].to;
      int cost = edges[j].dist;
      if(d[v] > d[u] + cost) {
	d[v] = d[u] + cost;
	p[v] = u;
	ok = true;
      }
    }
    if(!ok)
      return true;
  }
  for(int i = 0; i < edges.size(); i++) {
    if(d[edges[i].to] > d[edges[i].from] + edges[i].dist)
      return false;
  }
  return true;
}

bool BellmanFord::bellmanFord(int s, int t, int& dist, vector<int>& path) {
  if(!bellmanFord(s)) {
    dist = INF;
    return false;
  }
  int entry = t;
  while(entry != s) {
    path.push_back(entry);
    entry = p[entry];
  }
  path.push_back(s);
  reverse(path.begin(), path.end());
  dist = d[t];
  return true;
}

void SPFA::init(int n) {
  this->n = n;
  for(int i = 0; i < n; i++)
    graph[i].clear();
  edges.clear();
}

void SPFA::addEdge(int from, int to, int d) {
  edges.push_back(Edge(from, to, d));
  m = edges.size();
  graph[from].push_back(m-1);
}

bool SPFA::spfa(int s) {
  queue<int> q;
  memset(inQueue, false, sizeof inQueue);
  memset(cnt, 0, sizeof cnt);
  for(int i = 0; i < n; i++)
    d[i] = INF;
  d[s] = 0;
  inQueue[s] = true;
  q.push(s);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    inQueue[u] = false;
    for(int i = 0; i < graph[u].size(); i++) {
      Edge& e = edges[graph[u][i]];
      if(d[u] < INF && d[e.to] > d[u] + e.dist) {
	d[e.to] = d[u] + e.dist;
	p[e.to] = u;
	if(!inQueue[e.to]) {
	  q.push(e.to);
	  inQueue[e.to] = true;
	  if(++cnt[e.to] > n)
	    return false;
	}
      }
    }
  }
  return true;
}

bool SPFA::spfa(int s, int t, int& dist,vector<int>& path) {
  if(!spfa(s)) {
    dist = INF;
    return false;
  }
  int entry = t;
  while(entry != s) {
    path.push_back(entry);
    entry = p[entry];
  }
  path.push_back(s);
  reverse(path.begin(), path.end());
  dist = d[t];
  return true;
}

void FloydWarshall::init(int n) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
          d[i][j] = i == j ? 0 : INF;
  this->n = n;
}

void FloydWarshall::addEdge(int from, int to, int dist) {
  d[from][to] = min(d[from][to], dist);
}

void FloydWarshall::floydWarshall() {
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) {
        if(d[i][k] < INF && d[k][j] < INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }

}
