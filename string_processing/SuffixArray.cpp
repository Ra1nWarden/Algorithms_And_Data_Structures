#include "SuffixArray.h"
#include <cstdlib>

using namespace std;

// When combining multiple strings, connect them with characters that do not appear in the string
// They do not have to be smaller than all the values in str[]. No negative values!
SuffixArray::SuffixArray(string line) {
  for(int i = 0; i < line.length(); i++) {
    str[i] = line[i];
  }
  str[line.length()] = 0; // Null terminated.
  n = line.length(); // Init length
}

// m is the upper bound for the characters in str[]
void SuffixArray::BuildArrayDoubleAlgorithm(int m) {
  n++;
  int i, j, p, *x = t1, *y = t2;
  for(i = 0; i < m; i++) c[i] = 0;
  for(i = 0; i < n; i++) c[x[i] = str[i]]++;
  for(i = 1; i < m; i++) c[i] += c[i-1];
  for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
  for(j = 1; j <= n; j <<= 1) {
    p = 0;
    for(i = n-j; i < n; i++) y[p++] = i;
    for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[y[i]]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1; x[sa[0]] = 0;
    for(i = 1; i < n; i++)
      x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? p - 1 : p++;
    if(p >= n) break;
    m = p;
  }
  int k = 0;
  n--;
  for(i = 0; i <= n; i++) ra[sa[i]] = i;
  for(i = 0; i < n; i++) {
    if(k) k--;
    j = sa[ra[i] - 1];
    while(str[i+k] == str[j+k]) k++;
    height[ra[i]] = k;
  }
}
