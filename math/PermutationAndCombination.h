#ifndef ALGORITHM_PERMUTATION_AND_COMBINATION_H_
#define ALGORITHM_PERMUTATION_AND_COMBINATION_H_

// a \ge 0
long long Factorial(long long a);

// a \ge b
long long Perm(long long a, long long b);

long long Combi(long long a, long long b);

long long Catalan(long long n);

long long CatalanR(long long n);

// Recursive function. Optimizable with memoization.
long long Derangement(long long n);

#endif
