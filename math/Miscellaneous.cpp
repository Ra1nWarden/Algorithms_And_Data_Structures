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
