
#include<limits.h>


/********** 	BRUTE FORCE APPROACH	**********/	// O(n^3)

int msa_brute_force(int * array, int n, int * start, int * end)
{

	int i, j, k, sum, max_sum = 0;
	max_sum = INT_MIN;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{		
			sum = 0;

			for (k = i; k<=j; k++)
			{
				//printf ("before : array[%d] = %d & sum = %d\n", k, array[k], sum);
				sum += array[k];
				//printf ("after : array[%d] = %d & sum = %d\n", k, array[k], sum);
			}
			//printf("start = %d, end = %d, sum = %d\n", i, j, sum);
			if(sum > max_sum)
			{
				//printf("max_sum to be changed from %d to %d\n", max_sum, sum);
				max_sum = sum;
				*start = i;	*end = j;
			}
			//printf("max_sum = %d\n", max_sum);
		}


	}
	return max_sum;

}


/**********     DYNAMIC PROGRAMMING APPROACH    **********/     // O(n^2)

int msa_using_DP(int * array, int n, int * start, int * end)
{

	int start_index, sub_array_size, k, sum, max_sum = 0;
	max_sum = INT_MIN;

	for (start_index = 0; start_index < n; start_index++)
	{
		sum = 0;
		for (sub_array_size = 1; start_index + sub_array_size <=n; sub_array_size++)
		{	

			sum += array[start_index + sub_array_size - 1];			//	Last element of new subarray

			if(sum > max_sum)
			{
				max_sum = sum;
				*start = start_index;     *end = start_index + sub_array_size;
			}
		}


	}
	return max_sum;

}


/**********     DIVIDE AND CONQUER APPROACH    **********/     // O(n logn)

int msa_using_DnC(int array[], int n, int ** start, int ** end)
{

	if (n == 1)
		return array[0];	// Base case of recursion

	int m = n/2;	// Divide the array into 2 sub-arrays

	// The final Max sum Sub Array will quilify either of three cases :
	// 1. Entirely in left subarray.
	// 2. Entirely in left subarray.
	// 3. Starts in Left SA, and ends in Right SA.

	// Calculating Case 1:
	int left_msa = msa_using_DnC(array, m, start, end);

	// Calculating Case 2:
	int right_msa = msa_using_DnC(array + m, (n - m), start, end);

	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int i, sum = 0;

	// Calculating Case 3:

	// Calculate the maximum of the sums of all right subarrays
	for (i = m; i < n; i++)
	{
		sum += array[i];
		right_sum = max_2(right_sum, sum);

	}

	sum = 0;

	// Calculate the maximum of the sums of all left subarrays
	for (i = (m-1); i >= 0; i--)
	{
		sum += array[i];
		left_sum = max_2(left_sum, sum);
	}

	return max_3(left_msa, (left_sum + right_sum), right_msa);

}

/**********     KADANE'S ALGORITHM    **********/     // O(n)

int msa_using_Kadane(int * array, int n, int * start, int * end)
{
	int i = 0, max_sum = 0, sum = 0;

	*start = 0;

	for(i = 0; i< n; i++)
	{
		if(sum + array[i] > 0)
			sum += array[i];
		else
		{
			sum = 0;
		}

		*end = i;

		if(sum < max_sum)
		{
			*start = i;
		}
		max_sum = max_2(max_sum, sum);
	}

	return max_sum;

}

