#ifndef ALGORITHM_MODULAR_H_
#define ALGORITHM_MODULAR_H_

// Calculates a^n \equiv m
int PowerModular(int a, int n, int m);

// Solve equation ax \equiv b (mod n)
bool SolveModularEquation(int a, int b, int n, int& x);

// Calculates a choose b modular m where m is PRIME
int ChooseModularPrime(int a, int b, int p);

// Finds inverse of a mod n
int ModularInverse(int a, int n);

#endif
