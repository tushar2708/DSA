#include <iostream>
using namespace std;

//#include "UF.hpp"

#define TRUE  0
#define FALSE 1

class UF
{

	private:
	int * arr ;
	int N;

        public:
        UF(int n)
	{
		N = n;
		arr = new int[N];
		for(int i = 0; i<N; i++)
                {
                        arr[i] = i;
        	}
	};

        void Union (int p, int q)
	{
		int pid = arr[p];
		int qid = arr[q] 
			for(int i = 0; i<N; i++) 
			{
				if(arr[i] == pid)
				arr[i] = qid;
			}
	};


        int connected (int p, int q)
	{
		//return ( (arr[p] == arr[q]) ? TRUE : FALSE );
		return !(arr[p] == arr[q]);
	};

        //int find (int p);
        int count();

};

int main(){

return 0;

}
