#include "gtest/gtest.h"
#include "Primes.h"
#include <vector>
#include <map>

using namespace std;

TEST(GeneratePrime, Two) {
  vector<int> primes = GeneratePrime(2);
  EXPECT_TRUE(primes.empty());
}

TEST(GeneratePrime, Three) {
  vector<int> primes = GeneratePrime(3);
  EXPECT_EQ(primes.size(), 1);
  EXPECT_EQ(primes[0], 2);
}

TEST(GeneratePrime, Twenty) {
  vector<int> primes = GeneratePrime(20);
  int expected[] = {2, 3, 5, 7, 11, 13, 17, 19};
  EXPECT_EQ(primes.size(), 8);
  for(int i = 0; i < primes.size(); i++) {
    EXPECT_EQ(primes[i], expected[i]);
  }
}

TEST(PrimeFactorize, One) {
  map<int, int> facts = PrimeFactorize(1);
  EXPECT_EQ(facts[1], 1);
}

TEST(PrimeFactorize, Two) {
  map<int, int> facts = PrimeFactorize(2);
  EXPECT_EQ(facts[2], 1);
}

TEST(PrimeFactorize, Eight) {
  map<int, int> facts = PrimeFactorize(8);
  EXPECT_EQ(facts[2], 3);
}

TEST(PrimeFactorize,TwoThreeFiveSeven) {
  map<int, int> facts = PrimeFactorize(2*3*5*7);
  map<int, int> expect;
  expect[2] = 1;
  expect[3] = 1;
  expect[5] = 1;
  expect[7] = 1;
  for(map<int, int>::iterator itr = facts.begin(); itr != facts.end(); itr++) {
    EXPECT_EQ(expect[itr->first], itr->second);
  }
}

TEST(PrimeFactorize, Seventeen) {
  map<int, int> facts = PrimeFactorize(17);
  EXPECT_EQ(facts[17], 1);
}

TEST(EulerPhi, One) {
  EXPECT_EQ(EulerPhi(1), 1);
}

TEST(EulerPhi, Two) {
  EXPECT_EQ(EulerPhi(2), 1);
}

TEST(EulerPhi, Eight) {
  // 8 -> (1, 3, 5, 7)
  EXPECT_EQ(EulerPhi(8), 4);
}

TEST(EulerPhi, Eighteen) {
  // 18 -> (1, 5, 7, 11, 13, 17)
  EXPECT_EQ(EulerPhi(18), 6);
}

TEST(EulerPhi, Seventeen) {
  // 17 is prime so the result is 17 - 1 = 16 (17 is excluded)
  EXPECT_EQ(EulerPhi(17), 16);
}

TEST(CountFactors, One) {
  EXPECT_EQ(CountFactors(1), 1);
}

TEST(CountFactors, Eight) {
  EXPECT_EQ(CountFactors(8), 4);
}

TEST(CountFactors, TwentyFour) {
  EXPECT_EQ(CountFactors(24), 8);
}

TEST(CountFactors, Seventeen) {
  EXPECT_EQ(CountFactors(17), 2);
}

TEST(IsPrime, One) {
  EXPECT_FALSE(IsPrime(1));
}

TEST(IsPrime, Two) {
  EXPECT_TRUE(IsPrime(2));
}

TEST(IsPrime, Eight) {
  EXPECT_FALSE(IsPrime(8));
}

TEST(IsPrime, Seventeen) {
  EXPECT_TRUE(IsPrime(17));
}

TEST(IsPrime, BigPrime) {
  EXPECT_TRUE(IsPrime(2147483647));
}
