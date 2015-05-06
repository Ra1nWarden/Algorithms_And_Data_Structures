#ifndef ALGORITHM_MODULAR_H_
#define ALGORITHM_MODULAR_H_

// Calculates a^n \equiv m
int PowerModular(int a, int n, int m);

// Solve equation ax \equiv b (mod n)
bool SolveModularEquation(int a, int b, int n, int& x);

#endif
