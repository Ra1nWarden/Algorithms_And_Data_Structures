#include "Miscellaneous.h"
#include <cmath>

pair<int, int> FloydCycleFinding(int (*f)(int), int x0) {
  int tortoise = f(x0), hare = f(f(x0));
  while(tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(f(hare));
  }
  int mu = 0;
  hare = tortoise;
  tortoise = x0;
  while(tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(hare);
    mu++;
  }
  int lambda = 1;
  hare = f(tortoise);
  while(tortoise != hare) {
    hare = f(hare);
    lambda++;
  }
  return make_pair(mu, lambda);
}

bool GaussElimination::Gauss() {
  int i, j, k, r;
  for(i = 0; i < n; i++) {
    r = i;
    for(j = i + 1; j < n; j++) {
      if(fabs(matrix[j][i]) > fabs(matrix[r][i]))
	r = j;
    }
    if(fabs(matrix[r][i]) < eps) {
      return false;
    }
    if(r != i) {
      for(j = 0; j < n; j++)
	swap(matrix[r][j], matrix[i][j]);
      swap(x[r], x[i]); // This line can be combined with the previous loop (j <= n) if x is included in matrix
    }
    // This loop can be combined with the next one (j = n) if x is included in the matrix as the last column
    for(k = i + 1; k < n; k++)
      x[k] -= matrix[k][i] / matrix[i][i] * x[i];
    for(j = n - 1; j >= i; j--)
      for(k = i + 1; k < n; k++)
	matrix[k][j] -= matrix[k][i] / matrix[i][i] * matrix[i][j];
  }
  for(i = n - 1; i >= 0; i--) {
    for(j = i + 1; j < n; j++)
      x[i] -= x[j] * matrix[i][j];
    x[i] /= matrix[i][i];
  }
  return true;
}

void GaussElimination::GaussJordan() {
  int i, j, k, r;
  for(i = 0; i < n; i++) {
    r = i;
    for(j = i + 1; j < n; j++) {
      if(fabs(matrix[j][i]) > fabs(matrix[r][i])) {
	r = j;
      }
    }
    if(fabs(matrix[r][i]) < eps)
      continue;
    if(r != i) {
      for(j = 0; j < n; j++)
	swap(matrix[r][j], matrix[i][j]);
      swap(x[r], x[i]); // This line can be combined with the previous loop (j <= n), if x is the last column of matrix.
    }
    for(k = 0; k < n; k++) {
      if(k != i) {
	x[k] -= matrix[k][i] / matrix[i][i] * x[i]; // This line can be combined with the next loop (j = n), if x is the last column of matrix.
	for(j = n - 1; j >=i; j--) {
	  matrix[k][j] -= matrix[k][i] / matrix[i][i] * matrix[i][j];
	}
      }
    }
  }
}

// Ignore this (Define the function to be integrated here.)
double SimpsonIntegral::f(double x) {
  return x * x;
}

double SimpsonIntegral::simpson(double a, double b) {
  double c = a + (b - a) / 2;
  return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}

double SimpsonIntegral::asr(double a, double b, double eps, double A) {
  double c = a + (b - a) / 2;
  double L = simpson(a, c), R = simpson(c, b);
  if(fabs(L + R - A) <= 15 * eps)
    return L + R + (L + R - A) / 15.0;
  return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}

double SimpsonIntegral::asr(double a, double b, double eps) {
  return asr(a, b, eps, simpson(a, b));
}
