#ifndef DQUEUE_H_INCLUDED
#define DQUEUE_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include "Dlist.h"

class DQueue{
private:
  Dlist ls();
  size_t sz = 0;

public:
  void push(const int & f);
  void pop();
  Node * first();
  size_t size();
};

void DQueue::push(const int & f){
  sz += 1;
  ls().insert(f, first());
};

void DQueue::pop(){
  ls().removeTail();
};

Node * DQueue::first(){
  if(sz == 0) return nullptr;
  return ls().getHead();
};

size_t DQueue::size(){
  return sz;
};

#endif // DQueue_H_INCLUDED
