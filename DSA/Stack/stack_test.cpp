#include "stack.cpp"

// Driver program to test above functions
int main()
{
    Stack stack = Stack(100);
    //cout << " isFull : " << stack.isFull() << "\n";
 
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    stack.Push(60);

    stack.Print();
    
    printf("%d popped from stack\n", stack.Pop());

    stack.Print();

    printf("Top item is %d (Just peeking :P )\n", stack.Peek());

    stack.Print();

    return 0;
}
