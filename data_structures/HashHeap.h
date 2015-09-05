#ifndef DATA_STRUCTURE_HASH_HEAP_H_
#define DATA_STRUCTURE_HASH_HEAP_H_

#include <list>
#include <map>
#define HEAPSIZE 1010

using namespace std;

struct HashHeap {
  int v[HEAPSIZE];
  int next;
  map<int, list<int> > hash;
  HashHeap();
  void insert(int x);
  void remove(int x);
  int top();
  void pop();
  int size();
private:
  void swap_node(int idx1, int idx2);
  void heapify(int idx);
  void modify_idx(int val, int old_pos, int new_pos);
  void remove_idx(int val, int pos);
};

#endif
