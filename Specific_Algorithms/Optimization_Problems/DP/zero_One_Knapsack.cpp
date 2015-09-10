

/*
 *
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 *
 */


#include <iostream>
#include <cstring>
#include <sys/time.h>
#include <limits.h>

using namespace std;

int max2(int a, int b)
{
	return (a>b) ? a : b;
}

int max3(int a, int b, int c)
{
	if(a>c)
		return (a>b) ? a : b;
	else
		return (c>b) ? c : b;
}

int min3(int a, int b, int c)
{
	if(a<c)
		return (a<b) ? a : b;
	else
		return (c<b) ? c : b;
}

int knapSack_rec(int W, int wt[], int val[], int n)
{
	if(W == 0 || n == 0)
		return 0;

	if(wt[n-1] > W){
		return knapSack_rec(W, wt, val, n-1);
	} else {
		return max2 (
				knapSack_rec(W, wt, val, n-1) ,
				val[n-1] + knapSack_rec(W-wt[n-1], wt, val, n-1) 
				);
	}

}


int memo[101][101] ;


int knapSack_memoization(int W, int wt[], int val[], int n)
{

        if(W == 0 || n == 0)
		return 0;

	if(memo[W][n] !=-1) {
		
		return memo[W][n];

	} else {

		memo[W][n] = (wt[n-1] > W) ? 
				knapSack_memoization(W, wt, val, n-1) :
				max2 ( knapSack_memoization(W, wt, val, n-1) , val[n-1] + knapSack_memoization(W-wt[n-1], wt, val, n-1) );
		return memo[W][n];
	
	}
}


int knapSack_tabulation (int W, int wt[], int val[], int n)
{
	int L[W+1][n+1] ;	//L[i][j] -> Minimum number of 'i' different types of coins required to make final amonut j
	int w, j;

	for(w=0;w<=W;w++){
		for(j=0;j<=n;j++){
			if( w==0 || j==0 ){
				L[w][j] = 0;
			} else if ( wt[j-1] > w ) {
				L[w][j] = L[w][j-1];
			} else {
				L[w][j] =  max2 ( L[w] [j-1] , val[j-1] + L[ w-wt[j-1] ] [j-1] );
			}
		}
	}
	return L[W][n];
}		// -----  end of function knapSack_tabulation  ----- 



int main() {

	int val[] = {8, 4, 0, 5, 3};
	int wt[] = {1, 2, 3, 2, 2};
	int W = 4;
	int n = sizeof(val)/sizeof(val[0]);


	for(int i=0; i<=101; i++){
		for(int j=0; j<=101; j++){
			memo[i][j] = -1;
		}
	}

	struct timeval t0; gettimeofday(&t0 , NULL);

	cout << "Maximum Value Possible = " << knapSack_rec(W, wt, val, n) << endl;
	struct timeval t1; gettimeofday(&t1 , NULL);
	cout << "recursion : " << (t1.tv_sec - t0.tv_sec) << " seconds and " << (t1.tv_usec - t0.tv_usec) << " microseconds" << endl;

	cout << "Maximum Value Possible (Memoization) = "  << knapSack_memoization(W, wt, val, n) << endl;
	struct timeval t2; gettimeofday(&t2 , NULL);
	cout << "memoization : " << (t2.tv_sec - t1.tv_sec) << " seconds and " << (t2.tv_usec - t1.tv_usec) << " microseconds" << endl;

	cout << "Maximum Value Possible (Tabulation) = "  << knapSack_tabulation(W, wt, val, n) << endl;
	struct timeval t3; gettimeofday(&t3 , NULL);
	cout << "tabulation : " << (t3.tv_sec - t2.tv_sec) << " seconds and " << (t3.tv_usec - t2.tv_usec) << " microseconds" << endl;
	return 0;

}
