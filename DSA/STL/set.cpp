#include <iostream>
#include <set>
using namespace std;

int main() {
		// your code goes here
		set<int> s;
		for(int i : {1,2,3,4,5,6,7,8,9,10}){
				s.insert(i);
		}
		s.insert(3);
		for(auto i : s){
				cout << i << " ";
		}
		return 0;
}
