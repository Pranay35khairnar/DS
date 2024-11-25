#include <stdio.h>
#define MAXSIZE 4
int deq[MAXSIZE], rear = -1, front = -1;

void insertfront();
void deletefront();
void insertrear();
void deleterear();
void display();

int main() 
{
    int choice;
    printf("\n--------------------------DOUBLE ENDED QUEUE---------------------");
    printf("\n1] Insert Front \n2] Delete Front \n3] Insert Rear \n4] Delete Rear \n5] Display \n6] Exit");
    printf("\n-----------------------------------------------------------------");
    while (1) 
	{
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                insertfront();
                break;
            case 2:
                deletefront();
                break;
            case 3:
                insertrear();
                break;
            case 4:
                deleterear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting...");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    }
}

void insertrear()
{
    int n;
    if ((rear + 1) % MAXSIZE == front)
    {
        printf("\nDouble-Ended Queue is full.");
    } 
	else 
	{
        printf("\nEnter the element: ");
        scanf("%d", &n);
        if (front == -1 && rear == -1)
        {
            rear = 0;
            front = 0;
        } else
        {
            rear = (rear + 1) % MAXSIZE;
        }
        deq[rear] = n;
    }
}

void deletefront()
{
    int n;
    if (rear == -1 && front == -1)
    {
        printf("\nDouble-Ended Queue is empty.");
    } else {
        n = deq[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        } 
		else
        {
            front = (front + 1) % MAXSIZE;
        }
        printf("\nDeleted element is: %d", n);
    }
}

void display()
{
    int i;
    if (rear == -1 && front == -1)
    {
        printf("\nDouble-Ended Queue is empty.");
    } 
	else
    {
        printf("\nElements of the queue are: ");
        for (i = front; i != rear; i = (i + 1) % MAXSIZE)
        {
            printf("%d ", deq[i]);
        }
        printf("%d", deq[rear]);
    }
}

void insertfront()
{
    int n;
    if ((front - 1 + MAXSIZE) % MAXSIZE == rear)
    {
        printf("\nDouble-Ended Queue is full.");
    } 
	else
	 {
        printf("\nEnter the element: ");
        scanf("%d", &n);
        if (front == -1 && rear == -1)
        {
            rear = 0;
            front = 0;
        } else
        {
            front = (front - 1 + MAXSIZE) % MAXSIZE;
        }
        deq[front] = n;
    }
}

void deleterear()
{
    int n;
    if (front == -1 && rear == -1)
    {
        printf("DEQ is empty");
    } else
    {
        n = deq[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + MAXSIZE) % MAXSIZE;
        }
        printf("The deleted item: %d", n);
    }
}
