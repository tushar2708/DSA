#include "../stdafx.h"
#include "../Heaps/minHeap.h"

int main()
{
		int array1[] = {10, 4, 5, 30, 3, 300};
		int array2[] = {2, 5, 7, 30, 50, 300, 400};

		MinHeap minHeap1(array1, 6);
		MinHeap minHeap2(array2, 7);

		for(int i=0; i<6; ++i)
		{
				array1[i] =  minHeap1.GetMin();
				minHeap1.DeleteMin();
		}

		for(int i=0; i<7; ++i)
		{
				array2[i] =  minHeap2.GetMin();
				minHeap2.DeleteMin();
		}
		int * array3 = new int[6];
		int k=0;
		for(int i=0, j=0; i<6, j<7; )
		{
				if(array1[i] < array2[j])
						i++;
				else if (array1[i] > array2[j])
						j++;
				else{
						array3[k] = array1[i];
						i++;
						j++;
						k++;
				}
		}

		for(int i=0; i<k; ++i)
		{
				cout << array3[i] << " " ;
		}


		cout << endl;

		return 0;
}
