#ifndef ALGORITHM_MODULAR_H_
#define ALGORITHM_MODULAR_H_

#include <vector>

using namespace std;

// Calculates a^n \equiv m
int PowerModular(int a, int n, int m);

// Solve equation ax \equiv b (mod n)
bool SolveModularEquation(int a, int b, int n, int& x);

// Calculates a choose b modular m where m is PRIME
int ChooseModularPrime(int a, int b, int p);

// Finds inverse of a mod n
int ModularInverse(int a, int n);

// Chinese Remainder Theorem
// x \equiv a_i \mod m_i
// NOTE: use long long to avoid overflow if necessary
int ChineseRemainderThm(vector<int> a, vector<int> m);

// Modular logarithm
// Find x for a^{x} \equiv b \mod n where n is prime
// Baby Step Giant Step algorithm
int BabyStepGiantStep(int a, int b, int n);

#endif
