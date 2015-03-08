#ifndef DATA_STRUCTURE_TRIE_H_
#define DATA_STRUCTURE_TRIE_H_

// Estimate a safe value for this maximum number of node
// e.g. MAXN = max words * max word length + 10
#define MAXN 1000
// The total number of characters, put the default as 26 (alphabets)
// If this value is too large, try to represent the Trie using child and brothers arrays method.
#define MAXC 26

using namespace std;

// Standard and simple implementation
struct Trie {
  int trie[MAXN][MAXC];
  int val[MAXN];
  int nextnode;
  Trie();
  // Insert word w wiht value v
  void insert(char* w, int v);
  // Look for the value of word w (return 0 if not found)
  int find(char* w);
  // Delete word w
  void del(char* w);
};

// If MAXC is too large, try switching to this to save space
struct TrieChildBrother {
  int lchild[MAXN]; // First child index
  int bro[MAXN]; // Index of the next brother
  int val[MAXN];
  char ch[MAXN]; // Saves character for each node
  int nextnode;
  TrieChildBrother();
  // Insert word w wiht value v
  void insert(char* w, int v);
  // Look for the value of word w (return 0 if not found)
  int find(char* w);
  // Delete word w
  void del(char* w);
};

#endif
