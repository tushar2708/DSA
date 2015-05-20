/*
 * linked_list.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: tdwivedi
 */



#include <iostream>
using namespace std;

class Node{

	int data;
	Node * next;

	public:
	Node(){};
	void SetData(int aData){data = aData;};
	void SetNext(Node * aNext){next = aNext;};
	int GetData(){return data;};
	Node* GetNext(){return next;};

};

class List{

	Node* First;

	public:
	List() {First = NULL;};
	void Print();
	void Prepend(int data);
	void Append(int data);
	void Sorted_Insert(int data);

	void Delete(int data);
	int Length();
	int GetNthNode(int n);
	void Delete_using_ptr_wrapper(){Delete_using_ptr(((First->GetNext())->GetNext())->GetNext());};
	//void Delete_using_ptr_wrapper(){Delete_using_ptr(First->GetNext());};
	void Delete_using_ptr(Node * node);
	int GetMiddleElem();
	void Delete_list();
	void Reverse();
	void Create_loop();
	int Detect_loop();
	void Delete_Duplicates();



};

class Stack{

	List * list;

	public:
	int Pop();
	int Top();
	int Push(int x);
	int Empty();
	void Make_List();

};



void List::Print(){

	Node * temp = First;
	if(temp == NULL) {
		printf("EMPTY\n" );
	} else {
		while(temp != NULL){
			printf("%d-->", temp->GetData());
			temp = temp->GetNext();
		}
		printf("NULL\n");
	}

}

void List::Append(int data){

	Node* new_node = new Node();

	new_node->SetData(data);
	new_node->SetNext(NULL);

	Node * temp = First;
	if(temp == NULL){
		First = new_node;
	} else {

		while(temp->GetNext() != NULL){
			temp = temp->GetNext();
		}
		temp->SetNext(new_node);


	}
}

void List::Prepend(int data){

	Node* new_node = new Node();

	new_node->SetData(data);
	new_node->SetNext(First);

	First = new_node;
}

void List::Sorted_Insert(int data)
{
	Node * current = First;
	Node * new_node = new Node();

	new_node->SetData(data);

	if(First == NULL || First->GetData() >= data){
		new_node->SetNext(First);
		First = new_node;
	} else {
		while(current->GetNext() != NULL && (current->GetNext())->GetData() <= data)
			current = current->GetNext();

		new_node->SetNext(current->GetNext());
		current->SetNext(new_node);
	}



}

void List::Delete(int data){

	Node * prev = First;
	Node * current = First;
	if(First == NULL){
		return;
	} else {
		while(current != NULL){
			if(current->GetData() == data ){
				if(current == First){
					First = First->GetNext();
					delete current;
					return;
				} else {
					prev->SetNext(current->GetNext());
					delete current;
					return;
				}

			}
			prev = current;
			current = current->GetNext();

		}

	}
}

void List::Delete_using_ptr(Node * node){

	Node * prev = First;
	Node * current = First;
	if(First == NULL){
		return;
	} else {
		while(current != NULL){
			if(current == node ){
				if(current == First){
					First = First->GetNext();
					delete current;
					return;
				} else {
					prev->SetNext(current->GetNext());
					delete current;
					return;
				}

			}
			prev = current;
			current = current->GetNext();

		}

	}
}

int List::Length()
{

	int count = 0;
	Node * temp = First;

	while (temp != NULL){

		count++;
		temp = temp->GetNext();

	}

	return count;

}

int List::GetNthNode(int n)
{
	int i = 0;
	Node * temp = First;
	for (i=0; i < n; i++){
		temp = temp->GetNext();
		if (temp == NULL)
			return -1;
	}
	return temp->GetData();
}

int List::GetMiddleElem(){

	Node * slow_ptr = First,  * fast_ptr = First;

	while (fast_ptr != NULL && fast_ptr->GetNext() != NULL){

		slow_ptr = slow_ptr->GetNext();
		fast_ptr = (fast_ptr->GetNext())->GetNext();

	}

	return slow_ptr->GetData();

}

void List::Delete_list()
{

	Node * current = First;
	Node * next;
	while (current != NULL) {

		next = current->GetNext();
		delete current;
		current = next;
	}

	First = NULL;

}


void List::Reverse()
{

	Node * prev = NULL, * next = NULL;
	Node * current = First;

	while (current != NULL){

		next = current->GetNext();
		current->SetNext(prev);

		prev = current;
		current = next;
	}

	First = prev;

}


void List::Create_loop()
{
	Node * current = First;

	while (current->GetNext() != NULL)
		current = current->GetNext();


	current->SetNext(First->GetNext());

}


int List::Detect_loop()
{
	Node * slow_ptr = First,  * fast_ptr = First;

	while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->GetNext() != NULL) {

		slow_ptr = slow_ptr->GetNext();
		fast_ptr = (fast_ptr->GetNext())->GetNext();

		if (slow_ptr == fast_ptr) {

			printf("\nFound Loop\n");
			return 1;

		}

	}

	printf("\nDidn't Find Loop\n");
	return 0;

}


void List::Delete_Duplicates()
{

	Node * current, * next, *next_next;

	current = First;
	while(current->GetNext() != NULL) {

		next = current->GetNext();

		if (current->GetData() == next->GetData()) {
			next_next = next->GetNext();
			delete next;
			current->SetNext(next_next);	
		} else {
			current = next;
		}
	}

}

