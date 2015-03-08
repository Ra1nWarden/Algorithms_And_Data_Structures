#include "Trie.h"
#include <cstring>

using namespace std;

Trie::Trie() {
  nextnode = 1;
  memset(trie[0], 0, sizeof trie[0]);
}

void Trie::insert(char* w, int v) {
  int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    int nextchar = w[i];
    if(trie[cur][nextchar - 'a'] == 0) {
      memset(trie[nextnode], 0, sizeof trie[nextnode]);
      trie[cur][nextchar - 'a'] = nextnode;
      val[nextnode] = 0; // Default value along the way: 0 in this case
      nextnode++;
    }
    cur = trie[cur][nextchar - 'a'];
  }
  val[cur] = v;
}

int Trie::find(char* w) {
  int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    int nextchar = w[i];
    cur = trie[cur][nextchar - 'a'];
    if(cur == 0)
      return 0; // Not found, return 0
  }
  return val[cur];
}

void Trie::del(char* w) {
  int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    int nextchar = w[i];
    cur = trie[cur][nextchar - 'a'];
    if(cur == 0)
      return; // Not found, not deleting anything, return
  }
  val[cur] = 0; // Found, reset value to 0
}

TrieChildBrother::TrieChildBrother() {
  nextnode = 1;
  lchild[0] = bro[0] = val[0] = 0;
}

void TrieChildBrother::insert(char* w, int v) {
  int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    int nextchar = w[i];
    int child = lchild[cur];
    bool found = false;
    while(bro[child] != 0) {
      if(ch[child] == nextchar) {
	cur = child;
	found = true;
	break;
      }
      child = bro[child];
    }
    if(ch[child] == nextchar) {
      found = true;
      cur = child;
    }
    if(!found) {
      int newnode = nextnode++;
      if(child != 0)
	bro[child] = newnode;
      else
	lchild[cur] = newnode;
      bro[newnode] = 0;
      lchild[newnode] = 0;
      val[newnode] = 0;
      ch[newnode] = nextchar;
      cur = newnode;
    }
  }
  val[cur] = v;
}

int TrieChildBrother::find(char* w) {
  int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    char nextchar = w[i];
    bool found = false;
    int child = lchild[cur];
    while(child != 0) {
      if(ch[child] == nextchar)
	break;
      child = bro[child];
    }
    if(child == 0)
      return 0; // Not found, return -1
    cur = child;
  }
  return val[cur];
}

void TrieChildBrother::del(char* w) {
    int cur = 0;
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    char nextchar = w[i];
    bool found = false;
    int child = lchild[cur];
    while(child != 0) {
      if(ch[child] == nextchar)
	break;
      child = bro[child];
    }
    if(child == 0)
      return; // Not found, return -1
    cur = child;
  }
  val[cur] = 0; // Found, reset val to 0
}



