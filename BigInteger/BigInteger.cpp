#include "BigInteger.h"
#include <cstdlib>

ostream& operator<<(ostream& oss, const BigInteger& rhs) {
  if(!rhs.positive)
    oss << "-";
  for(int i = 0; i < rhs.digits.size(); i++) {
    oss << rhs.digits[rhs.digits.size() - i - 1];
  }
  return oss;
}

// Initialize to zero, positive is default to true
BigInteger::BigInteger() {
  digits.push_back(0);
  positive = true;
}

BigInteger::BigInteger(string num) {
  positive = num[0] == '-' ? false : true;
  if(!positive)
    num = num.substr(1);
  digits.resize(num.length());
  for(int i = 0; i < num.length(); i++) {
    digits[num.length() - i - 1] = atoi(num.substr(i, 1).c_str());
  }
}

BigInteger BigInteger::operator=(const BigInteger& rhs) {
  BigInteger result;
  result.positive = rhs.positive;
  result.digits = rhs.digits;
  return result;
}

bool BigInteger::operator<(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    if(positive) {
      if(digits.size() != rhs.digits.size()) {
	return digits.size() < rhs.digits.size();
      } else {
	for(int i = digits.size() - 1; i >= 0; i--) {
	  if(digits[i] != rhs.digits[i])
	    return digits[i] < rhs.digits[i];
	}
	return false;
      }
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return dummylhs > dummyrhs;
    }
  } else {
    return !positive;
  }
}

bool BigInteger::operator>(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    if(positive) {
      if(digits.size() != rhs.digits.size()) {
	return digits.size() > rhs.digits.size();
      } else {
	for(int i = digits.size() - 1; i >= 0; i--) {
	  if(digits[i] != rhs.digits[i])
	    return digits[i] > rhs.digits[i];
	}
	return false;
      }
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return dummylhs < dummyrhs;
    }
  } else {
    return positive;
  }
}

bool BigInteger::operator==(const BigInteger& rhs) const {
  if(digits.size() == 1 && digits[0] == 0 && rhs.digits.size() == 1 && rhs.digits[0] == 0) {
    return true;
  }
  return positive == rhs.positive && digits == rhs.digits;
}

bool BigInteger::operator<=(const BigInteger& rhs) const {
  return *this < rhs || *this == rhs;
}

bool BigInteger::operator>=(const BigInteger& rhs) const {
  return *this > rhs || *this == rhs;
}

bool BigInteger::operator!=(const BigInteger& rhs) const {
  return !(*this == rhs);
}

BigInteger& BigInteger::operator++() {
  BigInteger one("1");
  BigInteger sum = (*this + one);
  positive = sum.positive;
  digits = sum.digits;
  return *this;
}

BigInteger BigInteger::operator++(int) {
  BigInteger copy = *this;
  operator++();
  return copy;
}

BigInteger& BigInteger::operator--() {
  BigInteger one("1");
  BigInteger sum = *this - one;
  positive = sum.positive;
  digits = sum.digits;
  return *this;
}

BigInteger BigInteger::operator--(int) {
  BigInteger copy = *this;
  operator--();
  return copy;
}

BigInteger BigInteger::operator-() {
  BigInteger result = *this;
  result.positive = !result.positive;
  return result;
}

BigInteger BigInteger::operator+(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    BigInteger result;
    result.positive = positive;
    result.digits.resize(max(digits.size(), rhs.digits.size()), 0);
    bool carry = false;
    for(int i = 0; i < result.digits.size(); i++) {
      result.digits[i] = 0;
      if(i < digits.size())
	result.digits[i] += digits[i];
      if(i < rhs.digits.size())
	result.digits[i] += rhs.digits[i];
      if(carry)
	result.digits[i]++;
      carry = result.digits[i] > 9;
      result.digits[i] %= 10;
    }
    if(carry)
      result.digits.push_back(1);
    return result;
  } else {
    if(positive) {
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return *this - dummyrhs;
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      return rhs - dummylhs;
    }
  }
}

BigInteger BigInteger::operator-(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    if(positive) {
      BigInteger result;
      result.positive = *this >= rhs;
      result.digits.clear();
      BigInteger large = max(*this, rhs);
      BigInteger small = min(*this, rhs);
      bool reduce = false;
      for(int i = 0; i < large.digits.size(); i++) {
	int up = large.digits[i];
	int down = 0;
	if(i < small.digits.size())
	  down = small.digits[i];
	if(reduce) {
	  up--;
	  reduce = false;
	}
	if(up < down) {
	  up += 10;
	  reduce = true;
	}
	result.digits.push_back(up - down);
      }
      // Remove leading zeros
      for(int i = result.digits.size() - 1; i >= 0; i--) {
	if(result.digits[i] != 0) {
	  result.digits.resize(i + 1);
	  break;
	}
      }
      return result;
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return dummyrhs - dummylhs;
    }
  } else {
    if(positive) {
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return *this + dummyrhs;
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      return -(dummylhs + rhs);
    }
  }
}
