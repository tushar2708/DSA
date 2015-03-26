#include <stdio.h>
#include "search.c"

int main(){

int array[] = {31, 41, 59, 26, 49, 58, 36, 75, 54,  89, 13, 43, 62, 47};
int key = 75;
int size = sizeof(array)/sizeof(int);
int index = linear_search(array, key, size);

printf("Index of %d = %d\n", key, index);

}
