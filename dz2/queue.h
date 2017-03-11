#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "stdlib.h"
#include <vector>

class PriorityQueue {
  private:
  std::vector<int> heap;
  void heapify(size_t i);

  public:
  void push(int el);
  void pop();
  int top();
};

void heapsort(std::vector<int> &vec);

#endif // QUEUE_H_INCLUDED
