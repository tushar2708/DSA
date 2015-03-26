void print_array(int arr[], int n){
	int i =0;
	printf("[ ");
	for(i=0; i<n; i++)
		printf("%d  ", arr[i]);
	printf("]\n");

}

void print_subarray(int arr[], int start, int end){
	int i =0;
	printf("{ ");
	for(i=start; i<=end; i++)
		printf("%d  ", arr[i]);
	printf("}\n");
}

int max_2(int a, int b)
{
	return (a > b ? a : b);
}

int max_3(int a, int b, int c)
{
	return (a > b ? max_2(a,c) : max_2(b,c));
}

void randomize_array(int * arr, int n)
{
	int i = 0;

	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		arr[i] = rand()%23;
	}
}
