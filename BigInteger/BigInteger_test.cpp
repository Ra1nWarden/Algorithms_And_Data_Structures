#include "gtest/gtest.h"
#include "BigInteger.h"

static const string posnum1 = "2326675176257368192873981264861287357126868767846376487364343676";
static const string posnum2 = "123628767832674892876382756687783628532576325765";
static const string posnum3 = "2326675176257368192873981264861287357126868767846376487364343677";
static const string negnum1 = "-" + posnum1;
static const string negnum2 = "-" + posnum2;
static const string negnum3 = "-2326675176257368192873981264861287357126868767846376487364343675";

// posnum1 + posnum2
static const string possum1 = "2326675176257368316502749097536180233509625455630005019940669441";
// posnum1 + negnum2 = posnum1 - posnum2
static const string possum2 = "2326675176257368069245213432186394480744112080062747954788017911";
static const string negsum1 = "-" + possum1;
static const string negsum2 = "-" + possum2;

// posnum1 * posnum2
static const string posprod = "287643985187570107498271519246946098643282829054192121182028927993624518149891401376351468927525631834793612140";
static const string negprod = "-" + posprod;

TEST(BigIntegerConstructor, Default) {
  BigInteger num;
  ASSERT_EQ(1, num.digits.size());
  ASSERT_EQ(0, num.digits[0]);
}

TEST(BigIntegerConstructor, StringConstructorPosZero) {
  BigInteger num("0");
  ASSERT_EQ(1, num.digits.size());
  ASSERT_EQ(0, num.digits[0]);
}

TEST(BigIntegerConstructor, StringConstructorNegZero) {
  BigInteger num("-0");
  ASSERT_EQ(1, num.digits.size());
  ASSERT_EQ(0, num.digits[0]);
}

TEST(BigIntegerConstructor, StringConstructorPositive) {
  BigInteger num(posnum1);
  ASSERT_TRUE(num.positive);
  ASSERT_EQ(posnum1.length(), num.digits.size());
  int len = num.digits.size();
  for(int i = 0; i < posnum1.length(); i++) {
    ASSERT_EQ(posnum1[i] - '0', num.digits[len - i - 1]);
  }
}

TEST(BigIntegerConstructor, StringConstructorNegative) {
  BigInteger num(negnum1);
  EXPECT_FALSE(num.positive);
  string str = negnum1.substr(1);
  EXPECT_EQ(str.length(), num.digits.size());
  int len = num.digits.size();
  for(int i = 0; i < str.length(); i++) {
    EXPECT_EQ(str[i] - '0', num.digits[len - i - 1]);
  }
}

TEST(BigIntegerEqualTo, Positive) {
  BigInteger lhs(posnum1);
  BigInteger rhs(posnum1);
  ASSERT_TRUE(lhs == rhs);
}

TEST(BigIntegerEqualTo, Zero) {
  BigInteger lhs("0");
  BigInteger rhs("-0");
  ASSERT_TRUE(lhs == rhs);
}

TEST(BigIntegerEqualTo, Negative) {
  BigInteger lhs(negnum1);
  BigInteger rhs(negnum1);
  ASSERT_TRUE(lhs == rhs);
}


TEST(BigIntegerAssignment, Positive) {
  BigInteger num(posnum1);
  BigInteger copy = num;
  EXPECT_EQ(num, copy);
}

TEST(BigIntegerAssignment, Negative) {
  BigInteger num(negnum1);
  BigInteger copy = negnum1;
  EXPECT_EQ(num, copy);
}

TEST(BigIntegerLessThan, Positive) {
  BigInteger large(posnum1);
  BigInteger small(posnum2);
  EXPECT_LT(small, large);
  EXPECT_FALSE(large < small);
}

TEST(BigIntegerLessThan, Negative) {
  BigInteger small(negnum1);
  BigInteger large(negnum2);
  EXPECT_LT(small, large);
  EXPECT_FALSE(large < small);
}

TEST(BigIntegerLessThan, Cross) {
  BigInteger pos(posnum1);
  BigInteger neg(negnum1);
  EXPECT_LT(neg, pos);
  EXPECT_FALSE(pos < neg);
}

TEST(BigIntegerGreaterThan, Positive) {
  BigInteger large(posnum1);
  BigInteger small(posnum2);
  EXPECT_GT(large, small);
  EXPECT_FALSE(small > large);
}

TEST(BigIntegerGreaterThan, Negative) {
  BigInteger small(negnum1);
  BigInteger large(negnum2);
  EXPECT_GT(large, small);
  EXPECT_FALSE(small > large);
}

TEST(BigIntegerGreaterThan, Cross) {
  BigInteger pos(posnum1);
  BigInteger neg(negnum1);
  EXPECT_GT(pos, neg);
  EXPECT_FALSE(neg > pos);
}

TEST(BigIntegerNotEqual, Positive) {
  BigInteger pos1(posnum1);
  BigInteger pos2(posnum2);
  EXPECT_NE(pos1, pos2);
}

TEST(BigIntegerNotEqual, Negative) {
  BigInteger neg1(negnum1);
  BigInteger neg2(negnum2);
  EXPECT_NE(neg1, neg2);
}

TEST(BigIntegerNotEqual, Corss) {
  BigInteger pos(posnum1);
  BigInteger neg(negnum1);
  EXPECT_NE(pos, neg);
}

TEST(BigIntegerLessThanEqual, Positive) {
  BigInteger large(posnum1);
  BigInteger small(posnum2);
  EXPECT_LE(small, large);
  EXPECT_FALSE(large <= small);
}

TEST(BigIntegerLessThanEqual, Negative) {
  BigInteger small(negnum1);
  BigInteger large(negnum2);
  EXPECT_LE(small, large);
  EXPECT_FALSE(large <= small);
}

TEST(BigIntegerLessThanEqual, Equal) {
  BigInteger lhs(posnum1);
  BigInteger rhs(posnum1);
  EXPECT_LE(lhs, rhs);
}

TEST(BigIntegerLessThanEqual, Cross) {
  BigInteger pos(posnum1);
  BigInteger neg(negnum1);
  EXPECT_LE(neg, pos);
  EXPECT_FALSE(pos <= neg);
}

TEST(BigIntegerGreaterThanEqual, Positive) {
  BigInteger large(posnum1);
  BigInteger small(posnum2);
  EXPECT_GE(large, small);
  EXPECT_FALSE(small >= large);
}

TEST(BigIntegerGreaterThanEqual, Negative) {
  BigInteger small(negnum1);
  BigInteger large(negnum2);
  EXPECT_GE(large, small);
  EXPECT_FALSE(small >= large);
}

TEST(BigIntegerGreaterThanEqual, Equal) {
  BigInteger lhs(posnum1);
  BigInteger rhs(posnum1);
  EXPECT_GE(lhs, rhs);
}

TEST(BigIntegerGreaterThanEqual, Cross) {
  BigInteger pos(posnum1);
  BigInteger neg(negnum1);
  EXPECT_GE(pos, neg);
  EXPECT_FALSE(neg >= pos);
}

TEST(BigIntegerPreIncrement, Positive) {
  BigInteger lhs(posnum1);
  BigInteger rhs(posnum3);
  EXPECT_EQ(rhs, ++lhs);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerPreIncrement, Negative) {
  BigInteger lhs(negnum1);
  BigInteger rhs(negnum3);
  EXPECT_EQ(rhs, ++lhs);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerPostIncrement, Positive) {
  BigInteger lhs(posnum1);
  BigInteger rhs(posnum3);
  EXPECT_NE(rhs, lhs++);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerPostIncrement, Negative) {
  BigInteger lhs(negnum1);
  BigInteger rhs(negnum3);
  EXPECT_NE(rhs, lhs++);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerPreDecrement, Positive) {
  BigInteger lhs(posnum3);
  BigInteger rhs(posnum1);
  EXPECT_EQ(rhs, --lhs);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerPreDecrement, Negative) {
  BigInteger lhs(negnum3);
  BigInteger rhs(negnum1);
  EXPECT_EQ(rhs, --lhs);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerPostDecrement, Positive) {
  BigInteger lhs(posnum3);
  BigInteger rhs(posnum1);
  EXPECT_NE(rhs, lhs--);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerPostDecrement, Negative) {
  BigInteger lhs(negnum3);
  BigInteger rhs(negnum1);
  EXPECT_NE(rhs, lhs--);
  EXPECT_EQ(lhs, rhs);
}

TEST(BigIntegerNegation, Positive) {
  BigInteger lhs(posnum1);
  BigInteger rhs(negnum1);
  EXPECT_EQ(-lhs, rhs);
}

TEST(BigIntegerNegation, Zero) {
  BigInteger zero("0");
  EXPECT_EQ(zero, -zero);
}

TEST(BigIntegerNegation, Negative) {
  BigInteger lhs(negnum2);
  BigInteger rhs(posnum2);
  EXPECT_EQ(-lhs, rhs);
}

TEST(BigIntegerAddition, PositiveAndPositive) {
  BigInteger one(posnum1);
  BigInteger two(posnum2);
  BigInteger sum(possum1);
  EXPECT_EQ(sum, one + two);
}

TEST(BigIntegerAddition, PositiveAndNegative) {
  BigInteger one(posnum1);
  BigInteger two(negnum2);
  BigInteger sum(possum2);
  EXPECT_EQ(sum, one + two);
}

TEST(BigIntegerAddition, NegativeAndPositive) {
  BigInteger one(posnum1);
  BigInteger two(negnum2);
  BigInteger sum(possum2);
  EXPECT_EQ(sum, two + one);
}

TEST(BigIntegerAddition, NegativeAndNegative) {
  BigInteger one(negnum1);
  BigInteger two(negnum2);
  BigInteger sum(negsum1);
  EXPECT_EQ(sum, one + two);
}

TEST(BigIntegerAddition, Zero) {
  BigInteger one(posnum1);
  BigInteger zero("0");
  EXPECT_EQ(one, one + zero);
}

TEST(BigIntegerSubtraction, PositiveAndPositive) {
  BigInteger one(posnum1);
  BigInteger two(posnum2);
  BigInteger sum(possum2);
  EXPECT_EQ(sum, one - two);
}

TEST(BigIntegerSubtraction, PositiveAndNegative) {
  BigInteger one(posnum1);
  BigInteger two(negnum2);
  BigInteger sum(possum1);
  EXPECT_EQ(sum, one - two);
}

TEST(BigIntegerSubtraction, NegativeAndPositive) {
  BigInteger one(posnum1);
  BigInteger two(negnum2);
  BigInteger sum(negsum1);
  EXPECT_EQ(sum, two - one);
}

TEST(BigIntegerSubtraction, NegativeAndNegative) {
  BigInteger one(negnum1);
  BigInteger two(negnum2);
  BigInteger sum(negsum2);
  EXPECT_EQ(sum, one - two);
}

TEST(BigIntegerSubtraction, Zero) {
  BigInteger one(posnum1);
  BigInteger zero("0");
  EXPECT_EQ(one, one - zero);
}

TEST(BigIntegerProduct, PositiveAndPositive) {
  BigInteger one(posnum1);
  BigInteger two(posnum2);
  BigInteger prod(posprod);
  EXPECT_EQ(prod, one * two);
}

TEST(BigIntegerProduct, PositiveAndNegative) {
  BigInteger one(posnum1);
  BigInteger two(negnum2);
  BigInteger prod(negprod);
  EXPECT_EQ(prod, one * two);
}

TEST(BigIntegerProduct, NegativeAndNegative) {
  BigInteger one(negnum1);
  BigInteger two(negnum2);
  BigInteger prod(posprod);
  EXPECT_EQ(prod, one * two);
}

TEST(BigIntegerProduct, Zero) {
  BigInteger one(posnum1);
  BigInteger zero("0");
  EXPECT_EQ(zero, one * zero);
}

TEST(BigIntegerProduct, One) {
  BigInteger one("1");
  BigInteger two(posnum1);
  EXPECT_EQ(two, one * two);
}
