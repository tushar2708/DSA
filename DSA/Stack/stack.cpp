/*
 * linked_list.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: tdwivedi
 */



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string>
#include <exception>

using namespace std;

#define Array_Stack Stack
//#define List_Stack Stack

class E : public std::exception {

public:
	explicit E(const char * s) throw() : msg(s) { }
	const char * what() const throw() {return msg;}
private:
	E(){};
	const char * msg;

};

template <typename T>
class Array_Stack {

	static const int default_size = 20;
	int top;
	unsigned int capacity;
	T * array;

	public:
	explicit Array_Stack(int size = default_size) {capacity = size; array = new T[capacity]; top = -1; };
	//Array_Stack() {capacity = DEFAULT_SIZE; array = new T[capacity]; top = -1; };
	~Array_Stack() {delete[] array;};

	bool isFull(){return (top == (capacity-1));};
	bool isEmpty(){return (top == -1);};

	T & Push(const T & data);
	T & Pop();
	T & Peek();

	void Print();
	//void Delete(int data);
	//int Length();
	//void Delete_stack();

};

template <typename T>
class StackNode {

	T data;
	StackNode * next;

	public:

	StackNode(const T & item = 0){data = item ; next = nullptr;};
	void SetData(const T & item){data = item;};
	T & GetData(){return data;};
	void SetNext(StackNode * nextAddr) { next = nextAddr; };
	StackNode * GetNext(){return next;};
};

template <typename T>
class List_Stack{

	static const int default_size = 20;
	StackNode<T> * top;
	int elements;
	int capacity;

	public:
	List_Stack(int size = default_size){capacity = size; elements = 0; top = nullptr;};
	//List_Stack() {capacity = DEFAULT_SIZE; elements = 0; top = nullptr;};

        bool isFull(){return (elements == capacity);};
        bool isEmpty(){return (top == nullptr);};

	const T & Push(T const & data);
	const T Pop();
	const T Peek();

	void Print();
};




template <typename T>
T & Array_Stack<T>::Push(T const & data)
{
	if(isFull()){
		throw E("Stack Full");
		//cout << "StackOverflow Happend";
		//return false;
	}

	return array[++top] = data;
}

template <typename T>
const T & List_Stack<T>::Push(const T & data)
{
        if(isFull()){
		throw E("Stack Full");
                //cout << "StackOverflow Happend";
                //return false;
        }

	StackNode<T> * newNode = new StackNode<T>(data);
	newNode->SetNext(top);
        top = newNode;
	elements++;
	return data;
}

template <typename T>
T & Array_Stack<T>::Pop()
{
	if(isEmpty())
		throw E("Stack Empty");

	return array[top--];
	//cout << "popped from stack : " << array[top] << "\n";
}

template <typename T>
const T List_Stack<T>::Pop()
{
        if(isEmpty())
                throw E("Stack Empty");

        const T data = top->GetData();
	StackNode<T> * temp = top;
	top = top->GetNext();
	delete temp;

	return data;
}

template <typename T>
T & Array_Stack<T>::Peek()
{
        if(isEmpty())
                throw E("Stack Empty");

        return array[top];
}

template <typename T>
const T List_Stack<T>::Peek()
{
        if(isEmpty())
                throw E("Stack Empty");

        const T data = top->GetData();

        return data;
}

template <typename T>
void Array_Stack<T>::Print()
{
	cout << "[Top] ";

	for(int i = top; i>=0; i--)
		cout << "-> " <<array[i] << " ";

	cout << "[Bottom]\n";
}

template <typename T>
void List_Stack<T>::Print()
{
        cout << "[Top] ";

	StackNode<T> * temp = top;

        while(temp) {
                cout << "-> " << temp->GetData() << " ";
		temp = temp->GetNext();
	}

        cout << "[Bottom]\n";
}
