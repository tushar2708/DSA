/*

   Based on following code chef problem:
https://www.codechef.com/JAN16/problems/CHMKTRPS

 */

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long max_noOfTriples = 0;
char final_triples_buffer [100];

long bsearch(long AR[], long size, long VAL)
{
	long Mid,Lbound=0,Ubound=size-1;
	while(Lbound<=Ubound)
	{
		Mid=(Lbound+Ubound)/2;
		if(VAL>AR[Mid])
			Lbound=Mid+1;
		else if(VAL<AR[Mid])
			Ubound=Mid-1;
		else
			return Mid;
	}
	return -1;
}

bool findTripletsWithSum(long A[], long arr_size, long sum)
{
	long l, m, r;
	int noOfTriples = 0;
	char triples_buffer [100];


	/* Now fix the first element one by one and find the
	   other two elements */
	for (int i = 0; i < arr_size - 2; i++)
	{

		// To find the other two elements, start two index variables
		// from two corners of the array and move them toward each
		// other
		l = i; // index of the first element in the remaining elements
		m = i+1;
		r = arr_size-1; // index of the last element

		//m = bsearch(A, arr_size, sum - l - r)
		while (m < r)
		{
			if( A[l] + A[m] + A[r] == sum)
			{
				max_noOfTriples++;
				sprintf (final_triples_buffer + strlen(final_triples_buffer), "%d %d %d ", l, m, r);
				//printf("\nTriplet is %d, %d, %d", A[l], A[m], A[r]);
				m++;
				r--;
				//return true;
			} else if (A[l] + A[m] + A[r] < sum)
				m++;
			else // A[i] + A[l] + A[r] > sum
				r--;
		}
	}

	/*
	   if (noOfTriples > max_noOfTriples)
	   {
	   max_noOfTriples = noOfTriples;
	   strcpy(final_triples_buffer, triples_buffer);
	   }
	 */


}

bool findDisjointTriplets(long A[], long arr_size)
{
	/* Sort the elements */
	sort(A, A + arr_size);
	//for(int i = 0; i< arr_size; i++)
	//	printf("%d ", A[i]);

	long max_sum = A[arr_size-1] + A[arr_size-2] + A[arr_size-3] ;
	//printf("\nmax_sum = %d\n", max_sum);

	long min_sum = A[0] + A[1] + A[2] ;
	//printf("\nmin_sum = %d\n", min_sum);

	findTripletsWithSum(A, arr_size, (max_sum + min_sum)/2);

	/*
	   for(int j = min_sum; j < max_sum; j++){
	   findTripletsWithSum(A, arr_size, j);
	   }
	 */

	printf("%d\n", max_noOfTriples);
	printf("%s", final_triples_buffer);
}

int main() {
	long N = 0;
	cin >> N;
	long array [3*N];

	for(int i = 0; i< 3*N; i++)
		scanf("%d ", &array[i]);

	findDisjointTriplets(array, 3*N);

	return 0;
}
