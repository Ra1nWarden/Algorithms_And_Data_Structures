#ifndef ALGORITHM_STRING_PROCESSING_MISCELLANEOUS_H_
#define ALGORITHM_STRING_PROCESSING_MISCELLANEOUS_H_

#include <string>
#define MAXN 1010

using namespace std;

int MinimumRepresentation(string s);

// A hash function for LCP queries (See taining guide p.224)
struct Hash {
  const int x = 123; // Any random value.
  int n;
  char s[MAXN];
  unsigned long long h[MAXN], xp[MAXN], hash[MAXN];
  Hash(string str);
  void init();
  // Hash value for string starting at i with length l
  unsigned long long hashSubstring(int i, int l);
};

// Manacher algorithm that finds the longest palindrome
struct Manacher {
  int id, len, maxlen;
  string word;
  char ch[MAXN];
  int p[MAXN];
  Manacher(string word);
  int solve();
};

#endif
