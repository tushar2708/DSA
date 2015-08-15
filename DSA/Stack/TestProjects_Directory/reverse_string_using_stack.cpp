#include "../stack.cpp"

void reverseString(char * String){

	int i = 0;
	int size = strlen(String);
	Stack stack = Stack(size);
	
	for (i = 0; i < size; i++)
        	stack.Push(String[i]);

        for (i = 0; i < size; i++)
                String[i] = stack.Pop();
}

int main()
{

	char * String = new char[10];
	strcpy(String, "tushar");

	cout << "String before Reversal : " << String << "\n";
	
	reverseString(String);

	cout << "String after Reversal : " << String << "\n";

	return 0;
}


