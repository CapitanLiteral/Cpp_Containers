#pragma once

#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <assert.h>
template <class TYPE>
class DynArray
{
private:

	TYPE *data;
	unsigned int allocatedMemory;
	unsigned int numElements;

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



public:

	DynArray<TYPE>()
	{
		data = NULL;
		allocatedMemory = 0;
		numElements = 0;
	}

	DynArray<TYPE>(const unsigned int newSize)
	{
		data = NULL;
		numElements = 0;
		reallocate(newSize);
	}

	~DynArray<TYPE>() 
	{ 
		if (data != NULL) 
			delete[] data; 
	}

	//TODO Push_Back:
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
	//TODO Clear:
	void clear()
	{
		numElements = 0;
	}


	//TODO Insert:
	void insert(const int newVal, const unsigned int pos)
	{
		if (pos <= numElements)
		{
			TYPE *tmp = new TYPE[allocatedMemory];

			for (int i = 0; i < numElements; i++)
			{
				tmp[i] = data[i];
			}

			if (numElements == allocatedMemory)
				reallocate(allocatedMemory + 1);

			for (int i = 0; i < pos; i++)
			{
				data[i] = tmp[i];
			}

			data[pos] = newVal;

			for (unsigned int i = pos; i < numElements; i++)
			{
				data[i + 1] = tmp[i];
			}
			numElements++;
			delete[] tmp;
		}
	}


	//TODO operator[] x2 
	int& operator[] (const unsigned int i)
	{
		assert(i < numElements);
		return data[i];
	}
	const int& operator[] (const unsigned int i) const
	{
		assert(i < numElements);
		return data[i];
	}

	// Copied from ricard sample code and adapted for mine --- Start
	TYPE* At(const unsigned int i)
	{
		TYPE* result = NULL;

		if (i < numElements)
			return result = &data[i];

		return result;
	}

	const TYPE* At(const unsigned int i) const
	{
		TYPE* result = NULL;

		if (i < num_elements)
			return result = &data[i];

		return result;
	}
	// Copied from ricard sample code and adapted for mine --- End


};

#endif