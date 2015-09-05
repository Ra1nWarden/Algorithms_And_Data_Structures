#include "ExpressionTree.h"
#include <cstring>
#include <stack>
#include <cstdlib>

using namespace std;

ExpressionTreeI::ExpressionTreeI(vector<string> tokens) : tokens(tokens) {}

int ExpressionTreeI::build() {
  int val, base = 0;
  stack<int> s;
  for(int i = 0; i <= tokens.size(); i++) {
    if(i != tokens.size()) {
      if(tokens[i] == "(") {
	base += 10;
	continue;
      } else if(tokens[i] == ")") {
	base -= 10;
	continue;
      } else {
	if(tokens[i] == "+" || tokens[i] == "-") {
	  val = base + 1;
	} else if(tokens[i] == "*" || tokens[i] == "/") {
	  val = base + 2;
	} else {
	  val = INF;
	}
      }
    }
    values[i] = i == tokens.size() ? -INF : val;
    int right = i;
    while(!s.empty()) {
      int u = s.top();
      if(values[right] <= values[u]) {
	s.pop();
	if(s.empty()) {
	  left_child[right] = u;
	} else {
	  int left = s.top();
	  if(values[left] < values[right]) {
	    left_child[right] = u;
	  } else {
	    right_child[left] = u;
	  }
	}
      } else {
	break;
      }
    }
    s.push(right);
  }
  return left_child[s.top()];
}

int ExpressionTreeI::evaluate_node(int node) {
  string token = tokens[node];
  if(token == "+")
    return evaluate_node(left_child[node]) + evaluate_node(right_child[node]);
  if(token == "-")
    return evaluate_node(left_child[node]) - evaluate_node(right_child[node]);
  if(token == "*")
    return evaluate_node(left_child[node]) * evaluate_node(right_child[node]);
  if(token == "/")
    return evaluate_node(left_child[node]) / evaluate_node(right_child[node]);
  return atoi(token.c_str());
}

int ExpressionTreeI::evaluate() {
  int root = build();
  return evaluate_node(root);
}

ExpressionTreeII::ExpressionTreeII(vector<string> tokens) {
  nc = 0;
  root = build(tokens, 0, tokens.size());
}

int ExpressionTreeII::build(vector<string>& tokens, int x, int y) {
  int i, u, c1 = -1, c2 = -1, p = 0;
  if(y - x == 1) {
    u = ++nc;
    left_child[u] = right_child[u] = 0;
    nodes[u] = tokens[x];
    return u;
  }
  for(i = x; i < y; i++) {
    if(tokens[i] == "(")
      p++;
    if(tokens[i] == ")")
      p--;
    if(tokens[i] == "+" || tokens[i] == "-") {
      if(!p)
	c1 = i;
    }
    if(tokens[i] == "*" || tokens[i] == "/") {
      if(!p)
	c2 = i;
    }
  }
  if(c1 < 0)
    c1 = c2;
  if(c1 < 0)
    return build(tokens, x + 1, y - 1);
  u = ++nc;
  left_child[u] = build(tokens, x, c1);
  right_child[u] = build(tokens, c1 + 1, y);
  nodes[u] = tokens[c1];
  return u;
}

int ExpressionTreeII::evaluate_node(int node) {
  string token = nodes[node];
  if(token == "+")
    return evaluate_node(left_child[node]) + evaluate_node(right_child[node]);
  if(token == "-")
    return evaluate_node(left_child[node]) - evaluate_node(right_child[node]);
  if(token == "*")
    return evaluate_node(left_child[node]) * evaluate_node(right_child[node]);
  if(token == "/")
    return evaluate_node(left_child[node]) / evaluate_node(right_child[node]);
  return atoi(token.c_str());
}

int ExpressionTreeII::evaluate() {
  return evaluate_node(root);
}
