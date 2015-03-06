#ifndef DATA_STRUCTURE_RATIONAL_H_
#define DATA_STRUCTURE_RATIONAL_H_

#include <iostream>

using namespace std;

struct Rational {
  long long num;
  long long denom;

  Rational();
  Rational(long long n, long long m);
  Rational operator=(const Rational& rhs);

  bool operator<(const Rational& rhs) const;
  bool operator>(const Rational& rhs) const;
  bool operator==(const Rational& rhs) const;
  bool operator<=(const Rational& rhs) const;
  bool operator>=(const Rational& rhs) const;
  bool operator!=(const Rational& rhs) const;

  Rational operator+(const Rational& rhs) const;
  Rational operator-(const Rational& rhs) const;
  Rational operator*(const Rational& rhs) const;
  Rational operator/(const Rational& rhs) const;
};

ostream& operator<<(ostream& oss, const Rational& rhs);

#endif
