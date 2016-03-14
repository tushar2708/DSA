#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph{
		private:
				int V;
				list<int> * adj;    //List of pointers.
				vector<bool> visited;
				vector<int> distance;

		public:
				Graph(int v):V(v){
						//cout << "constructor";
						adj = new list<int>[V+1];
						distance = vector<int>(V+1,-1);
						visited = vector<bool>(V+1,false);
				}

				~Graph(){
						//cout << "destructor";
						adj->clear();
						//delete adj ;
						distance.clear();
						//delete distance;
						visited.clear();
						//delete visited;
				}

				void addEdge(int v, int w);
				void BFS(int s);

};

void Graph::addEdge(int v, int w){
		adj[v].push_back(w);
}

void Graph::BFS(int s){
		deque<int> Q;

		visited[s] = true;
		distance[s] = 0;
		Q.push_back(s);

		int prev = s;
		int curr;
		while( !Q.empty() ){
				curr = Q.front();
				Q.pop_front();

				for(auto i=adj[curr].begin(); i !=adj[curr].end(); ++i){
						if(!visited[*i]){
								visited[*i] = true;
								distance[*i] = distance[curr] + 6;
								//cout << distance[*i] << " ";
								Q.push_back(curr);
						}
				}
		}

		for(int i=1; i<distance.size() ; i++){
				if(i!=s)
						cout << distance[i] << " ";
		}

		cout << endl;

}

int main() {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */   

		int T;
		int N, M;
		int S;

		cin >> T;

		while(T--){
				cin >> N >> M;

				Graph graph(N);


				while(M--){
						int p1, p2;
						cin >> p1 >> p2 ;
						graph.addEdge(p1,p2);
						//graph.addEdge(p2,p1);
				}

				cin >> S;

				graph.BFS(S);

		}
		return 0;
}

