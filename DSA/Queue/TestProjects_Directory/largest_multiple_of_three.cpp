
#include "../queue.cpp"


int CompareAsc(const void * a, const void * b){

	if ( *(int*)a < *(int*)b ) return -1;
	if ( *(int*)a > *(int*)b ) return 1;
	return 0;

}

int CompareDesc(const void * a, const void * b){

        if ( *(int*)a > *(int*)b ) return -1;
        if ( *(int*)a < *(int*)b ) return 1;
        return 0;

}

int largest_Multiple_of_3(int * arr, int size)
{
	std::qsort(arr, size, sizeof(int), CompareAsc);

	Queue <int>q0 = Queue <int>(size);
	Queue <int>q1 = Queue <int>(size);
	Queue <int>q2 = Queue <int>(size);

	int sum = 0;

	for(int i =0; i<size; i++){
		if(arr[i]%3 == 0) q0.Enqueue(arr[i]);
		else if(arr[i]%3 == 1) q1.Enqueue(arr[i]);
		else q2.Enqueue(arr[i]);
		sum += arr[i];
	}

	cout << "Before Deletion : " << endl;

	q0.Print();
	q1.Print();
	q2.Print();

	if(sum%3 == 1) {
		if(!q1.isEmpty())
			q1.Dequeue();
		else {
			if(!q2.isEmpty()){
                        	q2.Dequeue();
			}
			else
				return 0;

			if(!q2.isEmpty()){
                                q2.Dequeue();
			}
                        else
                                return 0;
		}
	}

        if(sum%3 == 2) {
                if(!q2.isEmpty())
                        q2.Dequeue();
                else {
                        if(!q1.isEmpty()){
                                q1.Dequeue();
                        }
                        else
                                return 0;


                        if(!q1.isEmpty()){
                                q1.Dequeue();
                        }
                        else
                                return 0;
                }
        }

	cout << "After Deletion : " << endl;

        q0.Print();
        q1.Print();
        q2.Print();

	int aux[size];
	int top=0;

	while(!q0.isEmpty())
		aux[top++] = q0.Dequeue();

        while(!q1.isEmpty())
                aux[top++] = q1.Dequeue();

        while(!q2.isEmpty())
                aux[top++] = q2.Dequeue();

	std::qsort(aux, top, sizeof(int), CompareDesc);

	for(int i=0; i<top; i++)
		cout << aux[i];
	cout << endl;
}

int main()
{

	int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size = sizeof(array)/sizeof(int);
	cout << "Largest multiple of 3 is : " << endl;
	largest_Multiple_of_3(array, size);
	return 0;
}
