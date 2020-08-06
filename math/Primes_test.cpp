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
  ASSERT_EQ(1, primes.size());
  EXPECT_EQ(2, primes[0]);
}

TEST(GeneratePrime, Twenty) {
  vector<int> primes = GeneratePrime(20);
  int expected[] = {2, 3, 5, 7, 11, 13, 17, 19};
  ASSERT_EQ(8, primes.size());
  for(int i = 0; i < primes.size(); i++) {
    EXPECT_EQ(expected[i], primes[i]);
  }
}

TEST(GeneratePrimeEulerSieve, Two) {
  vector<int> primes = GeneratePrimeEulerSieve(2);
  ASSERT_EQ(1, primes.size());
  EXPECT_EQ(2, primes[0]);
}

TEST(GeneratePrimeEulerSieve, Three) {
  vector<int> primes = GeneratePrimeEulerSieve(3);
  ASSERT_EQ(2, primes.size());
  EXPECT_EQ(2, primes[0]);
  EXPECT_EQ(3, primes[1]);
}

TEST(GeneratePrimeEulerSieve, Twenty) {
  vector<int> primes = GeneratePrimeEulerSieve(20);
  int expected[] = {2, 3, 5, 7, 11, 13, 17, 19};
  ASSERT_EQ(8, primes.size());
  for(int i = 0; i < primes.size(); i++) {
    EXPECT_EQ(expected[i], primes[i]);
  }
}

TEST(PrimeFactorize, One) {
  map<int, int> facts = PrimeFactorize(1);
  EXPECT_TRUE(facts.empty());
}

TEST(PrimeFactorize, Two) {
  map<int, int> facts = PrimeFactorize(2);
  EXPECT_EQ(1, facts[2]);
}

TEST(PrimeFactorize, Eight) {
  map<int, int> facts = PrimeFactorize(8);
  EXPECT_EQ(3, facts[2]);
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
  EXPECT_EQ(1, facts[17]);
}

TEST(EulerPhi, One) {
  EXPECT_EQ(1, EulerPhi(1));
}

TEST(EulerPhi, Two) {
  EXPECT_EQ(1, EulerPhi(2));
}

TEST(EulerPhi, Eight) {
  // 8 -> (1, 3, 5, 7)
  EXPECT_EQ(4, EulerPhi(8));
}

TEST(EulerPhi, Eighteen) {
  // 18 -> (1, 5, 7, 11, 13, 17)
  EXPECT_EQ(6, EulerPhi(18));
}

TEST(EulerPhi, Seventeen) {
  // 17 is prime so the result is 17 - 1 = 16 (17 is excluded)
  EXPECT_EQ(16, EulerPhi(17));
}

TEST(CountFactors, One) {
  EXPECT_EQ(1, CountFactors(1));
}

TEST(CountFactors, Eight) {
  EXPECT_EQ(4, CountFactors(8));
}

TEST(CountFactors, TwentyFour) {
  EXPECT_EQ(8, CountFactors(24));
}

TEST(CountFactors, Seventeen) {
  EXPECT_EQ(2, CountFactors(17));
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

TEST(MillerRabinIsPrime, One) {
  EXPECT_FALSE(IsPrime(1));
}

TEST(MillerRabinIsPrime, Two) {
  EXPECT_TRUE(IsPrime(2));
}

TEST(MillerRabinIsPrime, Eight) {
  EXPECT_FALSE(IsPrime(8));
}

TEST(MillerRabinIsPrime, Seventeen) {
  EXPECT_TRUE(IsPrime(17));
}

TEST(MillerRabinIsPrime, BigPrime) {
  EXPECT_TRUE(IsPrime(2147483647));
}

TEST(MillerRabinIsPrime, BigComposite) {
  EXPECT_FALSE(IsPrime(2147483645));
}
