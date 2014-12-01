#include "GcdLcm.h"

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
