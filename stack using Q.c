#include <stdio.h>
#define MAX_SIZE 5

int queue1[MAX_SIZE];
int queue2[MAX_SIZE];
int front1 = -1;
int rear1 = -1;
int front2 = -1;
int rear2 = -1;

void push(int x) 
{
    
    if (rear1 == MAX_SIZE - 1 && front1 == 0) 
	{
        printf("Stack is full\n");
        return;
    }
    
    
    if (front1 == -1) 
	{
        front1 = 0; 
    }
    
    
    queue1[++rear1] = x; 
}

int pop() 
{
    
    if (front1 == -1) 
	{
        printf("Stack is empty\n");
        return -1;
    }

    
    while (front1 < rear1) 
	{
        queue2[++rear2] = queue1[front1++];
    }
    
    
    int poppedValue = queue1[front1];

    
    front1 = rear1 = -1;

    
    front1 = 0;
    rear1 = -1;

    
    while (front2 <= rear2) {
        queue1[++rear1] = queue2[front2++];
    }

    
    front2 = rear2 = -1;

    return poppedValue;
}

int peek() {
    
    if (front1 == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    
    return queue1[rear1]; 
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
    return 0;
}
