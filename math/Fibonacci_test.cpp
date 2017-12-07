#include "gtest/gtest.h"
#include "Fibonacci.h"

using namespace std;

Fibonacci fib;

TEST(Fibonacci, Values) {
  EXPECT_EQ(1, fib.val(1));
  EXPECT_EQ(1, fib.val(2));
  EXPECT_EQ(2, fib.val(3));
  EXPECT_EQ(3, fib.val(4));
  EXPECT_EQ(5, fib.val(5));
  EXPECT_EQ(8, fib.val(6));
}

TEST(Fibonacci, Sums) {
  EXPECT_EQ(1, fib.sum(1));
  EXPECT_EQ(2, fib.sum(2));
  EXPECT_EQ(4, fib.sum(3));
  EXPECT_EQ(7, fib.sum(4));
  EXPECT_EQ(12, fib.sum(5));
  EXPECT_EQ(20, fib.sum(6));
}
