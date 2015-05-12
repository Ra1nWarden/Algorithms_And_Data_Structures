#include "Rational.h"
#include "../math/GcdLcm.h"
#include <cassert>

using namespace std;

// Default initialize a Rational to 1 / 1
Rational::Rational() {
  num = 1;
  denom = 1;
}

Rational::Rational(long long n, long long m) : num(n), denom(m) {
  assert(m != 0);
}

Rational Rational::operator=(const Rational& rhs) {
  Rational res;
  res.num = rhs.num;
  res.denom = rhs.denom;
  return res;
}

bool Rational::operator<(const Rational& rhs) const {
  long long common = LeastCommonMultiple(denom, rhs.denom);
  return num * (common / denom) < rhs.num * (common / rhs.denom);
}

bool Rational::operator>(const Rational& rhs) const {
  long long common = LeastCommonMultiple(denom, rhs.denom);
  return num * (common / denom) > rhs.num * (common / rhs.denom);
}

bool Rational::operator==(const Rational& rhs) const {
  long long selffactor = GreatestCommonDivisor(num, denom);
  long long rhsfactor = GreatestCommonDivisor(rhs.num, rhs.denom);
  return num / selffactor == rhs.num / rhsfactor && denom / selffactor == rhs.denom / rhsfactor;
}

bool Rational::operator<=(const Rational& rhs) const {
  return *this < rhs || *this == rhs;
}

bool Rational::operator>=(const Rational& rhs) const {
  return *this > rhs || *this == rhs;
}

bool Rational::operator!=(const Rational& rhs) const {
  return !(*this == rhs);
}

Rational Rational::operator+(const Rational& rhs) const {
  Rational res;
  res.denom = LeastCommonMultiple(denom, rhs.denom);
  res.num = num * (res.denom / denom) + rhs.num * (res.denom / rhs.denom);
  return res;
}

Rational Rational::operator-(const Rational& rhs) const {
  Rational res;
  res.denom = LeastCommonMultiple(denom, rhs.denom);
  res.num = num * (res.denom / denom) - rhs.num * (res.denom / rhs.denom);
  return res;
}

Rational Rational::operator*(const Rational& rhs) const {
  Rational res;
  res.num = num * rhs.num;
  res.denom = denom * rhs.denom;
  long long common = GreatestCommonDivisor(res.num, res.denom);
  res.num /= common;
  res.denom /= common;
  return res;
}

Rational Rational::operator/(const Rational& rhs) const {
  assert(rhs.num != 0);
  Rational rhscpy = rhs;
  swap(rhscpy.num, rhscpy.denom);
  return (*this) * rhscpy;
}

ostream& operator<<(ostream& oss, const Rational& rhs) {
  oss << rhs.num << "/" << rhs.denom << endl;
  return oss;
}
