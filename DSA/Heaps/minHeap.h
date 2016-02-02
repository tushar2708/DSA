#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
using namespace std;

class MinHeap
{
private:
    vector<int> _vector;
    //void BubbleDown(int index);
    //void BubbleUp(int index);
    void Heapify(int index);

public:
    MinHeap(int* array, int length);
    MinHeap(const vector<int>& vector);
    MinHeap();

    void Insert(int newValue);
    int GetMin();
    void DeleteMin();
};

#endif
