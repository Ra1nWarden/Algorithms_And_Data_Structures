#include "Primes.h"
#include <cstring>
#include <cmath>
#include <map>
#include <vector>

vector<int> GeneratePrime(int upper) {
  bool slots[upper];
  memset(slots, true, sizeof slots);
  vector<int> result;
  for(int i = 2; i < upper; i++) {
    if(slots[i]) {
      result.push_back(i);
      for(int j = i + i; j < upper; j += i) {
	slots[j] = false;
      }
    }
  }
  return result;
}

map<int, int> PrimeFactorize(int number) {
  vector<int> primes = GeneratePrime((int) sqrt(number) + 2);
  map<int, int> result;
  int numbercopy = number;
  for(int i = 0; i < primes.size(); i++) {
    int nextPrime = primes[i];
    if(numbercopy % nextPrime == 0) {
      int count = 0;
      while(numbercopy % nextPrime == 0) {
	count++;
	numbercopy /= nextPrime;
      }
      result[nextPrime] = count;
    }
  }
  if(numbercopy != 1) {
    result[numbercopy] = 1;
  }
  // special case for 1
  if(number == 1) {
    result[1] = 1;
  }
  return result;
}

int EulerPhi(int number) {
  map<int, int> facts = PrimeFactorize(number);
  int result = number;
  for(map<int, int>::iterator itr = facts.begin(); itr != facts.end(); itr++) {
    // excluding the special case when number is 1
    if(itr->first != 1) {
      result = result / itr->first * (itr->first - 1);
    }
  }
  return result;
}

int CountFactors(int number) {
  map<int, int> facts = PrimeFactorize(number);
  int result = 1;
  for(map<int, int>::iterator itr = facts.begin(); itr != facts.end(); itr++) {
    if(itr->first != 1) {
      result *= (itr->second + 1);
    }
  }
  return result;
}

bool IsPrime(int number) {
  // special case for 1
  if(number == 1) {
    return false;
  }
  map<int, int> facts = PrimeFactorize(number);
  return facts[number] == 1;
}
