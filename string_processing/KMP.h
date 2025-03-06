#ifndef ALGORITHMS_KMP_H_
#define ALGORITHMS_KMP_H_

#include <vector>
#define MAXL 1005 // Maximum length of the template we are looking for
#define MAXN 10000 // Maximum length of the string that we are searching for template

using namespace std;

// All fields in this struct can be made global when applied
struct KMP {
  char pattern[MAXL];
  char str[MAXN];
  int f[MAXL];
  KMP();
  /** 
     Initialize f array - f array is also known as prefix function.
     Prefix function is an array (of index i) that stores the longest proper prefix that is also a suffix of substring (0..i)
     (Parameters are global.)
     @param f The fail array that directs to the next possible index in the template.
     @param pattern The string we are looking for (template).
   */
  void init();
  
  /**
     Find all occurrences of pattern in str. Calls init().
     (Parameters are global.)
     @param pattern The string we are looking for (template).
     @param str The string we are searching.
   */
  vector<int> match();
};

#endif
