#include "Knapsack.h"
#include <cstring>

using namespace std;

Knapsack::Knapsack(int capacity, vector<int> weights, vector<int> values) : capacity(capacity), weights(weights), values(values) {
  n = weights.size();
  memset(dp, 0, sizeof dp); // Depending on whether the problem is asking for filling the entire knapsack. If so, initialize to -1.
}

Knapsack::Knapsack(int capacity, vector<int> weights, vector<int> values, vector<int> counts) : counts(counts), capacity(capacity), weights(weights), values(values) {
  n = weights.size();
  memset(dp, 0, sizeof dp); // Depending on whether the problem is asking for filling the entire knapsack. If so, initialize to -1.
}

void Knapsack::zeroOneEach(int weight, int value, int& ans) {
  for(int v = capacity; v >= weight; v--) {
    dp[v] = max(dp[v], dp[v-weight] + value);
    ans = max(ans, dp[v]);
  }
}

void Knapsack::completeEach(int weight, int value, int& ans) {
  for(int v = weight; v <= capacity; v++) {
    dp[v] = max(dp[v], dp[v-weight] + value);
    ans = max(ans, dp[v]);
  }
}

int Knapsack::zeroOneKnapsack() {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    zeroOneEach(weights[i], values[i], ans);
  }
  return ans;
}

int Knapsack::completeKnapsack() {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    completeEach(weights[i], values[i], ans);
  }
  return ans;
}

void Knapsack::multipleEach(int weight, int value, int count, int& ans) {
  if(count * weight >= capacity) {
    completeEach(weight, value, ans);
    return;
  }
  int k = 1;
  while(k < count) {
    zeroOneEach(weight*k, value*k, ans);
    count -= k;
    k *= 2;
  }
  zeroOneEach(weight*count, value*count, ans);
}

int Knapsack::multipleKnapsack() {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    multipleEach(weights[i], values[i], counts[i], ans);
  }
  return ans;
}

bool Knapsack::feasibleKnapsack(int v) {
  // dpf[a][b]: the number of the ath item left (one-indexed) using first a items to fill a capacity of b
  memset(dpf, -1, sizeof dpf);
  dpf[0][0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= capacity; j++) {
      if(dpf[i][j] >= 0) {
	dpf[i+1][j] = counts[i];
      } else {
	dpf[i+1][j] = -1;
      }
    }
    for(int j = 0; j <= capacity - weights[i]; j++) {
      if(dpf[i+1][j] > 0) {
	dpf[i+1][j+weights[i]] = max(dpf[i+1][j+weights[i]], dpf[i+1][j]-1);
      }
    }
  }
  return dpf[n][v] > -1;
}
