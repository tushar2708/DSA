#include <iostream>

using namespace std;

int findOddOccurance(int * arr, int size)
{
	int result = 0;
	for (int i=0;i<size;i++)
	{
		result = result^arr[i];
	}
	return result;
}

int main() {

	int A[10] = {1, 2, 3, 1, 2, 3, 1};

	cout << "This one came odd number of times : " << findOddOccurance(A, 7) << endl;
}
