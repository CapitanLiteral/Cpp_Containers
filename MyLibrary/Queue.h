
#pragma once
#ifndef Queue_H
#define Queue_H

#include "DynArray.h"

template <class TYPE>
class Queue
{
public:

	TYPE *data;
	unsigned int allocatedMemory;
	unsigned int numElements;
	TYPE *start;

	int i;

	Queue()
	{
		data = NULL;
		start = NULL;
		allocatedMemory = 0;
		numElements = 0;
	}
	~Queue(){}


	//TODO Push
	void pushBack(const TYPE val)
	{
		if (numElements == allocatedMemory)
			reallocate(allocatedMemory + 1);
		start = data;
		data[numElements] = val;
		numElements++;
	}


	//TODO Pop: elements -1 
	TYPE pop()
	{
		TYPE *tStart = start;
		start = start++;
		return *tStart;
	}

	const TYPE pick(const int a) const
	{
		return start+a;
	}

	TYPE getLast()
	{
		return data[numElements - 1];
	}

	void reallocate(unsigned int newSize)
	{
		if (data != NULL)
		{
			// Saving Data
			TYPE *tmp = new TYPE[allocatedMemory];
			for (unsigned int i = 0; i < numElements; i++)
			{
				tmp[i] = data[i];
			}
			// Reallocating data Space+
			delete[] data;
			allocatedMemory = newSize;
			data = new TYPE[allocatedMemory];
			// Copying saved Data to the new Data
			for (unsigned int i = 0; i < numElements; i++)
			{
				data[i] = tmp[i];
			}
		}
		else
		{
			delete[] data;
			allocatedMemory = newSize;
			data = new TYPE[allocatedMemory];
		}
	}

};

#endif
