/*
 * linked_tree_test.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: tdwivedi
 */




#include "trees.cpp"

int main() 
{
	// your code goes here
	int i, x, N = 0;
	Tree tree ;

	//printf ("Length = %d\n", tree.Length());

	tree.Insert(5);
	tree.Insert(4);
	tree.Insert(6);

	//printf ("Length = %d\n", tree.Length());
	//tree.Print();

	tree.Insert(2);
	//tree.Insert(1);
	
	//printf ("Length = %d\n", tree.Length());
	//tree.Print();

	tree.Insert(8);

	tree.Insert(1);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(9);
/*
	tree.Insert(0);
	tree.Insert(3);
	tree.Insert(11);
	tree.Insert(12);
	tree.Insert(7);
	tree.Insert(7);
	tree.Insert(8);
	tree.Insert(10);
	tree.Insert(4);
*/	
	//tree.Print();

	//printf("Middle Element : %d\n", tree.GetMiddleElem());

	//tree.Reverse();

	//printf("Reversed : ");	
	//tree.Print();

	//tree.Delete(3);

	//printf ("Length = %d\n", tree.Length());
	tree.Print(PRE_ORDER);
	tree.Print(IN_ORDER);
	tree.Print(POST_ORDER);
        tree.Print(LEVEL_ORDER);
	tree.Print(5);

	return 0;
}
