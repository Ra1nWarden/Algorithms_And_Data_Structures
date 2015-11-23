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
  int i, j, k, col, max_r;
  for(k = 0, col = 0; k < equ && col < var; k++, col++) {
    max_r = k;
    for(i = k+1; i < equ; i++) {
      if(fabs(matrix[i][col]) > fabs(matrix[max_r][col]))
	max_r = i;
    }
    if(fabs(matrix[max_r][col]) < eps)
      return false;
    if(k != max_r) {
      for(j = col; j < var; j++) {
	swap(matrix[k][j], matrix[max_r][j]);
      }
      swap(x[k], x[max_r]);
    }
    x[k] /= matrix[k][col];
    for(j = col+1; j < var; j++)
      matrix[k][j] /= matrix[k][col];
    matrix[k][col] = 1;
    for(i = 0; i < equ; i++) {
      if(i != k) {
	x[i] -= x[k] * matrix[i][k];
	for(j = col+1; j < var; j++)
	  matrix[i][j] -= matrix[k][j] * matrix[i][col];
	matrix[i][col] = 0;
      }
    }
  }
  return true;
}
