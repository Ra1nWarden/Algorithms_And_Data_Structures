#include "gtest/gtest.h"
#include "Trie.h"

using namespace std;

Trie trie;
TrieChildBrother triecb;

char word1[] = "cat";
char word2[] = "case";
char word3[] = "dog";
char word4[] = "abcdefghijklmnopqrstuvwxyz";
char word5[] = "abcdefghijkl";

TEST(Trie, InsertWord) {
  trie.insert(word1, 1);
  EXPECT_EQ(1, trie.find(word1));
}

TEST(Trie, InsertWords) {
  trie.insert(word1, 1);
  trie.insert(word2, 2);
  EXPECT_EQ(1, trie.find(word1));
  EXPECT_EQ(2, trie.find(word2));
}

TEST(Trie, InsertPrefix) {
  trie.insert(word4, 100);
  trie.insert(word5, 1);
  EXPECT_EQ(1, trie.find(word5));
  EXPECT_EQ(100, trie.find(word4));
}

TEST(Trie, Remove) {
  trie.insert(word1, 1);
  trie.insert(word2, 2);
  trie.del(word1);
  EXPECT_EQ(0, trie.find(word1));
  EXPECT_EQ(2, trie.find(word2));
}

TEST(TrieChildBrother, InsertWord) {
  triecb.insert(word1, 1);
  EXPECT_EQ(1, triecb.find(word1));
}

TEST(TrieChildBrother, InsertWords) {
  triecb.insert(word1, 1);
  triecb.insert(word2, 2);
  EXPECT_EQ(1, triecb.find(word1));
  EXPECT_EQ(2, triecb.find(word2));
}

TEST(TrieChildBrother, InsertPrefix) {
  triecb.insert(word4, 100);
  triecb.insert(word5, 1);
  EXPECT_EQ(1, triecb.find(word5));
  EXPECT_EQ(100, triecb.find(word4));
}

TEST(TrieChildBrother, Remove) {
  triecb.insert(word1, 1);
  triecb.insert(word2, 2);
  triecb.del(word1);
  EXPECT_EQ(0, triecb.find(word1));
  EXPECT_EQ(2, triecb.find(word2));
}
