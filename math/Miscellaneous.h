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

#endif
