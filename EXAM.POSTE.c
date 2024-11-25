#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x; // Store value in stack
    } else {
        printf("Stack Overflow\n");
        exit(1); // Exit if stack is full
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--]; // Return value and decrease top
    } else {
        printf("Stack Underflow\n");
        exit(1); // Exit if stack is empty
    }
}

int main() {
    char postfix[MAX];
    int i;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); ++i) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0'); // Convert char to int
        } else {
            int op2 = pop();
            int op1 = pop();
            switch (postfix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        push(op1 / op2);
                    } else {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(1);
            }
        }
    }
    
    printf("Result: %d\n", pop());
    return 0;
}
