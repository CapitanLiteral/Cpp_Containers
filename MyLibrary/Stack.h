
#pragma once
#ifndef Stack_H
#define Stack_H

#include "DynArray.h"

template <class TYPE>
class Stack
{
	public:

		TYPE *data;
		unsigned int allocatedMemory;
		unsigned int numElements;

		int i;

		Stack()
		{ 
			data = NULL;
			allocatedMemory = 0;
			numElements = 0;
		}
		~Stack(){}


		//TODO Push
		void pushBack(const TYPE val)
		{
			if (numElements == allocatedMemory)
				reallocate(allocatedMemory + 1);

			data[numElements] = val;
			numElements++;
		}
		

		//TODO Pop: elements -1 
		bool pop()
		{
			bool ret = false;
			if (data != NULL && numElements > 0)
			{
				numElements--;
				return !ret;
			}
			return ret;
		}			
		
		const TYPE pick(const int a) const
		{
			return data[a];
		}

		TYPE getLast()
		{
			return data[numElements-1];
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
