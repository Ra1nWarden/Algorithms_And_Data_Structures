#include "Primes.h"
#include "ModularArithmetic.h"
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

vector<int> EulerPhiArr(int x) {
  vector<int> primes;
  vector<int> ans(x + 1, 0);
  ans[1] = 1;
  for(int i = 2; i <= x; i++) {
    if(ans[i] == 0) {
      ans[i] = i - 1;
      primes.push_back(i);
    }
    for(int j = 0; j < primes.size(); j++) {
      if(i * primes[j] > x) {
	break;
      }
      if(i % primes[j] == 0) {
	// phi(i * primes[j]) = primes[j] * phi(i)
	ans[i * primes[j]] = ans[i] * primes[j]; 
	break;
      } else {
	// phi(i * primes[j]) = phi(i) * phi(primes[j]) when gcd(i, primes[j]) = 1
	ans[i * primes[j]] = ans[i] * ans[primes[j]];
      }
    }
  }
  return ans;
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

bool MillerRabinHelper(int a, int n, int x, int t) {
  int ret = PowerModular(a, x, n);
  int last = ret;
  for(int i = 1; i <= t; i++) {
    ret = PowerModular(ret, 2, n);
    if(ret == 1 && last != 1 && last != n - 1) {
      return true;
    }
    last = ret;
  }
  return ret != 1;
}

bool MillerRabinIsPrime(int n) {
  if(n < 2)
    return false;
  if(n == 2)
    return true;
  if(!(n & 1))
    return false;
  int x = n - 1;
  int t = 0;
  while(!(x & 1)) {
    x >>= 1;
    t++;
  }
  srand(time(NULL));
  for(int i = 0; i < S; i++) {
    int a = rand() % (n - 1) + 1;
    if(MillerRabinHelper(a, n, x, t)) {
      return false;
    }
  }
  return true;
}
