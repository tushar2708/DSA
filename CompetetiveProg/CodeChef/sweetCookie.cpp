#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
		unsigned long N, K;

		cin >> N >> K;

		priority_queue <unsigned long, vector<unsigned long>, greater<unsigned long> > Q;

		unsigned long a;

		while(N--){
				cin >> a;
				Q.push(a);
		}

		unsigned long value1, value2, newValue;
		long long oper = 0;

		if(!Q.empty()){
				if(Q.top() > K){
						cout << oper << endl;
						return 0;
				}

				while(Q.top() < K){

						value1 = Q.top(); Q.pop();
						value2 = Q.top(); Q.pop();
						newValue = value1 + 2*value2;
						cout << oper << " : " << value1 << " " << value2 << " " << newValue << endl;
						oper++;
						Q.push(newValue);

						if(Q.size() == 1 && Q.top() < K){
								oper = -1;
								break;
						}
				}

				cout << oper << endl;

		}

		return 0;
}

