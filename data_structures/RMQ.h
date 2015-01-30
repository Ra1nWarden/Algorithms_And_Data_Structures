#ifndef DATA_STRUCTURE_RMQ_H_
#define DATA_STRUCTURE_RMQ_H_

#define MAXN 1001

using namespace std;

struct RMQ {
  int v[MAXN];
  int dp[MAXN][MAXN];
  int n; // Length of v
  RMQ(int b[], int bn);
  void RMQ_init();
  int query(int L, int R); // Query from L to R (inclusive)
};

#endif
