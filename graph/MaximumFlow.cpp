#include "MaximumFlow.h"
#include <cstring>
#include <queue>
#define INF 2000000000

using namespace std;

Edge::Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
Edge::Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}

void EdmondsKarp::init(int n) {
  for(int i = 0; i < n; i++) {
    graph[i].clear();
  }
  edges.clear();
  this->n = n;
}

void EdmondsKarp::addEdge(int from, int to, int cap) {
  edges.push_back(Edge(from, to, cap, 0));
  edges.push_back(Edge(to, from, 0, 0)); // Remember to add a back edge
  m = edges.size();
  graph[from].push_back(m-2);
  graph[to].push_back(m-1);
}

int EdmondsKarp::maxFlow(int s, int t) {
  int flow = 0;
  while(true) {
    memset(a, 0, sizeof a);
    queue<int> q;
    q.push(s);
    a[s] = INF;
    while(!q.empty()) {
      int x = q.front();
      q.pop();
      for(int i = 0; i < graph[x].size(); i++) {
	Edge& e = edges[graph[x][i]];
	if(!a[e.to] && e.cap > e.flow) {
	  p[e.to] = graph[x][i];
	  a[e.to] = min(a[x], e.cap - e.flow);
	  q.push(e.to);
	}
      }
      if(a[t])
	break;
    }
    if(!a[t])
      break;
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    flow += a[t];
  }
  return flow;
}

void MinimumCostMaximumFlow::init(int n) {
  this->n = n;
  for(int i = 0; i < n; i++)
    graph[i].clear();
  edges.clear();
}

void MinimumCostMaximumFlow::addEdge(int from, int to, int cap, int cost) {
  edges.push_back(Edge(from, to, cap, 0, cost));
  edges.push_back(Edge(to, from, 0, 0, -cost));
  m = edges.size();
  graph[from].push_back(m-2);
  graph[to].push_back(m-1);
}

bool MinimumCostMaximumFlow::bellmanFord(int s, int t, int& flow, long long& cost) {
  for(int i = 0; i < n; i++)
    d[i] = INF;
  memset(inq, false, sizeof inq);
  d[s] = 0;
  inq[s] = true;
  p[s] = 0;
  a[s] = INF;
  
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for(int i = 0; i < graph[u].size(); i++) {
      Edge& e = edges[graph[u][i]];
      if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
	d[e.to] = d[u] + e.cost;
	p[e.to] = graph[u][i];
	a[e.to] = min(a[u], e.cap - e.flow);
	if(!inq[e.to]) {
	  q.push(e.to);
	  inq[e.to] = true;
	}
      }
    }
  }
  if(d[t] == INF)
    return false;
  flow += a[t];
  cost += (long long) d[t] * (long long) a[t];
  for(int u = t; u != s; u = edges[p[u]].from) {
    edges[p[u]].flow += a[t];
    edges[p[u]^1].flow -= a[t];
  }
  return true;
}

int MinimumCostMaximumFlow::minimumCostMaximumFlow(int s, int t, long long& cost) {
  int flow = 0;
  cost = 0;
  while(bellmanFord(s, t, flow, cost));
  return flow;
}
