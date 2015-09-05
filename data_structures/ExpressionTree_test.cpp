#include "gtest/gtest.h"
#include "ExpressionTree.h"

string plus_minus[9] = {"3", "+", "4", "-", "2", "-", "1", "+", "10"};
string multiply_divide[11] = {"3", "*", "2", "/", "1", "*", "5", "/", "2", "/", "3"};
string no_paren_all_mix[13] = {"3", "+", "4", "/", "2", "-", "2", "*", "3", "*", "2", "+", "14"};
string paren_plus_minus[13] = {"3", "-", "(", "2", "+", "2", ")", "+", "(", "5", "-", "2", ")"};
string paren_multiply_divide[13] = {"3", "*", "(", "9", "/", "3", ")", "*", "(", "4", "/", "2", ")"};
string all_mix[13] = {"8", "+", "2", "*", "(", "3", "-", "1", ")", "-", "10", "/", "2"};

TEST(ExpressionTreeI, PlusMinus) {
  ExpressionTreeI exp(vector<string>(plus_minus, plus_minus + 9));
  EXPECT_EQ(14, exp.evaluate());
}

TEST(ExpressionTreeI, MultiplyDivide) {
  ExpressionTreeI exp(vector<string>(multiply_divide, multiply_divide + 11));
  EXPECT_EQ(5, exp.evaluate());
}

TEST(ExpressionTreeI, NoParenMix) {
  ExpressionTreeI exp(vector<string>(no_paren_all_mix, no_paren_all_mix + 13));
  EXPECT_EQ(7, exp.evaluate());
}

TEST(ExpressionTreeI, ParenPlusMinus) {
  ExpressionTreeI exp(vector<string>(paren_plus_minus, paren_plus_minus + 13));
  EXPECT_EQ(2, exp.evaluate());
}

TEST(ExpressionTreeI, ParenMultiplyDivide) {
  ExpressionTreeI exp(vector<string>(paren_multiply_divide, paren_multiply_divide + 13));
  EXPECT_EQ(18, exp.evaluate());
}

TEST(ExpressionTreeI, AllMix) {
  ExpressionTreeI exp(vector<string>(all_mix, all_mix + 13));
  EXPECT_EQ(7, exp.evaluate());
}

TEST(ExpressionTreeII, PlusMinus) {
  ExpressionTreeII exp(vector<string>(plus_minus, plus_minus + 9));
  EXPECT_EQ(14, exp.evaluate());
}

TEST(ExpressionTreeII, MultiplyDivide) {
  ExpressionTreeII exp(vector<string>(multiply_divide, multiply_divide + 11));
  EXPECT_EQ(5, exp.evaluate());
}

TEST(ExpressionTreeII, NoParenMix) {
  ExpressionTreeII exp(vector<string>(no_paren_all_mix, no_paren_all_mix + 13));
  EXPECT_EQ(7, exp.evaluate());
}

TEST(ExpressionTreeII, ParenPlusMinus) {
  ExpressionTreeII exp(vector<string>(paren_plus_minus, paren_plus_minus + 13));
  EXPECT_EQ(2, exp.evaluate());
}

TEST(ExpressionTreeII, ParenMultiplyDivide) {
  ExpressionTreeII exp(vector<string>(paren_multiply_divide, paren_multiply_divide + 13));
  EXPECT_EQ(18, exp.evaluate());
}

TEST(ExpressionTreeII, AllMix) {
  ExpressionTreeII exp(vector<string>(all_mix, all_mix + 13));
  EXPECT_EQ(7, exp.evaluate());
}

