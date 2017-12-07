#include "Fibonacci.h"

using namespace std;

Fibonacci::Fibonacci() {}

int Fibonacci::sum(int n) {
  return val(n + 2) - 1;
}

int Fibonacci::val(int n) {
  int f[2][2] = {{1, 1}, {1, 0}};
  power(f, n);
  return f[0][1];
}

void Fibonacci::power(int m[2][2], int n) {
  if(n == 1)
    return;
  int g[2][2];
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      g[i][j] = m[i][j];
  power(g, n / 2);
  mult(g, g);
  if(n & 1) {
    mult(g, m);
  }
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      m[i][j] = g[i][j];
}

void Fibonacci::mult(int m[2][2], int n[2][2]) {
  int v[2][2];
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      int sum = 0;
      for(int k = 0; k < 2; k++) {
	sum += m[i][k] * n[k][j];
      }
      v[i][j] = sum;
    }
  }
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      m[i][j] = v[i][j];
}
