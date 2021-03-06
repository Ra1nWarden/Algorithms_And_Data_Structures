#include "gtest/gtest.h"
#include "Treap.h"

TEST(Treap, kthTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  EXPECT_EQ(3, kth(root, 3));
  recycle(root);
}


TEST(Treap, kthDuplicateTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 3);
  insert(root, 5);
  EXPECT_EQ(3, kth(root, 2));
  EXPECT_EQ(3, kth(root, 3));
  EXPECT_EQ(2, kth(root, 4));
  recycle(root);
}

TEST(Treap, kthRemoveTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  EXPECT_EQ(3, kth(root, 3));
  remove(root, 4);
  EXPECT_EQ(2, kth(root, 3));
  recycle(root);
}

TEST(Treap, kthDuplicateRemoveTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 3);
  insert(root, 5);
  EXPECT_EQ(3, kth(root, 2));
  remove(root, 2);
  EXPECT_EQ(3, kth(root, 2));
  EXPECT_EQ(3, kth(root, 3));
  EXPECT_EQ(1, kth(root, 4));
  recycle(root);
}

TEST(Treap, rankTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  EXPECT_EQ(4, rank(root, 2));
  recycle(root);
}

TEST(Treap, rankRemoveTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  EXPECT_EQ(3, rank(root, 3));
  remove(root, 4);
  EXPECT_EQ(2, rank(root, 3));
  recycle(root);
}

TEST(Treap, rankDuplicateTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 3);
  insert(root, 5);
  EXPECT_EQ(4, rank(root, 2));
  EXPECT_EQ(2, rank(root, 3));
  EXPECT_EQ(0, rank(root, 4));
  recycle(root);
}

TEST(Treap, rankDuplicateRemoveTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 3);
  insert(root, 5);
  EXPECT_EQ(4, rank(root, 2));
  remove(root, 2);
  EXPECT_EQ(4, rank(root, 1));
  EXPECT_EQ(0, rank(root, 2));
  EXPECT_EQ(2, rank(root, 3));
  recycle(root);
}

TEST(Treap, findTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  EXPECT_TRUE(find(root, 2));
  recycle(root);
}

TEST(Treap, findRemoveTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  EXPECT_TRUE(find(root, 2));
  remove(root, 2);
  EXPECT_FALSE(find(root, 2));
  recycle(root);
}

TEST(Treap, findDuplicateRemoveTest) {
  Node* root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 3);
  insert(root, 5);
  EXPECT_TRUE(find(root, 3));
  remove(root, 3);
  EXPECT_TRUE(find(root, 3));
  remove(root, 3);
  EXPECT_FALSE(find(root, 3));
  recycle(root);
}
