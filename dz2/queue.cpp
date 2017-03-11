#include "queue.h"
#include <vector>

void PriorityQueue::push(int el){
  heap.push_back(el);
  size_t i = heap.size() - 1;
  size_t parent = (i - 1) / 2;

  while(i > 0 && heap[parent] < heap[i]){
    std::swap(heap[i], heap[parent]);
    i = parent;
    parent = (i - 1) / 2;
  }
}

void PriorityQueue::pop(){
  heap[0] = heap[heap.size() - 1];
  heap.erase(heap.end() - 1);
  heapify(0);
}

int PriorityQueue::top(){
  return this->heap[0];
}

void PriorityQueue::heapify(size_t i){
  size_t left;
  size_t right;
  size_t largestChild;

  while(true){
    if(left < heap.size() && heap[left] > heap[largestChild]){
      largestChild = left;
    }

    if(right < heap.size() && heap[right] > heap[largestChild]){
      largestChild = right;
    }

    if(i == largestChild) return;

    std::swap(heap[i], heap[largestChild]);
    i = largestChild;
  }
}

void heapsort(std::vector<int> &vec){
  PriorityQueue qu;
  for(size_t i = 0; i < vec.size(); i++){
    qu.push(vec[i]);
  }
  for(size_t i = vec.size() - 1; i >= 0; i--){
    vec[i] = qu.top();
    qu.pop();
  }
}
