#include "Polynomial.h"
#include <cmath>

vector<int> PolynomialMultiply(vector<int> f, vector<int> g) {
  // initialize the answer array of size 2^n
  int len = 1;
  while(len < f.size() * 2 || len < g.size() * 2) {
    len <<= 1;
  }
  // Convert into complex number
  vector<Comp> ff;
  for(int i = 0; i < f.size(); i++) {
    Comp each(f[i], 0);
    ff.push_back(each);
  }
  vector<Comp> gg;
  for(int i = 0; i < g.size(); i++) {
    Comp each(g[i], 0);
    gg.push_back(each);
  }
  ff.resize(len);
  gg.resize(len);
  // FFT
  FastFourierTransform(&ff[0], len, 1);
  FastFourierTransform(&gg[0], len, 1);
  // Calculate product based on point representation
  for(int i = 0; i < len; i++) {
    ff[i] *= gg[i];
  }
  // IFFT
  FastFourierTransform(&ff[0], len, -1);
  vector<int> ans;
  for(int i = 0; i < len; i++) {
    ans.push_back((int) (ff[i].real() / len + 0.5));
  }
  // Resize
  int size = ans.size();
  while(ans[size - 1] == 0) {
    size--;
  }
  ans.resize(size);
  
  return ans;
}

void FastFourierTransform(Comp* a, int n, int inv) {
  if(n == 1) {
    return;
  }
  int mid = n / 2;
  vector<Comp> b(n);
  for(int i = 0; i < mid; i++) {
    b[i] = a[i * 2];
    b[i + mid] = a[i * 2 + 1];
  }
  for(int i = 0; i < n; i++) {
    a[i] = b[i];
  }
  // Divide
  FastFourierTransform(a, mid, inv);
  FastFourierTransform(a + mid, mid, inv);
  // Combine
  const double pi = acos(-1.0);
  for(int i = 0; i < mid; i++) {
    Comp x(cos(2 * pi * i / n), inv * sin(2 * pi * i / n));
    b[i] = a[i] + x * a[i + mid];
    b[i + mid] = a[i] - x * a[i + mid];
  }
  for(int i = 0; i < n; i++) {
    a[i] = b[i];
  }
}
