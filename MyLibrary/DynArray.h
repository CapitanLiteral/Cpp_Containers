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
			// Reallocating data Space
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




	DynArray(){}
	~DynArray(){}

	//TODO Push_Back:
	//TODO Pop:
	//TODO Clear:
	//TODO Insert:
};

