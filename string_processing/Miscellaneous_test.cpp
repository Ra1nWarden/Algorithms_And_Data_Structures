#include "gtest/gtest.h"
#include "Miscellaneous.h"

using namespace std;

TEST(MinimumRepresentation, SingleChar) {
  string str = "a";
  EXPECT_EQ(0, MinimumRepresentation(str));
}

TEST(MinimumRepresentation, ABCDEFG) {
  string str = "defgabc";
  EXPECT_EQ(4, MinimumRepresentation(str));
}

TEST(MinimumRepresentation, Repeated) {
  string str = "aaaaaaa";
  EXPECT_EQ(0, MinimumRepresentation(str));
}

TEST(MinimumRepresentation, SomeRepeated) {
  string str = "aabaaaa";
  EXPECT_EQ(3, MinimumRepresentation(str));
}
