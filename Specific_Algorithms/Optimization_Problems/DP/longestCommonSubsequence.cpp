

// Two given strings. Have to find the length of longest common subsequence (not necessarily continuous)


#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int LCS_rec(char * X, int m, char * Y, int n)
{
	if(m==0 || n ==0){
		return 0;
	}

	if(X[m] == Y[n]){
		return (1 + LCS_rec(X, m - 1, Y, n-1));
	} else {
		return max(LCS_rec(X, m, Y, n-1), LCS_rec(X, m-1, Y, n));
	}

}

int memo[1001][1001] ;


int LCS_memoization(char * X, int m, char * Y, int n)
{
	if(m==0 || n ==0){
		memo[m][n] = 0;
	//	cout << "1 : memo[" << m <<"][" << n << "] : " << memo[m][n] << endl ;
		return memo[m][n];
	}
	if(memo[m][n] !=-1) {
	//	cout << "2 : memo[" << m <<"][" << n << "] : " << memo[m][n] << endl ;
		return memo[m][n];
	} else
	{
		if(X[m] == Y[n]){
			memo[m][n] = (1 + LCS_memoization(X, m - 1, Y, n-1));
		} else {
			memo[m][n] = max( LCS_memoization(X, m, Y, n-1), LCS_memoization(X, m-1, Y, n) );
		}
	//	cout << "3 : memo[" << m <<"][" << n << "] : " << memo[m][n] << endl ;
		return memo[m][n];
	}

}


int LCS_tabulation ( char * X, int m, char * Y, int n )
{
	int L[m+1][n+1] ;	//L[i][j] -> Length of LCS of X[0 ... i-1] & Y[0 ... j-1]
	int i, j;

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0){
				L[i][j] = 0;
			} else if (X[i] == Y[j]){
				L[i][j] = L[i-1][j-1] + 1;
			} else {
				L[i][j] = max(L[i][j-1], L[i-1][j]);
			}
		}
	}

	return L[m][n];
}		/* -----  end of function LCS_tabulation  ----- */


int main() {

	char X[] = "AGGTABAGGTABAABCDEFGAGGDEFGAGGTABAGGTABAGTABAGGTABAABCDEFGAGGTABAGGTABAABCDEGTABAABCDEFGAGGTABA";
	char Y[] = "GXTXAYBGXTXAYAZBYCXDVGXXTXAYAZBYCXDVGXTXXAYBGXTXAYAZBYTXABYCXDVGXTXAYBGXTXAYAZBYCXDVGXTXAYBGXTX";

	int m = strlen(X);
	int n = strlen(Y);

	for(int i=0; i<=1001; i++){
		for(int j=0; j<=1001; j++){
			memo[i][j] = -1;
		}
	}

	clock_t t0 = (double) clock();

	cout << "CLOCKS_PER_SEC : " << CLOCKS_PER_SEC << endl;

	//cout << "Length of LCS = " << LCS_rec(X, m, Y, n) << endl;
	clock_t t1 = (clock());
	//cout << "recursion : " << (double) (t1 - t0) / CLOCKS_PER_SEC << endl;
	cout << "Length of LCS = " << LCS_tabulation(X, m, Y, n) << endl;
	clock_t t2 = (clock());
	cout << "tabulation : " << (double) (t2 - t1) / CLOCKS_PER_SEC << endl;
cout << "Length of LCS = " << LCS_memoization(X, m, Y, n) << endl;
        clock_t t3 = (clock());
	cout << "memoization : " << (double) (t3 - t2) / CLOCKS_PER_SEC << endl;

	return 0;

}
