#ifndef DATA_STRUCTURE_SUFFIX_ARRAY_H_
#define DATA_STRUCTURE_SUFFIX_ARRAY_H_
#define MAXN 10000 // Maximum length (leave some room for overflow ~5)

#include <string>

using namespace std;

struct SuffixArray {
  // Fields in this struct can be set as global variables
  // sa: sorted suffix array, stores the starting index in the string
  // ra: rank array, the reverse mapping of sa
  // height: stores the length of longest common prefix between suffixes beginning with ra[i] and ra[i-1]
  // str: the string's representation in ASCII
  int t1[MAXN], t2[MAXN], c[MAXN], ra[MAXN], sa[MAXN], height[MAXN], str[MAXN];
  int n; // string length
  SuffixArray(string line);
  SuffixArray();
  void BuildArrayDoubleAlgorithm(int m);
  // see kuangbin's template for initRMQ, askRMQ, lcp if needed
};

#endif
