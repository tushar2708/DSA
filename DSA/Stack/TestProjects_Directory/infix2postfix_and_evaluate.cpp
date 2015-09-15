//#include "stack.cpp"
#include <cstring>
#include <math.h>
#include "../stack.cpp"

// A utility function to check if the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
 
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

int infix2postfix(char * infix, char * postfix)

{
	Stack<char> stack_c = Stack<char>(strlen(infix));
	int len = strlen(infix);
	int marker = 0;

	for(int i=0; i<len; i++){
	
		if (isOperand(infix[i]))		// If operand, directly put in postfix exp
			postfix[marker++] = infix[i];
		else if(infix[i] == '(')		// If "(", push it to stack
			stack_c.Push(infix[i]);
		else if(infix[i] == ')') {		
	// If ")", keep popping and adding operators from stack to postfix exp, until "("is found, finally remove that "(" from stack
			while(!stack_c.isEmpty() && stack_c.Peek() != '(')
				postfix[marker++] = stack_c.Pop();
			if(stack_c.isEmpty() && stack_c.Peek() != '(')
			{
				cout << "invalid expression" << endl;
				return -1;
			} else {
				stack_c.Pop();
			}
		} else {
	// It's an operator, keep "popping and adding to postfix" until the top of stack has precedence less than/equal to it. 
			while( !stack_c.isEmpty() && Prec(infix[i]) <= Prec(stack_c.Peek()) ){
				postfix[marker++] = stack_c.Pop();
			}
				stack_c.Push(infix[i]);

		}

	}

	while(!stack_c.isEmpty())
		postfix[marker++] = stack_c.Pop();

	postfix[marker] = '\0';

}

int evaluatePostfix(char * postfix){

	Stack<int> stack_i = Stack<int>(strlen(postfix));

	int len = strlen(postfix);

	for(int i=0; i<len; i++){
		if(isOperand(postfix[i])) {
			stack_i.Push(postfix[i] - '0');
			cout << "Pushed postfix[" << i << "] (" << postfix[i] << ") to stack" << endl;
		} else {
			int val1 = stack_i.Pop();
			int val2 = stack_i.Pop();
			int val3 = 0;
			switch(postfix[i]){

			case '+':
				val3 = val2 + val1;
				break;
                        case '-':
                                val3 = val2 - val1;
                                break;
                        case '*':
                                val3 = val2 * val1;
                                break;
                        case '/':
                                val3 = val2 / val1;
                                break;
                        case '^':
                                val3 = pow(val2,val1);
                                break;
			}
			cout << "Calculated " << val2 << postfix[i] << val1 << " as " << val3 << endl;
			stack_i.Push(val3);
		}
	}
	return stack_i.Pop();
}

// Driver program to test above functions
int main()
{
	char infix[100];
	char postfix[100];

	cout << "Enter the infix expression :" << endl;
	cin >> infix ;


	infix2postfix(infix, postfix);

	cout << "Postfix expression : " << postfix << endl;

	strcpy(postfix, "231*+9-");

	cout << "Which evaluates to : " << evaluatePostfix(postfix) << endl;

	return 0;

}
