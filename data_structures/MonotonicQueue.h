#ifndef DATA_STRUCTURE_MONOTONIC_QUEUE_H_
#define DATA_STRUCTURE_MONOTONIC_QUEUE_H_

#include <utility>
#define MAXN 1005

using namespace std;

/*
Monotonic queue is mostly used for optimization in dynamic programming.
A classic problem that this data structure addresses:
Given a list of numbers {3, 2, 1, 4, 3, 1} and a window of width w
What is the min/max value in the window as the window slides?
This data structure answers this query in O(n) time. (Amortized O(1) for each query)
*/

// Data type for the queue.
// For example, II.first is the value we are maintaining and II.second is the index which is used to test against constraint
typedef pair<int, int> II;

// Everything in this class can be global
struct MonotonicQueue {
  II v[MAXN];
  int front, rear; // rear is point one element after the last actual element
  MonotonicQueue();
  void insert(II x);
  II topVal(int constraint); // constraint is used to pop the front element if necessary.
};

#endif
