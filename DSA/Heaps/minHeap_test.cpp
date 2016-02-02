#include "../stdafx.h"
#include "minHeap.h"

int main()
{
		//int array[] = {10, 4, 5, 30, 3, 300};
		int array[] = {2, 5, 7, 30, 50, 300, 400};

		MinHeap minHeap(array, 7);

		for(int i=0; i<3; ++i)
		{
				cout << minHeap.GetMin() << "  ";
				minHeap.DeleteMin();
		}

		cout << endl;

		return 0;
}
