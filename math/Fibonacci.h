#ifndef ALGORITHM_MATH_FIBONACCI_H_
#define ALGORITHM_MATH_FIBONACCI_H_

using namespace std;

struct Fibonacci {
  Fibonacci();
  int sum(int n);
  int val(int n);
  void power(int m[2][2], int n);
  void mult(int m[2][2], int n[2][2]);
};

#endif
