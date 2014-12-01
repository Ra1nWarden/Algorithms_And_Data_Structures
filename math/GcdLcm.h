#ifndef ALGORITHM_GCDLCM_H_
#define ALGORITHM_GCDLCM_H_

#include <utility>

using namespace std;

// Returns the greatest common divisor of a and b
// e.g. (1, 2) -> 1
// e.g. (4, 8) -> 4
int GreatestCommonDivisor(int a, int b);

// Returns the least common multiple of a and b
// e.g. (1, 2) -> 2
// e.g. (4, 8) -> 8
int LeastCommonMultiple(int a, int b);

// Returns a pair of integer solutions x, y of the equation ax + by = c
// Let d = gcd(x, y), there is NO such solutions if d does not divide c
// ATTENTION: This function assumes that d divides c
// More solutions can be found using x = x0 + (b/d)n and y = y0 - (a/d)n
// ExtendedEuclid is the helper function to find the first solution
pair<int, int> ExtendedEuclid(int a, int b);
pair<int, int> SolveDiophantine(int a, int b, int c);

#endif
