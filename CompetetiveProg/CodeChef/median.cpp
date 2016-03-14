#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class MedianFinder{
		public:
				priority_queue <float, std::vector<float>, std::less<float> > maxHeap;
				priority_queue <float, std::vector<float>, std::greater<float> >  minHeap;
				int size;

				MedianFinder(int N) : size(N){}

				void Insert(float a, int step);
				float Median();

};

template<typename T> void print_queue(T& q) {
		while(!q.empty()) {
				std::cout << q.top() << " ";
				q.pop();
		}
		std::cout << '\n';
}


void MedianFinder::Insert(float a, int step){
		/*
		   if(step == 10) {
		   print_queue(maxHeap);
		   print_queue(minHeap);
		   exit(0);
		   }
		 */
		if(maxHeap.empty()){
				//cout << "1 ";
				maxHeap.push(a);
				return;
		}

		/*
		   if(minHeap.empty()){
		   cout << "2 ";
		   minHeap.push(a);
		   return;
		   }
		 */

		if(a >= maxHeap.top()){
				//cout << "5 ";
				minHeap.push(a);
		} else {
				//cout << "6 ";
				maxHeap.push(a);
		}

		int diff = maxHeap.size() - minHeap.size();

		if(diff > 1){
				//cout << "maxmore (" << maxHeap.size() << " - " << minHeap.size() << " = " << diff << ") ";
				minHeap.push(maxHeap.top());
				maxHeap.pop();
		} else if(diff < -1){
				//cout << "minmore (" << minHeap.size() << " - " << maxHeap.size() << " = " << diff << ") ";
				maxHeap.push(minHeap.top());
				minHeap.pop();
		}

}

float MedianFinder::Median(){

		if(maxHeap.empty())
				return minHeap.top();
		if (minHeap.empty())
				return maxHeap.top();

		int diff = minHeap.size() - maxHeap.size();

		if(diff > 0)
				return minHeap.top();
		else if (diff < 0)
				return maxHeap.top();
		else
				return (maxHeap.top() + minHeap.top())/2;
}

int main() {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */   

		long N;
		cin >> N;

		MedianFinder mdn(N);

		while(N--){
				float a;
				cin >> a;
				//cout << a << " ";
				mdn.Insert(a, 15-N);
				//cout << mdn.Median() << endl;
				//printf("%ld | %.1f | \n",15-N, mdn.Median());
				printf("%.1f\n", mdn.Median());
				//cout << " | " << mdn.Median() << " | " << endl;
		}

		return 0;
}

