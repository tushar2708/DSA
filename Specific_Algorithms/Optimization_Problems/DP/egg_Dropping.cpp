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

int min_EggDrops_rec(int e, int f)
{
	int res;

	if( f == 1 || f == 0)
		return f;

	if( e == 1 )
		return f;

	int min = INT_MAX;

	for(int i = 1; i <= f ; i++){
			// Breaks			//Doesn't break
		res = max(min_EggDrops_rec(e-1, i-1), min_EggDrops_rec(e, f-i) );
		if(res < min)
			min = res;
	}

	return (1 + min);
}


int min_EggDrops_tabulation (int e, int f)
{
	int L[e+1][f+1] ;
	int res;

	for(int i=0; i<=e; i++)
	{
		L[i][0] = 0;
		L[i][1] = 1;
	}

	for(int j = 0; j<=f;j++)
	{
		L[0][j] = 0;
		L[1][j] = j;
	}

	for(int i =2; i <=e; i++){
	
		for(int j =2; j <=f; j++){
			L[i][j] = INT_MAX;
			for(int k =1; k<=j; k++){
				res = 1 + max (L[i-1][k-1], L[i][j-k]);
				if (res < L[i][j])
					L[i][j] = res;
			}
		}
	}

	return L[e][f];
}		// -----  end of function min_EggDrops_tabulation  ----- 



int main() {

	int e, f ;
	cout << "Enter the number of Floors :" << endl;
	cin >> f;

	cout << "Enter the number of eggs :" << endl;
	cin >> e;


	struct timeval t0; gettimeofday(&t0 , NULL);

	//cout << "Minimum Trials Required = " << min_EggDrops_rec(e, f) << endl;
	struct timeval t1; gettimeofday(&t1 , NULL);
	//cout << "recursion : " << (t1.tv_sec - t0.tv_sec) << " seconds and " << (t1.tv_usec - t0.tv_usec) << " microseconds" << endl;

	//cout << "Minimum Trials Required (Memoization) = "  << min_EggDrops_memoization(e, f) << endl;
	struct timeval t2; gettimeofday(&t2 , NULL);
	//cout << "memoization : " << (t2.tv_sec - t1.tv_sec) << " seconds and " << (t2.tv_usec - t1.tv_usec) << " microseconds" << endl;

	cout << "Minimum Trials Required (Tabulation) = "  << min_EggDrops_tabulation(e, f) << endl;
	struct timeval t3; gettimeofday(&t3 , NULL);
	cout << "tabulation : " << (t3.tv_sec - t2.tv_sec) << " seconds and " << (t3.tv_usec - t2.tv_usec) << " microseconds" << endl;
	return 0;

}
