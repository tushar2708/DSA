#include <stdio.h>
#include "sorting.c"


int main() {

	int array[7] = {31, 41, 59, 26, 41, 58};
	int size = sizeof(array)/sizeof(int);
	print_array(array, size);
	//insertion_sort(array, size);
	merge_sort(array, 0, size-1);
	print_array(array, size);

}
