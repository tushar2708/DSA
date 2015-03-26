#include "basic_functions.c"


/************ BUBBLE SORT ************/		// O(n^2)

Start from end (right) of array, iterate towards begining, and keep placing the smallest number of the iteration at it's place from left.

void bubble_sort(int *A, int n){

int i, j, temp = 0;

	for(i=0; i<n-1; i++){
		for(j=n;j>i;j--){
			if(A[j-1] > A[j])
			{
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
			}
		}
	}
}

/************ INSERTION SORT ************/	// O(n^2)

//	Start from second element of the array and move towards right in every iteretion, everytime compare the number with all the numbers on it's left.
//	Keep shifting them right if they are larger than the 'key' number, and swap if the number is less than 'key' number.

void insertion_sort (int* a, int n){

	int i, j, key = 0;

	for(i=1; i< n; i++){

		key = a[i];

		j = i-1;
		while (j>=0 && a[j] > key ){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

}


/************ MERGE SORT ************/		// O(n logn)

//	Keep dividing the array in two parts, and call merge_sort on them recursively.Then merge the two arrays.
//	While merging, keep taking the smaller number from both the subarrays, and putting it in a temp array, when either of the subarray is exhausted,
//	start taking numbers from the other subarrayarray.

void merge(int * A, int min, int mid, int max){

	int l = min;		// Starting of left subarray
	int r = mid + 1;	// Starting of right subarray
	int i,k = 0;

	//int L[100], R[100];

	int temp[100];

	for(i = min; l <= mid && r <=max; i++ ){

		if(A[l] <= A[r])
		{
			temp[i] = A[l];
			l++;
		} else{
			temp[i] = A[r];
			r++;
		}

	}

	if(l>mid){	// Left Subarray is exhausted

		for(k=r;k<=max;k++){
			temp[i] = A[k];
			i++;
		}

	} else {	// Right Subarray is exhausted

		for(k=l;k<=mid;k++){
			temp[i] = A[k];
			i++;
		}

	}

	for(i=min;i<=max;i++){

		A[i] = temp[i];

	}


}


void merge_sort(int * A, int min, int max){

	if (min < max){

		int mid = ( min + max ) / 2;
		merge_sort(A, min, mid);
		merge_sort(A, mid+1,max);
		merge(A, min, mid, max);

	}

}




