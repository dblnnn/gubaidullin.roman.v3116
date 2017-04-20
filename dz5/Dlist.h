#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Node{
  int field;
  Node *next;
  Node *prev;

  Node():
    field(0),
    next(nullptr),
    prev(nullptr)
  {};

  Node(const int f):
    field(f),
    next(nullptr),
    prev(nullptr)
  {};
};

struct DList{
private:
  Node *head = nullptr;
  Node *tail = nullptr;

public:
  DList(){};
  ~DList();

  Node * find(const int & f);
  void insert(const int & f, Node * current);
  void remove(Node * nd);
  void removeHead();
  void removeTail();
  size_t DListSize();

  Node * getTail(){
    return tail;
  };

  Node * getHead(){
    return head;
  };
};


DList::~DList(){
  while (head){
    Node * temp;
    temp->next = head->next;
    delete head;
    head = temp->next;
    delete temp;
  }
};

Node * DList::find(const int & f){
  Node * current(nullptr);
  if(current->next == nullptr){
    if(current->field == head->field){
      return head;
    }
    current = head;
  }
  while(current){
    if(current->field == f){
      return current;
    }
  }
  return nullptr;
};

void DList::insert(const int & f, Node * before){
  Node * newNode = new Node(f);
  if(before == nullptr){
    newNode->next = head;
    head = newNode;
    newNode->next->prev = newNode;
    newNode->prev = nullptr;
    return;
  }
  newNode->prev = before;
  newNode->next = before->next;
  if(before->next != nullptr){
    before->next->prev = newNode;
    before->next = newNode;
  }
  else{
    before->next = newNode;
    newNode->next = nullptr;
    tail = newNode;
  }
  return;
};

void DList::remove(Node * nd){
  if(nd == nullptr) return;
  if(nd == head){
    removeHead();
    return;
  }
  if(nd == tail){
    removeTail();
    return;
  }
  Node * newNext = nd->next;
  nd->next->prev = nd->prev;
  nd->prev->next = newNext;
  delete newNext;
  delete nd;
};

void DList::removeHead(){
  Node * newHead = head->next;
  delete head;
  head = newHead;
  head->prev = nullptr;
  delete newHead;
  return;
};

void DList::removeTail(){
  Node * newTail = tail->prev;
  delete tail;
  tail = newTail;
  tail->next = nullptr;
  delete newTail;
  return;
};

size_t DList::DListSize(){
  size_t i = 0;
  Node * temp = head;
  for(;temp != nullptr; i++){
    temp = head->next;
  }
  return i;
};




#endif // LIST_H_INCLUDED
