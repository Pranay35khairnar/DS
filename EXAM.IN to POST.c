#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) 
{
    int i = 0, j = 0;
    push('(');
    strcat(infix, ")");  // Make sure infix has enough space for this
    while (infix[i] != '\0') 
	{
        if (infix[i] == '(')
		{
            push(infix[i]);
        } 
		else if (isalnum(infix[i])) 
		{
            postfix[j++] = infix[i];
        } 
		else if (infix[i] == ')') 
		{
            while (stack[top] != '(') 
			{
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } 
		else 
		{
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i])) 
			{
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) 
	{
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}
int main() 
{
    char infix[MAX];
    char postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%49s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
