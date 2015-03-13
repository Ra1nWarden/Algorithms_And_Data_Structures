#include "gtest/gtest.h"
#include "AhoCorasickAutomata.h"
#include <algorithm> // Sort the res vector for testing purpose

using namespace std;

char pat1[] = "abc";
char pat2[] = "ab";
char pat3[] = "bc";
char pat4[] = "ac";
char pat5[] = "ca";

TEST(AhoCorasickAutomata, NoMatch) {
  AhoCorasickAutomata ac;
  ac.insert(pat1, 1);
  ac.insert(pat2, 2);
  ac.insert(pat3, 3);
  ac.init();
  char str[] = "aaaaa";
  vector<int> res = ac.find(str);
  EXPECT_TRUE(res.empty());
}

TEST(AhoCorasickAutomata, NoMatchPartial) {
  AhoCorasickAutomata ac;
  ac.insert(pat1, 1);
  ac.insert(pat2, 2);
  ac.insert(pat3, 3);
  ac.init();
  char str[] = "a";
  vector<int> res = ac.find(str);
  EXPECT_TRUE(res.empty());
}

TEST(AhoCorasickAutomata, SingleMatch) {
  AhoCorasickAutomata ac;
  ac.insert(pat1, 1);
  ac.insert(pat2, 2);
  ac.insert(pat3, 3);
  ac.init();
  char str[] = "xfeabe";
  vector<int> res = ac.find(str);
  ASSERT_EQ(1, res.size());
  EXPECT_EQ(2, res[0]);
}

TEST(AhoCorasickAutomata, MultipleMatches) {
  AhoCorasickAutomata ac;
  ac.insert(pat1, 1);
  ac.insert(pat2, 2);
  ac.insert(pat3, 3);
  ac.insert(pat4, 4);
  ac.init();
  char str[] = "seabcfe";
  vector<int> res = ac.find(str);
  ASSERT_EQ(3, res.size());
  sort(res.begin(), res.end());
  EXPECT_EQ(1, res[0]);
  EXPECT_EQ(2, res[1]);
  EXPECT_EQ(3, res[2]);
}

TEST(AhoCorasickAutomata, MultipleMatchesRepeated) {
  AhoCorasickAutomata ac;
  ac.insert(pat1, 1);
  ac.insert(pat2, 2);
  ac.insert(pat3, 3);
  ac.insert(pat4, 4);
  ac.insert(pat5, 5);
  ac.init();
  char str[] = "abcabc";
  vector<int> res = ac.find(str);
  ASSERT_EQ(7, res.size());
  sort(res.begin(), res.end());
  EXPECT_EQ(1, res[0]);
  EXPECT_EQ(1, res[1]);
  EXPECT_EQ(2, res[2]);
  EXPECT_EQ(2, res[3]);
  EXPECT_EQ(3, res[4]);
  EXPECT_EQ(3, res[5]);
  EXPECT_EQ(5, res[6]);
}
