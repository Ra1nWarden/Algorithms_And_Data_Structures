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

Manacher::Manacher(string word) : word(word) {
  len = word.length();
  id = 0;
  maxlen = 0;
  for(int i = len; i >= 0; i--) {
    ch[i+i+2] = i == len ? '\0' : word[i];
    ch[i+i+1] = '#';
  }
  ch[0] = '$'; // ch[0] and ch[2*len+2] must be different character and this prevents out-of-bound error.
  memset(p, 0, sizeof p);
}

int Manacher::solve() {
  for(int i = 2; i < 2 * len + 1; i++) {
    if(p[id] + id > i)
      p[i] = min(p[2 * id - i], p[id] + id - i);
    else
      p[i] = 1;
    while(ch[i - p[i]] == ch[i + p[i]])
      p[i]++;
    if(p[id] + id < i + p[i])
      id = i;
    maxlen = max(maxlen, p[i]);
  }
  return maxlen - 1;
}
