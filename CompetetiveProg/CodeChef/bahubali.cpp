/*                                                                                                                                                                      

https://www.codechef.com/problems/AMR15C

 */

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long int LL;

int main ()
{
		int t, N, k;

		cin >> t;
		while(t--){
				cin >> N;
				cin >> k;
				cout << N << " " << k << endl;
				if(k > N/2)
				{
						cout << "-1" << endl;
						continue;
				}
				if(!k)
				{
						cout << "-1" << endl;
						continue;
				}
		}
		return 0;
}
