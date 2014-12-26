#include "gtest/gtest.h"
#include "Miscellaneous.h"

using namespace std;

int f0(int x) {
  return 1;
}

// 1 -> 2 -> 3 -> 4 -> 5 -> 3 -> 4 -> 5 ...
int f1(int x) {
  if(x < 5)
    return x + 1;
  else
    return 3;
}

TEST(FloydCycle, ConstantOne) {
  pair<int, int> result = FloydCycleFinding(f0, 1);
  EXPECT_EQ(make_pair(0, 1), result);
}

TEST(FloydCycle, ConstantZero) {
  pair<int, int> result = FloydCycleFinding(f0, 0);
  EXPECT_EQ(make_pair(1, 1), result);
}

TEST(FloydCycle, IncreaseOne) {
  pair<int, int> result = FloydCycleFinding(f0, 1);
  EXPECT_EQ(make_pair(0, 1), result);
}

TEST(FloydCycle, IncreaseTwo) {
  pair<int, int> result = FloydCycleFinding(f1, 1);
  EXPECT_EQ(make_pair(2, 3), result);
}
