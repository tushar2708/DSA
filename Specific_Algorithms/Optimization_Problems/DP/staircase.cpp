



// There are n stairs, you can either take one step or you can take 2 steps. How mny possibe ways can be there, to reach the top



#include<iostream>

using namespace std;

long find_ways_rec(long steps)
{
	if (steps <= 1)
		return 1;

	return find_ways_rec(steps - 1) + find_ways_rec(steps - 2);

}

long array[100] = {0,};

long find_ways_dp(long steps)
{
	if(steps <= 1)
		return 1;

	if (array[steps])
		return array[steps];

	long answer = find_ways_dp(steps - 2) + find_ways_dp(steps - 1);	// Apart from memory, a small optimization here, calcuating smaler number first
	array[steps] = answer;
	return answer;

}

long find_ways_dp_for(long steps)
{
	long a, b, c = 0 ;
	a = b = 1;
	for(int i = 1; i<steps; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main(){

	long steps = 0;
	cout << "How Many Steps?" << endl;
	cin >> steps;
	//cout << "There are " << find_ways_rec(steps) << " ways to reach the top." << endl;
	//cout << "There are " << find_ways_dp(steps) << " ways to reach the top." << endl;
	cout << "There are " << find_ways_dp_for(steps) << " ways to reach the top." << endl;
}
