#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../../Common/basic_functions.c"
#include "msa_algorithms.c"

int main ()
{

int size, start, end, max_sum = 0;
int array[] = {1, -3, 2, -5, 7, 6, -1, -4, 11, -23};	// These values aren't being used.
size = sizeof(array)/sizeof(int);

randomize_array(array, size);

printf("Random Input Array :\n");
print_array(array, size);



//max_sum = msa_brute_force(array, size, &start, &end);i
//printf("start = %d, end = %d, maximum sum = %d\n", start, end, max_sum);

//max_sum = msa_using_DP(array, size, &start, &end);
//printf("start = %d, end = %d, maximum sum = %d\n", start, end, max_sum);

//int *start_ptr, *end_ptr = NULL;
//max_sum = msa_using_DnC(array, size, &start_ptr, &end_ptr);
//printf("maximum sum = %d\n",, max_sum);

max_sum = msa_using_Kadane(array, size, &start, &end);
printf("start = %d, end = %d, maximum sum = %d\n", start, end, max_sum);
//print_subarray(array, start, end);

}


