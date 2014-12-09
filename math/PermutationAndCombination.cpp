#include "PermutationAndCombination.h"

long long Factorial(long long a) {
  long long result = 1;
  for(int i= 1; i <= a; i++)
    result *= i;
  return result;
}

long long Perm(long long a, long long b) {
  long long result = 1;
  for(int i = 0; i < b; i++)
    result *= a--;
  return result;
}

long long Combi(long long a, long long b) {
  // special case when b > a
  if(b > a) {
    return 0;
  }
  // Save some calculation by the fact 
  // a choose b = a choose (a - b)
  if(b > a / 2) {
    return Combi(a, b - a);
  }
  long long result = 1;
  for(long long i = 1; i <= b; i++) {
    result *= a--;
    result /= i;
  }
  return result;
}

long long Catalan(long long n) {
  return Combi(2*n, n) / (n+1);
}

long long CatalanR(long long n) {
  if(n == 0) {
    return 1;
  }
  return CatalanR(n - 1) * (4 * n - 2) / (n + 1);
}

long long Derangement(long long n) {
  if(n == 0) {
    return 1;
  }
  return n * Derangement(n-1) + (n % 2 == 0 ? 1 : -1);
}
