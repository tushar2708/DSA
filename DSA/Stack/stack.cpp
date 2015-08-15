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

#define Array_Stack Stack
//#define List_Stack Stack
#define DEFAULT_SIZE 50

using namespace std;


class Array_Stack{

	int top;
	unsigned capacity;
	int * array;

	public:
	Array_Stack(int size) {capacity = size; array = new int[capacity]; top = -1; };
	Array_Stack() {capacity = DEFAULT_SIZE; array = new int[capacity]; top = -1; };

	bool isFull();
	bool isEmpty();

	bool Push(int data);
	int Pop();
	int Peek();

	void Print();
	//void Delete(int data);
	//int Length();
	//void Delete_stack();

};

class StackNode {

	int data;
	StackNode * next;

	public:
	StackNode(){next = NULL;};
	StackNode(int item){data = item ; next = NULL;};
	void SetData(int item){data = item;};
	int GetData(){return data;};
	void SetNext(StackNode * nextAddr) { next = nextAddr; };
	StackNode * GetNext(){return next;};
};


class List_Stack{

	StackNode * top;
	int elements;
	int capacity;

	public:
	List_Stack(int size){capacity = size; elements = 0; top = NULL;};
	List_Stack() {capacity = DEFAULT_SIZE; elements = 0; top = NULL;};

        bool isFull();
        bool isEmpty();

	bool Push(int data);
	int Pop();
	int Peek();

	void Print();	
	//void Make_List();

};


bool Array_Stack::isFull()
{
//	cout << "top : " << top << " capacity : " << capacity;
	return (top == (capacity-1));
}

bool List_Stack::isFull()
{
        return (elements == capacity);
}

bool Array_Stack::isEmpty()
{
	return (top == -1);
}

bool List_Stack::isEmpty()
{
        return (top == NULL);
}

bool Array_Stack::Push(int data)
{
	if(isFull()){
		cout << "StackOverflow Happend";
		return false;
	}

	array[++top] = data;
	return true;
	//cout << data << " pushed to Array stack : " << array[top] << "\n";
}

bool List_Stack::Push(int data)
{
        if(isFull()){
                cout << "StackOverflow Happend";
                return false;
        }

	StackNode * newNode = new StackNode(data);
	newNode->SetNext(top);
        top = newNode;
	elements++;
        //cout << data << " pushed to List stack : " << data << "\n";
	return true;
}

int Array_Stack::Pop()
{
	if(isEmpty())
		return INT_MIN;

	return array[top--];
	//cout << "popped from stack : " << array[top] << "\n";
}

int List_Stack::Pop()
{
        if(isEmpty())
                return INT_MIN;

        int data = top->GetData();
	StackNode * temp = top;
	top = top->GetNext();
	delete temp;

        //cout << "popped from stack : " << data << "\n";
	return data;
}

int Array_Stack::Peek()
{
        if(isEmpty())
                return INT_MIN;

	//cout << "peeked from stack : " << array[top] << "\n";
        return array[top];
}

int List_Stack::Peek()
{
        if(isEmpty())
                return INT_MIN;

        int data = top->GetData();
 
        //cout << "peeked from stack : " << data << "\n";
        return data;
}

void Array_Stack::Print()
{
	cout << "[Top] ";

	for(int i = top; i>=0; i--)
		cout << "-> " <<array[i] << " ";

	cout << "[Bottom]\n";
}

void List_Stack::Print()
{
        cout << "[Top] ";

	StackNode * temp = top;

        while(temp) {
                cout << "-> " << temp->GetData() << " ";
		temp = temp->GetNext();
	}

        cout << "[Bottom]\n";
}
