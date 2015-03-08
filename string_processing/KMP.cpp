#include "KMP.h"

using namespace std;

KMP::KMP() {};

void KMP::init() {
  int len = strlen(pattern);
  f[0] = f[1] = 0;
  for(int i = 1; i < len; i++) {
    int j = f[i];
    while(j && pattern[i] != pattern[j])
      j = f[j];
    f[i+1] = pattern[i] == pattern[j] ? j + 1 : 0;
  }
}

vector<int> KMP::match() {
  vector<int> res;
  int m = strlen(pattern);
  int n = strlen(str);
  init();
  int j = 0;
  for(int i = 0; i < n; i++) {
    while(j && str[i] != pattern[j])
      j = f[j];
    if(str[i] == pattern[j])
      j++;
    if(j == m) {
      res.push_back(i - m + 1);
      j = f[j];
    }
  }
  return res;
}
