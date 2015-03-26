
#include "basic_functions.c"

int horners_rule(int * a, int n, int x)
{

	int i, y = 0;

	for(i = 0; i < n; i++) {
		y = a[i] + x*y;
	}

	return y;

}

