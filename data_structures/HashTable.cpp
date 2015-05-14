#include "HashTable.h"
#include <cstring>

using namespace std;

HashTable::HashTable() {
  // Index starts from 1.
  idx = 1;
  // 0 means the end of linked list.
  memset(head, 0, sizeof head);
  memset(next, 0, sizeof next);
}

// Change this function for other data types.
int HashTable::hashInteger(int x) {
  return x % TABLESIZE;
}

bool HashTable::insertKey(int x) {
  int h = hashInteger(x);
  int u = head[h];
  while(u) {
    if(intKeys[u] == x)
      return false;
    u = next[u];
  }
  next[idx] = head[h];
  head[h] = idx;
  intKeys[idx++] = x;
  return true;
}

bool HashTable::insertKeyValue(int k, int v) {
  int h = hashInteger(k);
  int u = head[h];
  while(u) {
    if(intKeys[u] == k) {
      values[u] = v;
      return false;
    }
    u = next[u];
  }
  next[idx] = head[h];
  head[h] = idx;
  intKeys[idx] = k;
  values[idx++] = v;
  return true;
}

bool HashTable::lookup(int x, int& v) {
  int h = hashInteger(x);
  int u = head[h];
  while(u) {
    if(intKeys[u] == x) {
      v = values[u];
      return true;
    }
    u = next[u];
  }
  return false;
}

int HashTable::hashString(char* str) {
  int n = 0;
  int base = 1;
  for(int i = 0; i < strlen(str); i++) {
    n = (n + base * str[i]) % TABLESIZE;
    base = (base * 31) % TABLESIZE;
  }
  return n;
}

bool HashTable::insertKey(char* str) {
  int h = hashString(str);
  int u = head[h];
  while(u) {
    if(strcmp(strKeys[u], str) == 0)
      return false;
    u = next[u];
  }
  next[idx] = head[h];
  head[h] = idx;
  memcpy(strKeys[idx++], str, sizeof(char) * (strlen(str) + 1));
  return true;
}

bool HashTable::insertKeyValue(char* str, int v) {
  int h = hashString(str);
  int u = head[h];
  while(u) {
    if(strcmp(strKeys[u], str) == 0) {
      values[u] = v;
      return false;
    }
    u = next[u];
  }
  next[idx] = head[h];
  head[h] = idx;
  memcpy(strKeys[idx], str, sizeof(char) * (strlen(str) + 1));
  values[idx++] = v;
  return true;
}

bool HashTable::lookup(char* str, int& v) {
  int h = hashString(str);
  int u = head[h];
  while(u) {
    if(strcmp(strKeys[u], str) == 0) {
      v = values[u];
      return true;
    }
    u = next[u];
  }
  return false;
}

int hashAllLower(char* str) {
  int len = strlen(str);
  int res = 0;
  for(int i = 0; i < len; i++) {
    res = res * 27 + str[i] - 'a' + 1; // +1 is necessary to differentiate a and aa
  }
  return res; // MOD table size before return
}
