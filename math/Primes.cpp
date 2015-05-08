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

// Use global check array and another array with index to store primes.
vector<int> GeneratePrimeEulerSieve(int x) {
  bool check[x+1];
  memset(check, false, sizeof check);
  vector<int> result;
  for(int i = 2; i <= x; i++) {
    if(!check[i])
      result.push_back(i);
    for(int j = 0; j < result.size(); j++) {
      if(i * result[j] > x)
	break;
      check[i * result[j]] = true;
      if(i % result[j] == 0)
	break;
    }
  }
  return result;
} 

map<int, int> PrimeFactorize(int number) {
  map<int, int> result;
  for(int i = 2; i <= sqrt(number+0.5); i++) {
    if(number % i == 0) {
      int cnt = 0;
      while(number % i == 0) {
	number /= i;
	cnt++;
      }
      result[i] = cnt;
    }
  }
  if(number > 1)
    result[number] = 1;
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
