#include "gtest/gtest.h"
#include "SuffixArray.h"

using namespace std;

/*
acacag
acag
ag
cacag
cag
g
 */
const string str1 = "acacag";
const int sa1[] = {6, 0, 2, 4, 1, 3, 5};
const int ra1[] = {1, 4, 2, 5, 3, 6, 0};
const int height1[] = {0, 0, 3, 1, 0, 2, 0};

/*
$cab
aab$cab
ab
ab$cab
b
b$cab
cab
*/
const string str2 = "aab$cab";
const int sa2[] = {7, 3, 0, 5, 1, 6, 2, 4};
const int ra2[] = {2, 4, 6, 1, 7, 3, 5, 0};
const int height2[] = {0, 0, 0, 1, 2, 0, 1, 0};

TEST(DoubleAlgorithm, str1) {
  SuffixArray sa(str1);
  sa.BuildArrayDoubleAlgorithm('i');
  EXPECT_EQ(6, sa.n);
  for(int i = 0; i <= 6; i++) {
    EXPECT_EQ(sa1[i], sa.sa[i]);
    EXPECT_EQ(ra1[i], sa.ra[i]);
    EXPECT_EQ(height1[i], sa.height[i]);
  }
}

TEST(DoubleAlgorithm, str2) {
  SuffixArray sa(str2);
  sa.BuildArrayDoubleAlgorithm('e');
  EXPECT_EQ(7, sa.n);
  for(int i = 0; i <= 7; i++) {
    EXPECT_EQ(sa2[i], sa.sa[i]);
    EXPECT_EQ(ra2[i], sa.ra[i]);
    EXPECT_EQ(height2[i], sa.height[i]);
  }
}
