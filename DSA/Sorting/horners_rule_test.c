#include <stdio.h>
#include "polynomial.c"


int main() {

        int array[7] = {31, 41, 59, 26, 41, 58};	//	31 + 41x + 59x^2 + 26x^3 + 41x^4 + 58x^5
	int x = 5;
        int size = sizeof(array)/sizeof(int);
        print_array(array, size);

	int y = horners_rule(array, size, x);
	printf("y = %d\n", y);


}
