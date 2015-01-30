#include "RMQ.h"
#include <iostream>
#include <cstring>

RMQ::RMQ(int b[], int bn) {
  n = bn;
  memcpy(v, b, sizeof(int) * n);
  memset(dp, 0, sizeof dp);
  RMQ_init();
}

void RMQ::RMQ_init() {
  for(int i = 0; i < n; i++)
    dp[i][0] = v[i];
  for(int j = 1; (1 << j) <= n; j++)
    for(int i = 0; i + (1 << j) - 1 < n; i++)
      dp[i][j] = min(dp[i][j-1], dp[i+(1 << (j-1))][j-1]);
}

int RMQ::query(int L, int R) {
  int k = 0;
  while((1 << (k+1)) <= R - L + 1)
    k++;
  return min(dp[L][k], dp[R - (1 << k) + 1][k]);
}
