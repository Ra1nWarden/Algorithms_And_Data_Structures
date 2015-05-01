#ifndef DATA_STRUCTURE_HASH_TABLE_H_
#define DATA_STRUCTURE_HASH_TABLE_H_

// Table size of the hash table. Must be a prime number.
#define TABLESIZE 1000003
// Maximum number of elements to be inserted into the hash table.
#define MAXN 1000
// Maximum length of strings.
#define MAXL 100

using namespace std;

struct HashTable {
  int head[TABLESIZE]; // The first element of each table entry.
  int next[TABLESIZE]; // Next element array.
  int values[MAXN]; // Value array for look up.
  int idx;
  // Hashing an integer
  int intKeys[MAXN]; // Key array for integer keys.
  int hashInteger(int x);
  // Use one of the following two:
  // HashSet: insertKey
  // HashMap: insertKeyValue
  bool insertKey(int x); // Returns false if already inserted.
  bool insertKeyValue(int k, int v); // Returns false if something is overwritten. (Key exists)
  bool lookup(int x, int& v);
  // Hashing a string
  char strKeys[MAXN][MAXL]; // Key array for string keys;
  int hashString(char* str);
  bool insertKey(char* str); // Returns false if already inserted.
  bool insertKeyValue(char* str, int v); // Returns false if something is overwritten. (Key exists)
  bool lookup(char* str, int& v);
  // Constructor
  HashTable();
};

#endif
