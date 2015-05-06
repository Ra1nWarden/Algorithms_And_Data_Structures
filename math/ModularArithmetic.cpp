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
