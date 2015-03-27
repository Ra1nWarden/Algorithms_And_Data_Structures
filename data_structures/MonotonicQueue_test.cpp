#include "gtest/gtest.h"
#include "MonotonicQueue.h"

using namespace std;

int arr[] = {-1, 2, 3, 1, -2, 2};
int len = 6;

TEST(MonotonicQueue, SingleSlotWindow) {
  MonotonicQueue mq;
  int k = 1;
  // Insert elements until the first window is filled.
  for(int i = 0; i < k; i++)
    mq.insert(make_pair(arr[i], i));
  for(int i = k; i <= len; i++) {
    II res = mq.topVal(i - k); // Adjust this constraint according to problem requirement.
    EXPECT_EQ(make_pair(arr[i - k], i - k), res);
    // Insert element if it is in bound.
    if(i < len)
      mq.insert(make_pair(arr[i], i));
  }
}

TEST(MonotonicQueue, MultipleSlotsWindow) {
  MonotonicQueue mq;
  int k = 3;
  // Answer for window of width 3
  int ansv[] = {3, 3, 3, 2};
  int ansi[] = {2, 2, 2, 5};
  // Insert elements until the first window is filled.
  for(int i = 0; i < k; i++)
    mq.insert(make_pair(arr[i], i));
  for(int i = k; i <= len; i++) {
    II res = mq.topVal(i - k); // Adjust this constraint according to problem requirement.
    EXPECT_EQ(make_pair(ansv[i - k], ansi[i - k]), res);
    if(i < len)
      mq.insert(make_pair(arr[i], i));
  }
}

TEST(MonotonicQueue, FullWindow) {
  MonotonicQueue mq;
  int k = len;
  // Insert elements until the first window is filled.
  for(int i = 0; i < k; i++)
    mq.insert(make_pair(arr[i], i));
  for(int i = k; i <= len; i++) {
    II res = mq.topVal(i - k); // Adjust this constraint according to problem requirement.
    EXPECT_EQ(make_pair(3, 2), res);
    if(i < len)
      mq.insert(make_pair(arr[i], i));
  }
}
