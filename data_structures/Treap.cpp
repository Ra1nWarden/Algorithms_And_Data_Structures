#include "Treap.h"
#include <cstdlib>

using namespace std;

Node::Node(int v) : v(v) {
  ch[0] = ch[1] = NULL;
  r = rand();
  w = 1;
  s = 1;
}

bool Node::operator<(const Node& rhs) const {
  return r < rhs.r;
}

int Node::cmp(int x) const {
  if(x == v)
    return -1;
  return x < v ? 0 : 1;
}

void Node::maintain() {
  s = w;
  if(ch[0] != NULL)
    s += ch[0]->s;
  if(ch[1] != NULL)
    s += ch[1]->s;
}

void rotate(Node*& o, int d) {
  Node* k = o->ch[d^1];
  o->ch[d^1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}

void insert(Node*& o, int x) {
  if(o == NULL)
    o = new Node(x);
  else {
    if(x == o->v) {
      o->w++;
    } else {
      int d = (x < o->v ? 0 : 1);
      insert(o->ch[d], x);
      if(o->ch[d]->r > o->r)
	rotate(o, d^1);
    }
  }
  o->maintain();
}

void remove(Node*& o, int x) {
  int d = o->cmp(x);
  if(d == -1) {
    if(o->w == 1) {
      Node* u = o;
      if(o->ch[0] != NULL && o->ch[1] != NULL) {
	int d2 = (o->ch[0]-> r > o->ch[1]->r ? 1 : 0);
	rotate(o, d2);
	remove(o->ch[d2], x);
      } else {
	if(o->ch[0] == NULL)
	  o = o->ch[1];
	else
	  o = o->ch[0];
	delete u;
      }
    } else {
      o->w--;
    }
  } else
    remove(o->ch[d], x);
  if(o != NULL)
    o->maintain();
}

int kth(Node* o, int k) {
  if(o == NULL || k <= 0 || k > o->s)
    return 0; // An error occurred.
  int s = (o->ch[1] == NULL ? 0 : o->ch[1]->s);
  if(k > s && k <= s + o->w)
    return o->v;
  else if(k <= s) {
    return kth(o->ch[1], k);
  }
  else {
    return kth(o->ch[0], k - s - o->w);
  }
}

int rank(Node* o, int x) {
  if(o == NULL)
    return 0;
  if(o->v == x) {
    return o->ch[1] == NULL ? 1 : o->ch[1]->s + 1;
  } else if(o->v < x) {
    return rank(o->ch[1], x);
  } else {
    int sub = rank(o->ch[0], x);
    if(sub == 0)
      return 0;
    else
      return (o->ch[1] == NULL ? o->w : o->ch[1]->s + o->w) + sub;
  }
}

void recycle(Node*& x) {
  if(x->ch[0] != NULL)
    recycle(x->ch[0]);
  if(x->ch[1] != NULL)
    recycle(x->ch[1]);
  delete x;
  x = NULL;
}
