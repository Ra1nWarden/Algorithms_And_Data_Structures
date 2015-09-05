#include "HashHeap.h"

using namespace std;

HashHeap::HashHeap() {
  hash.clear();
  next = 1;
}

void HashHeap::insert(int x) {
  v[next] = x;
  hash[x].push_back(next);
  int pos = next;
  while(pos != 1) {
    if(v[pos] <= v[pos >> 1]) {
      break;
    }
    swap_node(pos, pos >> 1);
    pos >>= 1;
  }
  next++;
}

void HashHeap::remove(int x) {
  if(hash.count(x) == 0 || hash[x].empty())
    return;
  int idx = hash[x].back();
  swap_node(idx, next - 1);
  remove_idx(x, next - 1);
  next--;
  heapify(idx);
}

int HashHeap::top() {
  return v[1];
}

int HashHeap::size() {
  return next - 1;
}

void HashHeap::modify_idx(int val, int old_pos, int new_pos) {
  list<int>& v = hash[val];
  list<int>::iterator itr;
  for(itr = v.begin(); itr != v.end(); itr++) {
    if(*itr == old_pos) {
      break;
    }
  }
  *itr = new_pos;
}

void HashHeap::remove_idx(int val, int pos) {
  list<int>& v = hash[val];
  list<int>::iterator itr;
  for(itr = v.begin(); itr != v.end(); itr++) {
    if(*itr == pos) {
      break;
    }
  }
  v.erase(itr);
}

void HashHeap::swap_node(int idx1, int idx2) {
  swap(v[idx1], v[idx2]);
  modify_idx(v[idx1], idx2, idx1);
  modify_idx(v[idx2], idx1, idx2);
}

void HashHeap::pop() {
  swap_node(1, next - 1);
  remove_idx(v[next - 1], next - 1);
  next--;
  heapify(1);
}

void HashHeap::heapify(int idx) {
  int left = idx << 1;
  int right = (idx << 1) | 1;
  if(left >= next && right >= next) {
    return;
  } else if(right >= next) {
    if(v[idx] < v[left]) {
      swap_node(idx, left);
    }
  } else {
    if(v[left] > v[idx] && v[left] >= v[right]) {
      swap_node(idx, left);
      heapify(left);
    } else if(v[right] > v[idx] && v[right] >= v[left]) {
      swap_node(idx, right);
      heapify(right);
    }
  }
}

