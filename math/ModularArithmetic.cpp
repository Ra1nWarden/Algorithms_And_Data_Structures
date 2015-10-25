#include "ModularArithmetic.h"
#include "GcdLcm.h"
#include <iostream>

int PowerModular(int a, int n, int m) {
  if(n == 0)
    return 1;
  int x = PowerModular(a , n / 2, m);
  long long ans = (long long) x * x % m;
  if(n % 2 == 1)
    ans = ans * a % m;
  return (int) ans;
}

bool SolveModularEquation(int a, int b, int n, int& x) {
  int d;
  int k;
  GreatestCommonDivisor(a, n, d, x, k);
  if(b % d != 0) {
    return false;
  } else {
    x *= (b / d);
    while(x < 0)
      x += n;
    return true;
  }
}

int ChooseModularPrime(int a, int b, int p) {
  int num = 1;
  int denom = 1;
  for(int i = 1; i <= b; i++) {
    denom *= i;
    denom %= p;
    num *= (a-i+1);
    num %= p;
  }
  // This uses Little Fermat's Theorem so denom and p must be coprime.
  return num * PowerModular(denom, p-2, p) % p;
}

int ModularInverse(int a, int n) {
  int d, x, y;
  GreatestCommonDivisor(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}

int ChineseRemainderThm(vector<int> a, vector<int> m) {
  int M = 1, d, y, x = 0;
  for(int i = 0; i < m.size(); i++)
    M *= m[i];
  for(int i = 0; i < m.size(); i++) {
    int w = M / m[i];
    GreatestCommonDivisor(m[i], w, d, d, y);
    x = (x + y * w * a[i]) % M;
  }
  return (x + M) % M;
}
