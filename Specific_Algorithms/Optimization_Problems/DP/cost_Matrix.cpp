

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


int MinCost_rec(int X[][4], int m, int n)
{
	if(m==0 && n ==0){
		return 0;
	}

	if (m<0 || n<0)
		return INT_MAX;

	return ( X[m][n] + min3 ( MinCost_rec(X, m, n-1), MinCost_rec(X, m-1, n), MinCost_rec(X, m-1, n-1) ) );

}


int memo[101][101] ;


int MinCost_memoization(int X[][4], int m, int n)
{
	if(m==0 && n ==0){
		memo[m][n] = 0;
		//	cout << "1 : memo[" << m <<"][" << n << "] : " << memo[m][n] << endl ;
		return memo[m][n];
	}

	if (m<0 || n<0)
		return INT_MAX;

	if(memo[m][n] !=-1) {
		//	cout << "2 : memo[" << m <<"][" << n << "] : " << memo[m][n] << endl ;
		return memo[m][n];
	} else
	{
		memo[m][n] =  X[m][n] + min3 ( MinCost_rec(X, m, n-1), MinCost_rec(X, m-1, n), MinCost_rec(X, m-1, n-1) );
		//	cout << "3 : memo[" << m <<"][" << n << "] : " << memo[m][n] << endl ;
		return memo[m][n];
	}

}


int MinCost_tabulation (int X[][4], int m, int n)
{
	int L[m+1][n+1] ;	//L[i][j] -> MinCost of Cost(0,0) to Cost(m,n)
	int i, j;

	L[0][0] = X[0][0];

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if (i == 0 && j > 0) {
				L[i][j] = L[0][j-1] + X[0][j];
			} else if (i > 0 && j == 0) {
				L[i][j] = L[i-1][0] + X[i][0];
			} else {
				L[i][j] =  X[i][j] + min3 ( L[i][j-1], L[i-1][j], L[i-1][j-1] ) ;
			}
		}
	}

	return L[m][n];
}		// -----  end of function MinCost_tabulation  ----- 




int main() {

	int Cost[4][4] = {1, 2, 3, 4,
			  5, 6, 7, 8,
			  8, 7, 6, 5,
			  4, 3, 2, 1};

	for(int i=0; i<=101; i++){
		for(int j=0; j<=101; j++){
			memo[i][j] = -1;
		}
	}

	struct timeval t0; gettimeofday(&t0 , NULL);

	cout << "MinCost[2][3] ie. " << Cost[2][3] << " = " << MinCost_rec(Cost, 2, 3) << endl;
	struct timeval t1; gettimeofday(&t1 , NULL);
	cout << "recursion : " << (t1.tv_sec - t0.tv_sec) << " seconds and " << (t1.tv_usec - t0.tv_usec) << " microseconds" << endl;

	cout << "MinCost_tabulation[2][3] ie. " << Cost[2][3] << " = "  << MinCost_tabulation(Cost, 2, 3) << endl;
	struct timeval t2; gettimeofday(&t2 , NULL);
	cout << "tabulation : " << (t2.tv_sec - t1.tv_sec) << " seconds and " << (t2.tv_usec - t1.tv_usec) << " microseconds" << endl;

	cout << "MinCost_memoization[2][3] ie. " << Cost[2][3] << " = "  << MinCost_memoization(Cost, 2, 3) << endl;
	struct timeval t3; gettimeofday(&t3 , NULL);
	cout << "memoization : " << (t3.tv_sec - t2.tv_sec) << " seconds and " << (t3.tv_usec - t2.tv_usec) << " microseconds" << endl;

	return 0;

}
