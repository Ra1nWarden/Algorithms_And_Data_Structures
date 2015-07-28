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

TEST(Hash, ABCABC) {
  Hash test("ABCABC");
  EXPECT_EQ(test.hashSubstring(0, 3), test.hashSubstring(3, 3));
  EXPECT_EQ(test.hashSubstring(0, 2), test.hashSubstring(3, 2));
  EXPECT_FALSE(test.hashSubstring(0, 1) == test.hashSubstring(0, 2));
  EXPECT_FALSE(test.hashSubstring(0, 2) == test.hashSubstring(2, 2));
}
