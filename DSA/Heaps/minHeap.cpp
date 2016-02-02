#include "../stdafx.h"
#include "minHeap.h"

inline int parent(int i)
{
	return (i-1)/2;
}

inline int leftChild(int i)
{
    return 2*i + 1;
}

inline int rightChild(int i)
{
    return 2*i + 2;
}

MinHeap::MinHeap(int* array, int length) : _vector(length)
{
    for(int i = 0; i < length; ++i)
    {
        _vector[i] = array[i];
    }

	for(int i = length/2 ; i>=0; i--)
    	Heapify(i);
}

MinHeap::MinHeap(const vector<int>& vector) : _vector(vector)
{
    Heapify(0);
}

MinHeap::MinHeap() 
{
}

void MinHeap::Heapify(int index)
{
    int length = _vector.size();
	int i = index;
	int left = leftChild(i);
	int right = rightChild(i);
	int swap = 0;
    while(left < length)
    {
        if(_vector[i] > _vector[left] || ( right < length && _vector[i] > _vector[right]))
		{
			swap = (_vector[left] < _vector[right]) ? left : right;
			int temp = _vector[swap];
			_vector[swap] = _vector[i];
			_vector[i] = temp;
			i = swap;
			left = leftChild(i);
			right = rightChild(i);
		} else 
		{
			break;
		}
    }
}

void MinHeap::Insert(int newValue)
{
    int length = _vector.size();
    _vector[length] = newValue;

    //BubbleUp(length);

	int i = length;

	while(i > 0){
		if(_vector[i] <= _vector[parent(i)])
		{
			int temp =_vector[i];
			_vector[i] = _vector[parent(i)];
			_vector[parent(i)] = temp;
		}
		i = parent(i);
	}
}

int MinHeap::GetMin()
{
	return _vector[0];
}

void MinHeap::DeleteMin()
{
	int length = _vector.size();
	_vector[0] = _vector[length - 1];
	_vector.pop_back();
	Heapify(0);
}
