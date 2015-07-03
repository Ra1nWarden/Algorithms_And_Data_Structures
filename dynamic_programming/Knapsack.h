#ifndef ALGORITHM_KNAPSACK_H_
#define ALGORITHM_KNAPSACK_H_

#include <vector>
#define MAXV 100 // Maximum capacity of the knapsack.
#define MAXN 10 // Maximum number of items.

using namespace std;

struct Knapsack {
  
  int dp[MAXV]; // Maximum value for each capacity.
  int dpf[MAXN][MAXV]; // Array for feasibleKnapsack(int v).
  int capacity; // The capacity of the knapsack.
  int n;  // The number of items
  vector<int> weights; // Array for the weights of the items.
  vector<int> values; // Array for the values of the items.
  vector<int> counts; // Array for the number of items available for selection. (Multiple Knapsack)

  Knapsack(int capacity, vector<int> weights, vector<int> values); // For 01 and complete knapsack problem
 
  void zeroOneEach(int weight, int value, int& ans);
  void completeEach(int weight, int value, int& ans);
  int zeroOneKnapsack();
  int completeKnapsack();


  Knapsack(int capacity, vector<int> weights, vector<int> values, vector<int> counts); // For multiple knapsack problem

  void multipleEach(int weight, int value, int count, int& ans);
  int multipleKnapsack();
  bool feasibleKnapsack(int v);
};

/**
 * All non-01 knapsack problems can be converted to 01 knapsack by grouping items using binary representation.
 */

#endif
