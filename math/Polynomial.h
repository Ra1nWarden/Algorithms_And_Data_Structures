#ifndef ALGORITHM_POLYNOMIAL_H_
#define ALGORITHM_POLYNOMIAL_H_

#include <vector>
#include <complex>

using namespace std;

typedef complex<double> Comp;

// Returns coefficients of the product of f and g
// f = f[0] * x_0 + f[1] * x_1
vector<int> PolynomialMultiply(vector<int> f, vector<int> g);

// FFT with divide and conquer
// O(n log n)
void FastFourierTransform(Comp* a, int n, int inv);

#endif
