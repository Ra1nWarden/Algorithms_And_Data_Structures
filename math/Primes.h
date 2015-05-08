#ifndef ALGORITHM_PRIMES_H_
#define ALGORITHM_PRIMES_H_

#include <vector>
#include <map>

using namespace std;

// Generates all prime numbers less than x (exclusive). Runs in O(x log log x)
vector<int> GeneratePrime(int x);
// Generates all prime numbers using Euler's linear sieve no more than x (inclusive). Runs in O(x)
vector<int> GeneratePrimeEulerSieve(int x);

// Generates prime factorization of x in a map
// key is the prime factor and the value is the corresponding power
// e.g. 10 -> <2, 1>, <5, 1>
// e.g. 8 -> <2, 3>
// WARNING: when x == 1, this function returns an empty map
map<int, int> PrimeFactorize(int x);

// Count the number of numbers that are coprime with x
// e.g. 8 -> 4 (1, 3, 5, 7)
// e.g. 1 -> 1 (1)
int EulerPhi(int x);

// Count the number of factors of x
// e.g. 8 -> 4 (1, 2, 4, 8)
// e.g. 24 -> 8 (1, 2, 3, 4, 6, 8, 12, 24)
int CountFactors(int x);

// Returns whether x is a prime number
bool IsPrime(int x);

#endif
