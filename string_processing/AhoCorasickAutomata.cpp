#include "AhoCorasickAutomata.h"
#include <cstring>
#include <queue>
#include <cstdlib>

using namespace std;

AhoCorasickAutomata::AhoCorasickAutomata() {
  memset(trie[0], 0, sizeof trie[0]);
  memset(val, 0, sizeof val);
  node_count = 1;
}

void AhoCorasickAutomata::insert(char* pat, int v) {
  int len = strlen(pat);
  int cur = 0;
  for(int i = 0; i < len; i++) {
    char c = pat[i];
    // Due to assumption of all lower case letters
    if(trie[cur][c - 'a'] == 0) {
      trie[cur][c - 'a'] = node_count++;
      // Initialize the new Trie node
      memset(trie[node_count-1], 0, sizeof trie[node_count-1]);
    }
    cur = trie[cur][c - 'a'];
  }
  val[cur] = v;
}

void AhoCorasickAutomata::init() {
  queue<int> q;
  f[0] = 0;
  for(int c = 0; c < SIGMA_SIZE; c++) {
    int u = trie[0][c];
    if(u) {
      f[u] = 0;
      q.push(u);
      last[u] = 0;
    }
  }
  while(!q.empty()) {
    int r = q.front();
    q.pop();
    for(int c = 0; c < SIGMA_SIZE; c++) {
      int u = trie[r][c];
      if(!u) {
	trie[r][c] = trie[f[r]][c];
	continue;
      }
      q.push(u);
      int v = f[r];
      while(v && !trie[v][c])
	v = f[v];
      f[u] = trie[v][c];
      last[u] = val[f[u]] ? f[u] : last[f[u]];
    }
  }
}

vector<int> AhoCorasickAutomata::find(char* s) {
  vector<int> res;
  int len = strlen(s);
  int j = 0;
  for(int i = 0; i < len; i++) {
    // Due to assumption of all lower case letters
    j = trie[j][s[i] - 'a'];
    if(val[j]) {
      int add = j;
      while(add != 0) {
	res.push_back(val[add]);
	add = last[add];
      }
    } else if(last[j]) {
      int add = last[j];
      while(add != 0) {
	res.push_back(val[add]);
	add = last[add];
      }
    }
  }
  return res;
}
