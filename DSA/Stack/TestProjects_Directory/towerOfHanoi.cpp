/*

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

*/



//#include "stack.cpp"

#include <math.h>

#include "../stack.cpp"

void swap(char &a, char &b)
{
	char c = a;
	a = b;
	b = c;
}

void moveDisks(Stack<int> & src, Stack<int> & dest, char s, char d)
{
	if(src.Peek() > dest.Peek()){
		cout << "Move disk " << dest.Peek() << " from " << d << " to " << s << "." << endl;
		src.Push(dest.Pop());
	} else if(src.Peek() < dest.Peek()){
		cout << "Move disk " << src.Peek() << " from " << s << " to " << d << "." << endl;
		dest.Push(src.Pop());
	}

}

void Solve_toh(int size)
{
	Stack<int> src = Stack<int>(size+1);
	Stack<int> aux = Stack<int>(size+1);
	Stack<int> dest = Stack<int>(size+1);

	src.Push(INT_MAX);
	aux.Push(INT_MAX);
	dest.Push(INT_MAX);

	char s = 'S', a = 'A', d = 'D';

	cout << "Before : a = " << a << " | d = " << d << endl;

	if(size%2 == 0)
		swap(a,d);

	cout << "After : a = " << a << " | d = " << d << endl;

	int total_moves = pow(2, size) - 1;
	cout << total_moves << endl;

	for (int i=size; i>=1; i--)
		src.Push(i);

	cout << endl << "Begining :" << endl;
	cout << "src :" << endl; src.Print();
	cout << "aux :" << endl; aux.Print();
	cout << "dest :" << endl; dest.Print();

	for (int i = 1; i<=total_moves; i++){

		if(i%3 == 1)
			moveDisks(src, dest, s, d);
		else if(i%3 == 2)
			moveDisks(src, aux, s, a);
		else{
			moveDisks(aux, dest, a, d);
			cout << endl;
		}

	}

	cout << "Optimized number of moves = " << total_moves << endl;

	cout << "Final Proof :" << endl;

	cout << "src :" << endl; src.Print();
	cout << "aux :" << endl; aux.Print();
	cout << "dest :" << endl; dest.Print();

}

// Driver program to test above functions
int main()
{
	int no_of_disks;
	cout << "Number of Disks ?" << endl;
	cin >> no_of_disks;

	Solve_toh(no_of_disks);

	return 0;

}
