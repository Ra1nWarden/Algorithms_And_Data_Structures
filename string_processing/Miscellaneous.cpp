#include "Miscellaneous.h"
#include <cstdlib>

using namespace std;

int MinimumRepresentation(string s) {
  int i = 0, j = 1, k = 0;
  int len = s.length();
  s += s; // If the string is too large, modify the indices of i+k and j+k.
  while(i < len && j < len) {
    k = 0;
    while(k < len && s[i+k] == s[j+k])
      k++;
    if(k >= len)
      break;
    if(s[i+k] > s[j+k])
      i = max(i+k+1, j+1);
    else
      j = max(i+1, j+k+1);
  }
  return min(i, j);
}

Hash::Hash(string str) {
  n = str.length();
  h[n] = 0;
  for(int i = n - 1; i > -1; i--)
    h[i] = h[i+1] * x + (str[i] - 'a');
  xp[0] = 1;
  for(int i = 1; i <= n; i++)
    xp[i] = xp[i-1] * x;
}

unsigned long long Hash::hashSubstring(int i, int l) {
  return h[i] - h[i+l] * xp[l];
}
