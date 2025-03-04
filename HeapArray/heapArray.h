#pragma once

class HeapArray
{
public:
	HeapArray(int);
	HeapArray(HeapArray&); 
	~HeapArray();

	void setElement(int,int);
	int getElement(int);

	int getSize();

	void addLast(int);
private:

	int capacity;
	int size; 
	int* arrayPointer;

};

	