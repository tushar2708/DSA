/*
 *	queue.cpp
 *
 *	Created on: Sep 09, 2015
 *	Author: tdwivedi
 */



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string>
#include <exception>

using namespace std;

//#define Array_Queue Queue
//#define List_Queue Queue

class E : public std::exception {

public:
	explicit E(const char * s) throw() : msg(s) { }
	const char * what() const throw() {return msg;}
private:
	E(){};
	const char * msg;

};

template <typename T>
class Array_Queue {

	static const int default_size = 20;
	int front, rear, size;
	unsigned int capacity;
	T * array;

	public:
	explicit Array_Queue(int _capacity = default_size) {capacity = _capacity; array = new T[capacity]; front=0; size=0; rear=-1; };
	//Array_Queue() {capacity = DEFAULT_SIZE; array = new T[capacity]; front = -1; };
	~Array_Queue() {delete[] array;};

	bool isFull(){return (size == capacity);};
	bool isEmpty(){return (size == 0);};

	T & Enqueue(const T & data);
	T & Dequeue();
	T & Front();
	T & Rear();

	void Print();
	//void Delete(int data);
	//int Length();
	//void Delete_queue();

};

template <typename T>
class QueueNode {

	T data;
	QueueNode * next;

	public:

	QueueNode(const T & item = 0){data = item ; next = nullptr;};
	void SetData(const T & item){data = item;};
	T & GetData(){return data;};
	void SetNext(QueueNode * nextAddr) { next = nextAddr; };
	QueueNode * GetNext(){return next;};
};

template <typename T>
class List_Queue{

	static const int default_size = 20;
	QueueNode<T> * front, * rear;
	int size;
	int capacity;

	public:
	List_Queue(int _capacity = default_size){capacity = _capacity; size = 0; front = nullptr; rear = nullptr;};
	//List_Queue() {capacity = DEFAULT_SIZE; size = 0; front = nullptr;};

        bool isFull(){return (size == capacity);};
        bool isEmpty(){return (front == nullptr);};

	const T & Enqueue(T const & data);
	const T Dequeue();
	const T Front();
	const T Rear();

	void Print();
};




template <typename T>
T & Array_Queue<T>::Enqueue(T const & data)
{
	if(isFull()){
		throw E("Queue Full");
		//cout << "QueueOverflow Happend";
		//return false;
	}

	size++;
        rear = (++rear)%capacity;
	return array[rear] = data;
}

template <typename T>
const T & List_Queue<T>::Enqueue(const T & data)
{
        if(isFull()){
		throw E("Queue Full");
                //cout << "QueueOverflow Happend";
                //return false;
        }
	
		

	QueueNode<T> * newNode = new QueueNode<T>(data);
	if(isEmpty()) {
		front = rear = newNode;
		return data;
	}

	rear->SetNext(newNode);
        rear = newNode;
	size++;
	return data;
}

template <typename T>
T & Array_Queue<T>::Dequeue()
{
	if(isEmpty())
		throw E("Queue Empty");

	size--;
	int _front = front;
	front = (++front)%capacity;
	return array[_front];
	//cout << "popped from queue : " << array[front] << "\n";
}

template <typename T>
const T List_Queue<T>::Dequeue()
{
        if(isEmpty())
                throw E("Queue Empty");

        const T data = front->GetData();
	QueueNode<T> * temp = front;
	front = front->GetNext();

	if(front == nullptr)
		rear = nullptr;
	delete temp;

	return data;
}

template <typename T>
T & Array_Queue<T>::Front()
{
        if(isEmpty())
                throw E("Queue Empty");

        return array[front];
}

template <typename T>
const T List_Queue<T>::Front()
{
        if(isEmpty())
                throw E("Queue Empty");

        const T data = front->GetData();

        return data;
}

template <typename T>
T & Array_Queue<T>::Rear()
{
        if(isEmpty())
                throw E("Queue Empty");

        return array[rear];
}

template <typename T>
const T List_Queue<T>::Rear()
{
        if(isEmpty())
                throw E("Queue Empty");

        const T data = rear->GetData();

        return data;
}


template <typename T>
void Array_Queue<T>::Print()
{
	cout << "[Front] ";

	int i = front - 1;

	if (!isEmpty()) {
		do {
			i = (++i)%capacity;
			cout << "-> " << array[i] << " ";
		} while (i!=rear);
	}

	cout << "[Rear]\n";
}

template <typename T>
void List_Queue<T>::Print()
{
        cout << "[Front] ";

	QueueNode<T> * temp = front;

        while(temp) {
                cout << "-> " << temp->GetData() << " ";
		temp = temp->GetNext();
	}

        cout << "[Rear]\n";
}
