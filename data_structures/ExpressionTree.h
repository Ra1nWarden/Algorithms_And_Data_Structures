#ifndef DATA_STRUCTURE_EXPRESSION_TREE_H_
#define DATA_STRUCTURE_EXPRESSION_TREE_H_

#include <vector>
#include <string>
#define MAXN 100 // Maximum number of tokens
#define INF 2000000000

using namespace std;

// Expression Tree built by Minimum Tree
struct ExpressionTreeI {
  int left_child[MAXN];
  int right_child[MAXN];
  int values[MAXN];
  int n;
  vector<string> tokens;
  ExpressionTreeI(vector<string> tokens);
  int evaluate();
private:
  int build();
  int evaluate_node(int node);
};

// Iteratively build the Expression Tree by finding the last executed operator
struct ExpressionTreeII {
  int left_child[MAXN];
  int right_child[MAXN];
  string nodes[MAXN];
  int nc, root;
  ExpressionTreeII(vector<string> tokens);
  int evaluate();
private:
  int build(vector<string>& tokens, int x, int y);
  int evaluate_node(int node);
};

#endif
