#ifndef ALGORITHM_GCDLCM_H_
#define ALGORITHM_GCDLCM_H_

#include <utility>
#include <vector>

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
// Let d = gcd(a, b), there is NO such solutions if d does not divide c
// ATTENTION: This function assumes that d divides c
// More solutions can be found using x = x0 + (b/d)n and y = y0 - (a/d)n
// ExtendedEuclid is the helper function to find the first solution when c = d

// Accoring to UVA 10104, the pair of solutions returned from this funciton
// satisfy the fact that |x| + |y| is minimal
pair<int, int> ExtendedEuclid(int a, int b);
pair<int, int> SolveDiophantine(int a, int b, int c);

// OR the following function that does both
// d is the gcd of a and b
// x and y are solutions to ax + by = gcd(a, b) = d
void GreatestCommonDivisor(int a, int b, int& d, int& x, int& y);

// Euclid's algorithm on polynomials to find the largest power polynomial that divideds both.
// a and b are vectors of coefficient starting from the largest power.
// The returned vector c is in the same format as a and b.
vector<int> PolynomialGreatestCommonDivisor(vector<int> a, vector<int> b, int mod);

#endif
