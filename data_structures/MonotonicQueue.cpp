#include "MonotonicQueue.h"

using namespace std;

MonotonicQueue::MonotonicQueue() {
  front = rear = 0;
}

void MonotonicQueue::insert(II x) {
  while(front < rear && v[rear - 1].first < x.first) // '<' snce we are looking for the maximum value in the window
    rear--;
  v[rear] = x;
  rear++;
}

II MonotonicQueue::topVal(int constraint) {
  while(front < rear && v[front].second < constraint) // The constraint condition is constructed based on usage.
    front++;
  return v[front];
}
