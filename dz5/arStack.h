#ifndef ARSTACK_H_INCLUDED
#define ARSTACK_H_INCLUDED

#include <cstring>
#include <iostream>

class arrStack
{
private:
	int last;
	int *data;
	int max_elem;

public:
  arrStack();
	arrStack(int n);
	~arrStack();

	int top();
	void pop();
	void push(const int a);
	int size();
	bool empty();
};

arrStack::arrStack()
{
	max_elem = 1;
	last = 0;
	data = new int[max_elem];
}

arrStack::arrStack(int n)
{
	max_elem = n;
	last = 0;
	data = new int[max_elem];
}

arrStack::~arrStack()
{
	delete[] data;
}

int arrStack::top()
{
	return (last)? data[last - 1] : -1;
}

void arrStack::pop()
{
	if(last)
		--last;
}

void arrStack::push(int a)
{
	if(last < max_elem)
		data[last++] = a;
	else
	{
		max_elem *= 2;
		int *new_data = new int[max_elem];
		memcpy(new_data, data, max_elem*sizeof(int));

		delete[] data;
		data = new_data;
		data[last++] = a;
	}

}

int arrStack::size()
{
	return last;
}

bool arrStack::empty()
{
	return !last;
}


#endif // ARSTACK_H_INCLUDED
