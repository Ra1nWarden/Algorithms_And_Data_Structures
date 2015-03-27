#include "gtest/gtest.h"
#include "MonotonicQueue.h"

using namespace std;

int arr[] = {-1, 2, 3, 1, -2, 2};
int len = 6;

TEST(MonotonicQueue, SingleSlotWindow) {
  MonotonicQueue mq;
  int k = 1;
  for(int i = 0; i < k; i++)
    mq.insert(make_pair(arr[i], i));
  for(int i = k; i < 6; i++) {
    II res = mq.topVal(i - k); // Adjust this constraint according to problem requirement.
    EXPECT_EQ(make_pair(arr[i - k], i - k), res);
    mq.insert(make_pair(arr[i], i));
  }
}

TEST(MonotonicQueue, MultipleSlotsWindow) {
  MonotonicQueue mq;
  int k = 3;
  // Answer for window of width 3
  int ansv[] = {3, 3, 3, 2};
  int ansi[] = {2, 2, 2, 5};
  for(int i = 0; i < k; i++)
    mq.insert(make_pair(arr[i], i));
  for(int i = k; i < 6; i++) {
    II res = mq.topVal(i - k); // Adjust this constraint according to problem requirement.
    EXPECT_EQ(make_pair(ansv[i - k], ansi[i - k]), res);
    mq.insert(make_pair(arr[i], i));
  }
}
