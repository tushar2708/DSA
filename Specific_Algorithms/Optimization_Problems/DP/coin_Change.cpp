

// A given cost matrix. Have to find the minimum cost of reaching a point (m,n) from (0,0)


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


int Coins_rec(int * S, int m, int n)
{
	if(n == 0)
		return 1;

	if(n < 0)
		return 0;

	if(m<=0 && n >=0){
		return 0;
	}

	return ( Coins_rec( S, m-1, n ) + Coins_rec( S, m, n - S[m-1] ) );
}


int memo[101][101] ;


int Coins_memoization(int * S, int m, int n)
{

	if(n == 0)
		return 1;

	if(n < 0)
		return 0;

	if(m<=0 && n >=0){
		return 0;
	}

	if(memo[m][n] !=-1) {

		return memo[m][n];
	} else
	{
		memo[m][n] = ( Coins_memoization( S, m-1, n ) + Coins_memoization( S, m, n - S[m-1] ) );
		return memo[m][n];
	}

}


int Coins_tabulation (int * S, int m, int n)
{
	int L[m+1][n+1] ;	//L[i][j] -> Minimum number of 'i' different types of coins required to make final amonut j
	int i, j;

	L[0][0] = 1;

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if (i == 0 && j >= 0) {
				L[0][j] = 0;
			} else if (i > 0 && j == 0) {
				L[i][0] = 1;
			} else {
				L[i][j] = ( (i >= 1) ? L[i-1][j] : 0 ) + ( (j - S[i-1] >=0) ? L[i][j - S[i-1]] : 0 ) ;
			}
		}
	}
	return L[m][n];
}		// -----  end of function Coins_tabulation  ----- 




int main() {

	int arr[] = {2, 5, 3, 6};
	int m = sizeof(arr)/sizeof(arr[0]);
	int n;

	cout << "Enter the amount" << endl;
	cin >> n;

	for(int i=0; i<=101; i++){
		for(int j=0; j<=101; j++){
			memo[i][j] = -1;
		}
	}

	struct timeval t0; gettimeofday(&t0 , NULL);

	cout << "Number of Ways = " << Coins_rec(arr, m, n) << endl;
	struct timeval t1; gettimeofday(&t1 , NULL);
	cout << "recursion : " << (t1.tv_sec - t0.tv_sec) << " seconds and " << (t1.tv_usec - t0.tv_usec) << " microseconds" << endl;

	cout << "Number of Ways (Memoization) = "  << Coins_memoization(arr, m, n) << endl;
	struct timeval t2; gettimeofday(&t2 , NULL);
	cout << "memoization : " << (t2.tv_sec - t1.tv_sec) << " seconds and " << (t2.tv_usec - t1.tv_usec) << " microseconds" << endl;


	cout << "Number of Ways (Tabulation) = "  << Coins_tabulation(arr, m, n) << endl;
	struct timeval t3; gettimeofday(&t3 , NULL);
	cout << "tabulation : " << (t3.tv_sec - t2.tv_sec) << " seconds and " << (t3.tv_usec - t2.tv_usec) << " microseconds" << endl;

	return 0;

}
