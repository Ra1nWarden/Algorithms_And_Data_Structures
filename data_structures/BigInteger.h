#ifndef DATA_STRUCTURE_BIGINTEGER_H_
#define DATA_STRUCTURE_BIGINTEGER_H_

#include <vector>
#include <iostream>

using namespace std;

struct BigInteger {
  vector<int> digits;
  bool positive;

  BigInteger();
  BigInteger(string num);
  BigInteger(long long num);
  BigInteger(const BigInteger& cpy);
  BigInteger& operator=(const BigInteger& rhs);
  
  bool operator<(const BigInteger& rhs) const;
  bool operator>(const BigInteger& rhs) const;
  bool operator<=(const BigInteger& rhs) const;
  bool operator>=(const BigInteger& rhs) const;
  bool operator!=(const BigInteger& rhs) const;
  bool operator==(const BigInteger& rhs) const;

  BigInteger& operator++();
  BigInteger operator++(int);
  BigInteger& operator--();
  BigInteger operator--(int);
  BigInteger operator-();
  BigInteger operator+(const BigInteger& rhs) const;
  BigInteger operator-(const BigInteger& rhs) const;
  BigInteger operator*(const BigInteger& rhs) const;
  BigInteger operator/(const BigInteger& rhs) const;
  BigInteger operator%(const BigInteger& rhs) const;
  BigInteger& operator+=(const BigInteger& rhs);
  BigInteger& operator-=(const BigInteger& rhs);
  BigInteger& operator*=(const BigInteger& rhs);
  BigInteger& operator/=(const BigInteger& rhs);
  BigInteger& operator%=(const BigInteger& rhs);
};

ostream& operator<<(ostream& oss, const BigInteger& rhs);
istream& operator>>(istream& iss, BigInteger& rhs);

#endif
