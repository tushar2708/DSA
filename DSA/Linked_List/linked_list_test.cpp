/*
 * linked_list_test.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: tdwivedi
 */




#include "linked_list.cpp"

int main() 
{
	// your code goes here
	int i, x, N = 0;
	List list ;

	printf ("Length = %d\n", list.Length());

	list.Append(3);
	list.Append(4);
	list.Append(5);

	printf ("Length = %d\n", list.Length());
	list.Print();

	list.Prepend(2);
	//list.Prepend(1);
	
	printf ("Length = %d\n", list.Length());
	list.Print();

	list.Append(9);

	list.Sorted_Insert(12);
	list.Sorted_Insert(1);
	list.Sorted_Insert(0);
	list.Sorted_Insert(6);
	list.Sorted_Insert(0);
	list.Sorted_Insert(3);
	list.Sorted_Insert(11);
	list.Sorted_Insert(12);
	list.Sorted_Insert(7);
	list.Sorted_Insert(7);
	list.Sorted_Insert(8);
	list.Sorted_Insert(10);
	list.Sorted_Insert(4);
	list.Print();

	printf("Middle Element : %d\n", list.GetMiddleElem());

	//list.Reverse();

	//printf("Reversed : ");	
	//list.Print();

	list.Delete(3);

	printf ("Length = %d\n", list.Length());
	list.Print();

	printf("0 : %d\n", list.GetNthNode(0));

	printf("3 : %d\n", list.GetNthNode(3));

	printf("10 : %d\n", list.GetNthNode(10));

	//list.Delete_using_ptr_wrapper();

	list.Print();

	//list.Create_loop();
	int isLoop = list.Detect_loop();

	list.Delete_Duplicates();
        printf ("Length = %d\n", list.Length());
        list.Print();





	if(isLoop == 0) {
	list.Delete_list();

	printf ("Length = %d\n", list.Length());
	list.Print();

	}

	return 0;
}
