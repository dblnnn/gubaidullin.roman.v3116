#include <vector>
#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
  try{
    srand(time(0));
    std::vector<int> testVector;
    for(size_t i = 0; i < 10; i++){
      testVector.push_back(rand() % 50 + 1);
    }
    for(size_t i =0; i < testVector.size(); i++){
      cout << testVector.at(i) << " ";
    }
    cout << endl;
    heapsort(testVector);
    for(size_t i =0; i < testVector.size(); i++){
      cout << testVector.at(i) << " ";
    }
    return 0;
  }
  catch(...){
    cout << "Smth went wrong!" << endl;
    return 1;
  }
}
