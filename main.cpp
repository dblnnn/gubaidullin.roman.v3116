#include <iostream>
#include "stdlib.h"

using namespace std;

void selection_sort(int array[], size_t arrSize)
{
  for(size_t i = 0; i < arrSize - 1; i++)
  {
    size_t iMin = i;
    for(size_t j = i + 1; j < arrSize; j++)
    {
      if(array[j] < array[iMin])
      {
        iMin = j;
      }
    }
    if(iMin != i)
    {
      swap(array[iMin], array[i]);
    }
  }
}

const size_t N = 20;

int main()
{

  int testArr[N];
  for(size_t k = 0; k < N; k++)
  {
    testArr[k] = rand() % 40 +1;
  }
  for(size_t k = 0; k < N; k++)
  {
    cout << testArr[k] << " ";
  }
  selection_sort(testArr,N);
  cout << endl << "Sorted: ";
  for(size_t k = 0; k < N; k++)
  {
    cout << testArr[k] << " ";
  }
  return 0;
}
