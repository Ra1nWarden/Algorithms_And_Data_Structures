#include "gtest/gtest.h"
#include "KMP.h"
#include <cstring>

using namespace std;

TEST(KMP, SingleMatch) {
  KMP kmp;
  char p[] = "abc";
  char s[] = "fejhuixcabcdwuhwl";
  memcpy(kmp.pattern, p, sizeof p);
  memcpy(kmp.str, s, sizeof s);
  vector<int> res = kmp.match();
  ASSERT_EQ(1, res.size());
  EXPECT_EQ(8, res[0]);
}

TEST(KMP, MultipleMatches) {
  KMP kmp;
  char p[] = "aab";
  char s[] = "feaabaabaabaabjuhaab";
  memcpy(kmp.pattern, p, sizeof p);
  memcpy(kmp.str, s, sizeof s);
  vector<int> res = kmp.match();
  ASSERT_EQ(5, res.size());
  EXPECT_EQ(2, res[0]);
  EXPECT_EQ(5, res[1]);
  EXPECT_EQ(8, res[2]);
  EXPECT_EQ(11, res[3]);
  EXPECT_EQ(17, res[4]);
}

TEST(KMP, MultipleMatchesOverlap) {
  KMP kmp;
  char p[] = "aa";
  char s[] = "abcefuheaaajefaaaa";
  memcpy(kmp.pattern, p, sizeof p);
  memcpy(kmp.str, s, sizeof s);
  vector<int> res = kmp.match();
  ASSERT_EQ(5, res.size());
  EXPECT_EQ(8, res[0]);
  EXPECT_EQ(9, res[1]);
  EXPECT_EQ(14, res[2]);
  EXPECT_EQ(15, res[3]);
  EXPECT_EQ(16, res[4]);
}

TEST(KMP, NoMatches) {
  KMP kmp;
  char p[] = "aa";
  char s[] = "abababababa";
  memcpy(kmp.pattern, p, sizeof p);
  memcpy(kmp.str, s, sizeof s);
  vector<int> res = kmp.match();
  EXPECT_EQ(0, res.size());
}

