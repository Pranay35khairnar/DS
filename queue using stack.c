#include <stdio.h>
#define SIZE 5

int stk1[SIZE], stk2[SIZE];
int top1 = -1, top2 = -1;

void push1(int data) {
    if (top1 == SIZE - 1) {
        printf("\nStack 1 is overflow");
    } else {
        top1++;
        stk1[top1] = data;
    }
}

int pop1() {
    if (top1 == -1) {
        printf("\nStack 1 is empty");
        return -1;
    } else {
        return stk1[top1--];
    }
}

void push2(int x) {
    if (top2 == SIZE - 1) {
        printf("\nStack 2 is full");
    } else {
        top2++;
        stk2[top2] = x;
    }
}

int pop2() {
    if (top2 == -1) {
        printf("\nStack 2 is empty");
        return -1;
    }
    return stk2[top2--];
}

void enqueue(int x) {
    if (top1 + top2 + 1 < SIZE) { // Check if queue is full
        push1(x);
    } else {
        printf("\nQueue is full\n");
    }
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }                                        
    }
    
    int b = pop2();
    if (b != -1) {
        printf("\nThe dequeued element is %d", b);
    }
}

void display() {
    if (top1 == -1 && top2 == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    
    // Display elements in stack 2 (which is the front of the queue)
    for(int i = top2; i >= 0; i--) {
        printf("%d ", stk2[i]);
    }
    
    // Display elements in stack 1 (which is the back of the queue)
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stk1[i]);
    }
    
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
