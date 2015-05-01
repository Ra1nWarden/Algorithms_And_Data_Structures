#include "gtest/gtest.h"
#include "HashTable.h"

using namespace std;

int intKey1 = 23231;
int intKey2 = 783;
int intKey3 = 6301274;
int intKey4 = 13567;

char strKey1[] = "hash";
char strKey2[] = "table";
char strKey3[] = "stlsucks";
char strKey4[] = "implementyourown";

TEST(HashTableInteger, HashSetInsertion) {
  HashTable ht;
  ASSERT_TRUE(ht.insertKey(intKey1));
}

TEST(HashTableInteger, HashSetTestPositive) {
  HashTable ht;
  ht.insertKey(intKey2);
  int v;
  ASSERT_TRUE(ht.lookup(intKey2, v));
}

TEST(HashTableInteger, HashSetTestPositiveCollision) {
  HashTable ht;
  ht.insertKey(0);
  int v;
  ASSERT_TRUE(ht.lookup(0, v));
  ht.insertKey(1000003);
  ASSERT_TRUE(ht.lookup(0, v));
  ASSERT_TRUE(ht.lookup(1000003, v));
}

TEST(HashTableInteger, HashSetTestNegative) {
  HashTable ht;
  ht.insertKey(intKey3);
  int v;
  ASSERT_FALSE(ht.lookup(intKey4, v));
  ASSERT_FALSE(ht.lookup(intKey1, v));
  ASSERT_FALSE(ht.lookup(intKey2, v));
}

TEST(HashTableInteger, HashMapInsert) {
  HashTable ht;
  ASSERT_TRUE(ht.insertKeyValue(intKey3, 33));
}

TEST(HashTableInteger, HashMapTestPositive) {
  HashTable ht;
  ht.insertKeyValue(intKey3, 100);
  int v;
  ASSERT_TRUE(ht.lookup(intKey3, v));
  ASSERT_EQ(100, v);
  ht.insertKeyValue(intKey2, 233);
  ASSERT_TRUE(ht.lookup(intKey2, v));
  ASSERT_EQ(233, v);
}

TEST(HashTableInteger, HashMapTestPositiveCollision) {
  HashTable ht;
  ht.insertKeyValue(0, 100);
  int v;
  ASSERT_TRUE(ht.lookup(0, v));
  ASSERT_EQ(100, v);
  ht.insertKeyValue(1000003, 233);
  ASSERT_TRUE(ht.lookup(0, v));
  ASSERT_EQ(100, v);
  ASSERT_TRUE(ht.lookup(1000003, v));
  ASSERT_EQ(233, v);
}

TEST(HashTableInteger, HashMapTestNegative) {
  HashTable ht;
  ht.insertKeyValue(intKey4, 100);
  int v;
  ASSERT_FALSE(ht.lookup(intKey3, v));
  ASSERT_FALSE(ht.lookup(intKey1, v));
  ASSERT_FALSE(ht.lookup(intKey2, v));
}

TEST(HashTableInteger, HashMapTestUpdate) {
  HashTable ht;
  ht.insertKeyValue(intKey3, 100);
  int v;
  ASSERT_TRUE(ht.lookup(intKey3, v));
  ASSERT_EQ(100, v);
  ASSERT_FALSE(ht.insertKeyValue(intKey3, 101));
  ASSERT_TRUE(ht.lookup(intKey3, v));
  ASSERT_EQ(101, v);
  ASSERT_FALSE(ht.insertKeyValue(intKey3, 134));
  ASSERT_TRUE(ht.lookup(intKey3, v));
  ASSERT_EQ(134, v);
}

TEST(HashTableString, HashSetInsertion) {
  HashTable ht;
  ASSERT_TRUE(ht.insertKey(strKey1));
}

TEST(HashTableString, HashSetTestPositive) {
  HashTable ht;
  ht.insertKey(strKey2);
  int v;
  ASSERT_TRUE(ht.lookup(strKey2, v));
}

TEST(HashTableString, HashSetTestNegative) {
  HashTable ht;
  ht.insertKey(strKey3);
  int v;
  ASSERT_FALSE(ht.lookup(strKey4, v));
  ASSERT_FALSE(ht.lookup(strKey1, v));
  ASSERT_FALSE(ht.lookup(strKey2, v));
}

TEST(HashTableString, HashMapInsert) {
  HashTable ht;
  ASSERT_TRUE(ht.insertKeyValue(strKey3, 33));
}

TEST(HashTableString, HashMapTestPositive) {
  HashTable ht;
  ht.insertKeyValue(strKey3, 50);
  int v;
  ASSERT_TRUE(ht.lookup(strKey3, v));
  ASSERT_EQ(50, v);
  ht.insertKeyValue(strKey2, 75);
  ASSERT_TRUE(ht.lookup(strKey2, v));
  ASSERT_EQ(75, v);
}

TEST(HashTableString, HashMapTestNegative) {
  HashTable ht;
  ht.insertKeyValue(strKey4, 15);
  int v;
  ASSERT_FALSE(ht.lookup(strKey3, v));
  ASSERT_FALSE(ht.lookup(strKey1, v));
  ASSERT_FALSE(ht.lookup(strKey2, v));
}

TEST(HashTableString, HashMapTestUpdate) {
  HashTable ht;
  ht.insertKeyValue(strKey3, 567);
  int v;
  ASSERT_TRUE(ht.lookup(strKey3, v));
  ASSERT_EQ(567, v);
  ASSERT_FALSE(ht.insertKeyValue(strKey3, 765));
  ASSERT_TRUE(ht.lookup(strKey3, v));
  ASSERT_EQ(765, v);
  ASSERT_FALSE(ht.insertKeyValue(strKey3, 123));
  ASSERT_TRUE(ht.lookup(strKey3, v));
  ASSERT_EQ(123, v);
}
