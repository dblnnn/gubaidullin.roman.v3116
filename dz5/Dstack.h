#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#include <cstdlib>
#include <iostream>
#include "Dlist.h"

class listStack{
private:
  DList ls();
  size_t sz = 0;

public:
  void push(const int & f);
  void pop();
  Node * last();
  size_t size();
};

void listStack::push(const int & f){
  sz += 1;
  ls().insert(f, last());
};

void listStack::pop(){
  ls().removeTail();
};

Node * listStack::last(){
  if(sz == 0) return nullptr;
  return ls().getTail();
};

size_t listStack::size(){
  return sz;
};

#endif // STACK_INCLUDED
