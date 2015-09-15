/*

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

*/



//#include "stack.cpp"

#include "../stack.cpp"


void calculateSpan(int * Price, int * Span, int size)
{
	Stack<int> stack_i = Stack<int>(size);
	
	stack_i.Push(0);
	Span[0] = 1;

	for (int i=1; i<size; i++){
		// Keep Popping elements from stack unless larger element to left is found.
		while (!stack_i.isEmpty() && Price[i] >= Price[stack_i.Peek()])
			stack_i.Pop();

		// Once that element is found, calculate the difference between the two.
		Span[i] = (stack_i.isEmpty()) ? (i+1) : i - stack_i.Peek();

		// Push the current element to stack as well.
		stack_i.Push(i);
	}

}

// Driver program to test above functions
int main()
{

	int Price[] = {10, 4, 5, 90, 120, 80};
	int size = sizeof(Price) / sizeof(int);
	int Span[size];

	cout << "Span of Stocks :" << endl;

	calculateSpan(Price, Span, size);

	for (int i=0; i<size; i++){
		cout << "Span of Price[" << i << "] (" << Price[i] <<") is " << Span[i] << endl;
	}

	return 0;

}
