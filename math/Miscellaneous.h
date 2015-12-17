#ifndef ALGORITHM_MATH_MISCELLANEOUS_H_
#define ALGORITHM_MATH_MISCELLANEOUS_H_

#include <utility>

using namespace std;

// Toirtoise and Hare Algorithm: finding cycles in interated function values
// Parameters (f, x0)
// f: function pointer to the function
// x0: start value
// Return (mu, lambda)
// mu: start of cycle
// lambda: length of cycle
pair<int, int> FloydCycleFinding(int (*f)(int), int x0);

// Gauss elimination for solving linear equations.
// Floating point version
const int maxn = 20;
const double eps = 1e-9;
struct GaussElimination {
  // matrix is the matrix for coefficients and x saves the constants on the RHS
  double matrix[maxn][maxn], x[maxn];
  int n; // n variables with n equations
  bool Gauss(); // Returns whether there is solution. x saves the answer
  void GaussJordan(); // No return value, for each row, there is only one non-zero value.
};

// Adaptive Simpson's Rule
// f(x) is a global function to be integrated.
struct SimpsonIntegral {
  double f(double x);
  double simpson(double a, double b);
  double asr(double a, double b, double eps, double A);
  // Main method, integrate f(x) from a to b with error eps.
  double asr(double a, double b, double eps);
};

#endif
