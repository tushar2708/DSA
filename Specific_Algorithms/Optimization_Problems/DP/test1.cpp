#include <iostream>
#include <vector>

using namespace std;


int main() {
		//code
		int T;
		cin >> T;
		while(T--){
				int m, n;
				cin >> m >> n;
				vector<char>str1;
				vector<char>str2;
				char a;
				for(int i=0; i<m; i++){
						cin >> a;
						str1.push_back(a);
				}

				/*
				   for(int i=0; i<n; i++){
				   cin >> a;
				   str2.push_back(a);
				   }

				   for(auto i : str2){
				   cout << i << " ";
				   }
				 */

		}
		return 0;
}
