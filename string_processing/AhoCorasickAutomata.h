#ifndef DATA_STRUCTURE_TRIE_H_
#define DATA_STRUCTURE_TRIE_H_

#include <vector>

// An estimate of the maximum number of node in the Trie
// To estimate this value, maximum pattern length * maximum number of patterns + some buffer space (~5)
#define MAXNODE 10005
// The maximum number of characters in the pattern
// 26 is just for all lower case letters, it can be set to 128 to include more ASCII characters
#define SIGMA_SIZE 26

using namespace std;

// This struct do not have to be global.
struct AhoCorasickAutomata {
  // A Trie data structure inside AC Automata
  int node_count;
  int trie[MAXNODE][SIGMA_SIZE];
  int val[MAXNODE];
  // Failure match array that is similar to KMP algorithm.
  int f[MAXNODE];
  // An array that points to other possile matches among the patterns.
  int last[MAXNODE];
  
  AhoCorasickAutomata();
  // Insert a pattern into the automata with value v
  void insert(char* pat, int v);
  // Initialize last and f arrays
  void init();
  // Return an vector of values for matches in the string.
  // The return type can be void. (e.g. print result after finding each match etc.)
  vector<int> find(char* s);
};

#endif
