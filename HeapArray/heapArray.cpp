#include "heapArray.h"

#include <utility>

HeapArray::HeapArray(int capacity)
{
	this->capacity = capacity;

	this->size = 0;

	this->arrayPointer = new int[capacity];
}

HeapArray::HeapArray(HeapArray& other)
{
	capacity = other.capacity;
	size = other.size;

	arrayPointer = new int[capacity];

	for (int64_t i = 0; i < size; i++)
	{
		arrayPointer[i] = other.arrayPointer[i];
	}
}


HeapArray::~HeapArray()
{
	delete[] arrayPointer;
}

void HeapArray::setElement(int position, int value)
{
	arrayPointer[position] = value;
}

int HeapArray::getElement(int position) {
	return position;
}

int HeapArray::getSize()
{
	return size;
}

void HeapArray::addLast(int value)
{
	if (capacity < size)
	{
		capacity = std::max(capacity * 2, 1);
		int* tempArray = new int[capacity];

		for (int64_t i = 0; i < size; i++)
		{
			tempArray[i] = arrayPointer[i];
		}

		delete[] arrayPointer;

		arrayPointer = tempArray;
	}

	arrayPointer[size++] = value;
}
