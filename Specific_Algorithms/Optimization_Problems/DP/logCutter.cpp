



// Best = n stairs, you can either take one step or you can take 2 width. How mny possibe ways can be there, to reach the top



#include<iostream>

using namespace std;



int Best[500] = {0,};

int max (int a, int b){
	return a>b ? a : b;
}

int bestLog_dp(int width, int price[])
{
	int k = 0 ;
	for(int i = 1; i<=width; i++)
	{
		for(int j=1; j<=i; j++){
			Best[i] = max(Best[i], price[j] + Best[i-j]);
		}
	}
	return Best[width];
}

int main(){

	int width = 0;
	cout << "Width of the Log?" << endl;
	cin >> width;
	int Prices[width] = {0,};
	
	for(int i=1; i<=width; i++){
		cout << "Price of " << i << " inch log" << endl;
		cin >> Prices[i];
	}
	
	cout << "Best = " << bestLog_dp(width, Prices) << " is the maximum revenue that can be generated." << endl;

	return 0;
}
