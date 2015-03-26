#include <stdio.h>
#include "sorting.c"


int main() {

	int array[] = {31, 41, 59, 26, 41, 58};
	int size = sizeof(array)/sizeof(int);
	print_array(array, size);
	bubble_sort(array, size);
	print_array(array, size);

}
