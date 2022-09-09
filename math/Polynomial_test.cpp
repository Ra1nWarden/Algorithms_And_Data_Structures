#include "gtest/gtest.h"
#include "Polynomial.h"

using namespace std;


TEST(Polynomial, Zero) {
  vector<int> f{3};
  vector<int> g{1};
  vector<int> calc = PolynomialMultiply(f, g);
  vector<int> ans{3};
  EXPECT_EQ(ans.size(), calc.size());
  for(int i = 0; i < ans.size(); i++) {
    EXPECT_EQ(ans[i], calc[i]);
  }
}

TEST(Polynomial, One) {
  vector<int> f{1, 2, 3};
  vector<int> g{1, 1};
  vector<int> calc = PolynomialMultiply(f, g);
  vector<int> ans{1, 3, 5, 3};
  EXPECT_EQ(ans.size(), calc.size());
  for(int i = 0; i < ans.size(); i++) {
    EXPECT_EQ(ans[i], calc[i]);
  }
}

TEST(Polynomial, Two) {
  vector<int> f{1, 0, 2};
  vector<int> g{0, 1};
  vector<int> calc = PolynomialMultiply(f, g);
  vector<int> ans{0, 1, 0, 2};
  EXPECT_EQ(ans.size(), calc.size());
  for(int i = 0; i < ans.size(); i++) {
    EXPECT_EQ(ans[i], calc[i]);
  }
}


TEST(Polynomial, Three) {
  vector<int> f{1, 2, 3};
  vector<int> g{2, 3, 4};
  vector<int> calc = PolynomialMultiply(f, g);
  vector<int> ans{2, 7, 16, 17, 12};
  EXPECT_EQ(ans.size(), calc.size());
  for(int i = 0; i < ans.size(); i++) {
    EXPECT_EQ(ans[i], calc[i]);
  }
}
