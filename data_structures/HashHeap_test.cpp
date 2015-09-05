#include "gtest/gtest.h"
#include "HashHeap.h"

using namespace std;

TEST(HashHeap, NoRemove) {
  HashHeap heap;
  heap.insert(5);
  heap.insert(2);
  heap.insert(3);
  heap.insert(7);
  EXPECT_EQ(4, heap.size());
  EXPECT_EQ(7, heap.top());
  heap.pop();
  EXPECT_EQ(5, heap.top());
  heap.pop();
  EXPECT_EQ(3, heap.top());
  heap.pop();
  EXPECT_EQ(2, heap.top());
  heap.pop();
  EXPECT_EQ(0, heap.size());
}

TEST(HashHeap, RemoveElement) {
  HashHeap heap;
  heap.insert(5);
  heap.insert(2);
  heap.insert(3);
  heap.insert(7);
  heap.remove(5);
  EXPECT_EQ(3, heap.size());
  heap.remove(3);
  EXPECT_EQ(2, heap.size());
  EXPECT_EQ(7, heap.top());
  heap.pop();
  EXPECT_EQ(2, heap.top());
  heap.pop();
  EXPECT_EQ(0, heap.size());
}

TEST(HashHeap, NoRemoveDuplicates) {
  HashHeap heap;
  heap.insert(5);
  heap.insert(7);
  heap.insert(5);
  heap.insert(3);
  EXPECT_EQ(4, heap.size());
  EXPECT_EQ(7, heap.top());
  heap.pop();
  EXPECT_EQ(5, heap.top());
  heap.pop();
  EXPECT_EQ(5, heap.top());
  heap.pop();
  EXPECT_EQ(3, heap.top());
  heap.pop();
  EXPECT_EQ(0, heap.size());
}

TEST(HashHeap, RemoveDuplicates) {
  HashHeap heap;
  heap.insert(7);
  heap.insert(5);
  heap.insert(5);
  heap.insert(3);
  EXPECT_EQ(4, heap.size());
  EXPECT_EQ(7, heap.top());
  heap.pop();
  EXPECT_EQ(5, heap.top());
  heap.pop();
  heap.remove(5);
  EXPECT_EQ(3, heap.top());
  heap.pop();
  EXPECT_EQ(0, heap.size());
}

TEST(HashHeap, RemoveNotExist) {
  HashHeap heap;
  heap.insert(5);
  heap.insert(7);
  heap.insert(10);
  EXPECT_EQ(3, heap.size());
  heap.remove(11);
  EXPECT_EQ(3, heap.size());
  EXPECT_EQ(10, heap.top());
}

TEST(HashHeap, RemoveNoMore) {
  HashHeap heap;
  heap.insert(5);
  heap.insert(5);
  heap.insert(7);
  EXPECT_EQ(3, heap.size());
  heap.remove(5);
  EXPECT_EQ(2, heap.size());
  heap.remove(5);
  EXPECT_EQ(1, heap.size());
  EXPECT_EQ(7, heap.top());
}

TEST(HashHeap, ComplicatedTest) {
  HashHeap heap;
  for(int i = 1; i <= 10; i += 2) {
    heap.insert(i);
  }
  for(int i = 2; i <= 10; i += 2) {
    heap.insert(i);
  }
  while(heap.size() != 0) {
    if(heap.size() % 2) {
      heap.remove(heap.size());
    } else {
      EXPECT_EQ(heap.size(), heap.top());
      heap.pop();
    }
  }
}

TEST(HashHeap, AllEqualTest) {
  HashHeap heap;
  for(int i = 1; i <= 10; i++)
    heap.insert(10);
  while(heap.size() != 0) {
    EXPECT_EQ(10, heap.top());
    heap.remove(10);
  }
}
