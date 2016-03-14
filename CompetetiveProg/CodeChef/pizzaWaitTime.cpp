#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Q_Item{
		public:
				unsigned long int arrivalTime;
				unsigned long int processTime;

				Q_Item(unsigned long int a, unsigned long int b) : arrivalTime(a), processTime(b) {}
};

class Compare_arrivalTime{
		public:
				bool operator() (Q_Item a, Q_Item b){
						return (a.arrivalTime > b.arrivalTime);
				}
};

class Compare_waitingTime{
		public:
				bool operator() (Q_Item a, Q_Item b){
						return (a.processTime > b.processTime);
				}
};

int main() {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */  
		int N, start, wait;

		priority_queue <Q_Item, std::vector<Q_Item>, Compare_arrivalTime > Q_arrival;
		priority_queue <Q_Item, std::vector<Q_Item>, Compare_waitingTime > Q_waiting;

		cin >> N;
		int cnt = N;
		while(cnt--){
				cin >> start >> wait;
				Q_arrival.push(Q_Item(start, wait));
		}

		Q_Item curr_Customer = Q_arrival.top();

		int totalWait = 0;

		while (!Q_arrival.empty() || !Q_waiting.empty()){
				if (Q_waiting.empty()){
						//cout << "1 : ";
						curr_Customer = Q_arrival.top();
						Q_arrival.pop();
				} else {
						//cout << "2 : ";
						curr_Customer = Q_waiting.top();
						Q_waiting.pop();
				}

				//cout << totalWait << " " << curr_Customer.processTime << " - " << curr_Customer.arrivalTime << endl;
				totalWait += (curr_Customer.processTime + totalWait - curr_Customer.arrivalTime) ;
				//cout << totalWait << endl;

				//cout << " *" << Q_arrival.top().arrivalTime << " " << totalWait << "* " << endl;
				while(Q_arrival.top().arrivalTime <= totalWait && !Q_arrival.empty()){
						//cout << " -3- ";
						Q_waiting.push(Q_arrival.top());
						//cout << "(" << Q_arrival.top().arrivalTime << ":" << Q_arrival.top().processTime << ")";
						Q_arrival.pop();
				}


		}

		cout << totalWait/N;

		return 0;
}

