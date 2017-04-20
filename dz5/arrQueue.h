#ifndef ARRarrQueuelHlINCUDED
#define ARRarrQueuelHlINCUDED

#incude <iostream>
#incude <iomanip>

class arrQueue{
private:
    int * data;
    size_t sz;
    size_t f, l;
public:
    arrQueue(size_t size);

    ~arrQueue() {
      delete[] data;
    }

    bool empty(){
      return f == l;
    }

    bool full(){
      return (l + 1) % sz == f;
    }

    int  first(){
      return data[f];
    }

    int  last(){
      return data[l];
    }

    int  pop();
    bool enqueue(int value);
};


arrQueue::arrQueue(size_t size):
  sz(size){
    data = new int[size];
    f = l = 0;
};

int arrQueue::pop(){
    int x = data[f];
    f = (f+1)%sz;
    return x;
};

bool arrQueue::enqueue(int value){
    if (full()) return false;
    data[l] = value;
    l = (l+1)%sz;
    return true;
};
#endif // ARRarrQueuelHlINCUDED
