#include "gtest/gtest.h"
#include "Rational.h"

Rational a(2, 4);
Rational b(1, 2);
Rational c(0, 2);
Rational e(13, 91);
Rational f(4, 2);
Rational g(1, 7);

TEST(Rational, DefaultConstructor) {
  Rational def;
  ASSERT_EQ(1, def.num);
  ASSERT_EQ(1, def.denom);
}

TEST(Rational, ConstructorWithArguments) {
  ASSERT_EQ(2, a.num);
  ASSERT_EQ(4, a.denom);
  ASSERT_EQ(13, e.num);
  ASSERT_EQ(91, e.denom);
}

TEST(Rational, CopyConstructor) {
  Rational atest = a;
  Rational etest = e;
  ASSERT_EQ(2, atest.num);
  ASSERT_EQ(4, atest.denom);
  ASSERT_EQ(13, etest.num);
  ASSERT_EQ(91, etest.denom);
}

TEST(Rational, LessThanOperator) {
  EXPECT_TRUE(e < a);
  EXPECT_TRUE(b < f);
  EXPECT_TRUE(e < f);
}

TEST(Rational, GreaterThanOperator) {
  EXPECT_TRUE(a > e);
  EXPECT_TRUE(f > b);
  EXPECT_TRUE(f > e);
}

TEST(Rational, EqualsOperator) {
  EXPECT_TRUE(a == b);
}

TEST(Rational, NotEqualsOperator) {
  EXPECT_TRUE(a != f);
}

TEST(Rational, LessThanOrEqualsOperator) {
  EXPECT_TRUE(e <= a);
  EXPECT_TRUE(b <= f);
  EXPECT_TRUE(e <= f);
  EXPECT_TRUE(a <= b);
}

TEST(Rational, GreaterThanOrEqualsOperator) {
  EXPECT_TRUE(a >= e);
  EXPECT_TRUE(f >= b);
  EXPECT_TRUE(f >= e);
  EXPECT_TRUE(b >= a);
}

TEST(Rational, AdditionOne) {
  Rational one;
  EXPECT_EQ(one, a + b);
  EXPECT_EQ(b, b + c);
}

TEST(Rational, AdditionTwo) {
  Rational ans(9, 14);
  EXPECT_EQ(ans, g + b);
  EXPECT_EQ(ans, g + a);
  EXPECT_EQ(ans, e + b);
  EXPECT_EQ(ans, e + a);
}

TEST(Rational, SubtractionOne) {
  Rational zero;
  zero.num = 0;
  EXPECT_EQ(zero, a - b);
  EXPECT_EQ(zero, b - a);
}

TEST(Rational, SubtractionTwo) {
  Rational ans(5, 14);
  EXPECT_EQ(ans, a - g);
  EXPECT_EQ(ans, b - g);
  EXPECT_EQ(ans, a - e);
  EXPECT_EQ(ans, b - e);
}

TEST(Rational, MultiplicationZero) {
  EXPECT_EQ(c, c * a);
  EXPECT_EQ(c, c * b);
}

TEST(Rational, MultiplicationOne) {
  Rational one;
  EXPECT_EQ(a, one * a);
  EXPECT_EQ(b, one * b);
}

TEST(Rational, MultiplicationTwo) {
  Rational ans(1, 14);
  EXPECT_EQ(ans, e * a);
  EXPECT_EQ(ans, e * b);
  EXPECT_EQ(ans, g * a);
  EXPECT_EQ(ans, g * b);
}

TEST(Rational, DivisionOne) {
  Rational one;
  EXPECT_EQ(a, a / one);
  EXPECT_EQ(b, b / one);
}

TEST(Rational, DivisionTwo) {
  Rational ans(1, 14);
  EXPECT_EQ(ans, e / f);
  EXPECT_EQ(ans, g / f);
}

TEST(Rational, DivisionThree) {
  Rational one;
  EXPECT_EQ(one, a / b);
  EXPECT_EQ(one, g / e);
}
