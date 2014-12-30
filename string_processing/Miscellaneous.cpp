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
