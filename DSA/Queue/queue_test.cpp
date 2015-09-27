#define Array_Queue Queue

#include "queue.cpp"


// Driver program to test above functions
int main()
{

	Queue<int> queue_i = Queue<int>(10);

	try {
		for (int i : {1, 2, 3, 4, 5}) {
			queue_i.Enqueue(i);
			queue_i.Print();
		}

		cout << "queue_i front after enqueues: " << queue_i.Front() << endl;
		cout << "queue_i rear after enqueues : " << queue_i.Rear() << endl;

		while(!queue_i.isEmpty()) {
			cout << "Dequeued from Queue_i : " << queue_i.Dequeue() << endl;
			queue_i.Print();
		}

	} catch (E & e)
	{
		cout << "Queue Error : " << e.what() << endl;
	}


        Queue<string> queue_s = Queue<string>(10);

        try {
                for ( const char * s : {"one", "two", "three", "four", "five"}) {
                        queue_s.Enqueue(s);
			queue_s.Print();
                }

                cout << "queue_s front after dequeues : " << queue_s.Front() << endl;
		cout << "queue_s rear after dequeues : " << queue_s.Rear() << endl;

                while(!queue_s.isEmpty()) {
                        cout << "Dequeueped from Queue_s : " << queue_s.Dequeue() << endl;
			queue_s.Print();
                }
        } catch (E & e)
        {
                cout << "Queue Error : " << e.what() << endl;
        }

	return 0;

}
