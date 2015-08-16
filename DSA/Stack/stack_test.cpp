//#include "stack.cpp"

#include "stack.cpp"


// Driver program to test above functions
int main()
{

	Stack<int> stack_i = Stack<int>(10);

	try {
		for (int i : {1, 2, 3, 4, 5}) {
			stack_i.Push(i);
		}

		cout << "stack_i top after pushes : " << stack_i.Peek() << endl;


		stack_i.Print();

		while(!stack_i.isEmpty()) {
			cout << "Popped from Stack_i : " << stack_i.Pop() << endl;
		}
	} catch (E & e)
	{
		cout << "Stack Error : " << e.what() << endl;
	}


	stack_i.Print();


        Stack<string> stack_s = Stack<string>(10);

        try {
                for ( const char * s : {"one", "two", "three", "four", "five"}) {
                        stack_s.Push(s);
                }

                cout << "stack_s top after pushes : " << stack_s.Peek() << endl;


                stack_s.Print();

                while(!stack_s.isEmpty()) {
                        cout << "Popped from Stack_s : " << stack_s.Pop() << endl;
                }
        } catch (E & e)
        {
                cout << "Stack Error : " << e.what() << endl;
        }


        stack_s.Print();

	return 0;

}
