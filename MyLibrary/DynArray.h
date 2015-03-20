#pragma once
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
	DynArray<TYPE>(unsigned int newSize)
	{
		data = NULL;
		numElements = 0;
		reallocate(newSize);
	}
	~DynArray<TYPE>() 
	{ 
		if (data != NULL) delete[] data; 
	}

	

	//TODO Push_Back:
	void pushBack(TYPE val)
	{
		if (numElements == allocatedMemory)
			reallocate(allocatedMemory + 1);

		data[numElements] = val;
		numElements++;
	}
	//TODO Pop:
	TYPE pop()
	{
		// When the element is deleted, it is necessary to return a copy of that element.
		if (data != NULL && numElements != 0)
		{
			num_elements--;
			TYPE ret = data[numElements];
			return ret;
		}
		return -1;
	}
	//TODO Clear:
	void clear()
	{
		numElements = 0;
	}
	//TODO Insert:
};

