#include "GcdLcm.h"
#include "ModularArithmetic.h"

int GreatestCommonDivisor(int a, int b) {
  return b == 0 ? a : GreatestCommonDivisor(b, a % b);
}

int LeastCommonMultiple(int a, int b) {
  return a * (b / GreatestCommonDivisor(a, b));
}

pair<int, int> ExtendedEuclid(int a, int b) {
  if(b == 0) {
    return make_pair(1, 0);
  }
  pair<int, int> prev = ExtendedEuclid(b, a % b);
  int x1 = prev.second;
  int y1 = prev.first - (a / b) * prev.second;
  return make_pair(x1, y1);
}

pair<int, int> SolveDiophantine(int a, int b, int c) {
  pair<int, int> sol = ExtendedEuclid(a, b);
  int result = sol.first * a + sol.second * b;
  return make_pair(sol.first * c / result, sol.second * c / result);
}

void GreatestCommonDivisor(int a, int b, int& d, int& x, int& y) {
  if(!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    GreatestCommonDivisor(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

vector<int> PolynomialGreatestCommonDivisor(vector<int> a, vector<int> b, int mod) {
  if(b.empty())
    return a;
  int t = a.size() - b.size();
  vector<int> c;
  for(int i = 0; i <= t; i++) {
    int inv = a[i] * ModularInverse(b[0], mod) % mod;
    for(int j = 0; j < b.size(); j++) {
      a[i+j] = (a[i+j] - inv * b[j] % mod + mod) % mod;
    }
  }
  int p = -1;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != 0) {
      p = i;
      break;
    }
  }
  if(p >= 0) {
    for(int i = p; i < a.size(); i++) {
      c.push_back(a[i]);
    }
  }
  return PolynomialGreatestCommonDivisor(b, c, mod);
}
