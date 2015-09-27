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
/*
	Tree<int> tree ;

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
	tree.Print(PRE_ORDER);
	tree.Print(IN_ORDER);
	tree.Print(POST_ORDER);
        //tree.Print(LEVEL_ORDER);
	tree.Print(5);

	cout << "Size before deletion = " << tree.Size() << "\n";

	tree.Delete(4);

	cout << "Value to be Deleted : 4\n" ;

        tree.Print(PRE_ORDER);
        tree.Print(IN_ORDER);
        tree.Print(POST_ORDER);

	cout << "Size after deletion = " << tree.Size() << "\n";
*/




	Tree<string> tree ;

	//printf ("Length = %d\n", tree.Length());

	tree.Insert("e");
	tree.Insert("d");
	tree.Insert("f");

	//printf ("Length = %d\n", tree.Length());
	//tree.Print();

	tree.Insert("b");
	//tree.Insert("a");
	
	//printf ("Length = %d\n", tree.Length());
	//tree.Print();

	tree.Insert("h");

	tree.Insert("a");
	tree.Insert("c");
	tree.Insert("g");
	tree.Insert("i");
	tree.Print(PRE_ORDER);
	tree.Print(IN_ORDER);
	tree.Print(POST_ORDER);
        //tree.Print(LEVEL_ORDER);
	tree.Print(5);

	cout << "Size before deletion = " << tree.Size() << "\n";

	tree.Delete("d");

	cout << "Value to be Deleted : d\n" ;

        tree.Print(PRE_ORDER);
        tree.Print(IN_ORDER);
        tree.Print(POST_ORDER);

	cout << "Size after deletion = " << tree.Size() << "\n";





	return 0;
}
