#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*add;
};struct node*start=NULL,*temp,*new1;
void create();
void push();
void pop();
void display();
void main()
{
    int choice;
    do
    {
        printf("\n--------------LINKED LIST MENU IN STACK-------------------");
        printf("\n1]create\n2]push\n3]pop\n4]display\n5]exit");
        printf("\nEnter choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 2:push();break;
            case 3:pop();break;
            case 4:display();break;
            case 1:create();break;
            default:printf("\nINVALID CHOICE");
        }

    }while(choice!=5);
}
void create()
{
    int n;
    char ch;
    printf("\nenter an element");
    scanf("%d",&n);
    start=(struct node*)(malloc(sizeof(struct node)));
    start->data=n;
    start->add=NULL;
    temp=start;
    printf("\nwant to continue");
    ch=getche();
    while(ch=='Y' || ch=='y')
    {
        printf("\nenter next element");
        scanf("%d",&n);

        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=n;
        new1->add=NULL;
        temp->add=NULL;
        temp->add=new1;
        temp=temp->add;
        printf("\nwant to continue");
        ch=getche();
    }

}
void display()
{
    if(start==NULL)
        printf("\nLL stack is empty");
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp=temp->add;
        }
    }
}
void push()
{
    int n;
    if(start==NULL)
        printf("\nList not exit");
    else
    {
        printf("\nenter an on fisrt position");
        scanf("%d",&n);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=n;
        new1->add=NULL;
        new1->add=start;
        start=new1;
    }
}
void pop()
{

    if(start==NULL)
        printf("\nLL not exit");
    else
    {

        temp=start;
        start=start->add;
        printf("\nDeleted element is %d",temp->data);
        free(temp);
    }
}
