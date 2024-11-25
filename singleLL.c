#include<stdio.h>
struct node
{
	int data;
	struct node*add;
};struct node*start=NULL,*temp,*new1,*prev,*next;
void create();
void insertfirst();
void display();
void insertmiddle();
void insertlast();
void deletefirst();
void deletemiddle();
void deletelast();
//void countnode();
void search();
void main()
{
	int choice;
	do
	{
		printf("\n------------LINKED LIST MENU--------------");
		printf("\n1] create\n2] insertfirst\n3] insertmiddle\n4] insertlast");
		printf("\n5] deletefirst\n6] deletemiddle\n7] deletelast");
		printf("\n8] display\n9] count\n10] search\n11]exit");
		printf("\nenter choice ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:create();break;
			case 2:insertfirst();break;
			case 3:insertmiddle();break;
			case 4:insertlast();break;
			case 5:deletefirst();break;
			case 6:deletemiddle();break;
			case 7:deletelast();break;
			case 8:display();break;
		//	case 9:countnode();break;
			case 10:search();break;
			default:printf("\ninvalid choice");break;
		}

	}while(choice!=11);
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
	printf("\nWANT TO CONTINUE");
	scanf(" %c",&ch);
	while(ch=='y' || ch=='Y')
	{
			printf("\nenter next element");
	        scanf("%d",&n);
	        new1=(struct node*)(malloc(sizeof(struct node)));
	        new1->data=n;
	        new1->add=NULL;
	        temp->add=NULL;
	        temp->add=new1;
	        temp=temp->add;
	        printf("\nWANT TO CONTINUE");
	        scanf(" %c",&ch);



	}
}
void display()
{
	if(start==NULL)
	printf("\nList not exit");
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("\t\n%d",temp->data);
			temp=temp->add;
		}
	}
}
insertfirst()
{
	int n;
	if(start==NULL)
	printf("\nList not exit");
	else
	{
		printf("\nenter new element LL on 1st");
		scanf("%d",&n);
		new1=(struct node*)(malloc(sizeof(struct node)));
		new1->data=n;
		new1->add=NULL;
		new1->add=start;
		start=new1;
	}
}
insertlast()
{
	int n;
	if(start==NULL)
	printf("\nList not exit");
	else
	{
		printf("enter new element in last");
		scanf("%d",&n);
		new1=(struct node*)(malloc(sizeof(struct node)));
		new1->data=n;
		new1->add=NULL;
		temp=start;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
		temp->add=new1;
	}

}
void insertmiddle()
{
int n,pos,i=1;
if(start==NULL)
printf("\nList not exit");
else
{
printf("\nenter element in middle of LL");
scanf("%d",&n);
new1=(struct node*)(malloc(sizeof(struct node)));
new1->data=n;
new1->add=NULL;
printf("Enter the position");
scanf("%d",&pos);
next=start;
while(i<pos)
    {
    	prev=next;
    	next=next->add;
    	i++;
	}
	prev->add=new1;
	new1->add=next;
}
}
deletefirst()
{
	if(start==NULL)
	printf("\nList not exit");
	else
	{
		temp=start;
		start=start->add;
		printf("\ndeleted node is %d",temp->data);
		free(temp);
	}
}
deletelast()
{
	if(start==NULL)
	printf("\nList not exit");
	else
	{
		temp=start;
		while(temp->add!=NULL)
		{
			prev=temp;
			temp=temp->add;
		}
		prev->add=NULL;
		printf("\nDeleted node is %d",temp->data);
		free(temp);
	}
}
void deletemiddle()
{
	int pos,i=1;
	if(start==NULL)
	printf("\nList not exit");
	else
	{
		printf("enter the position");
		scanf("%d",&pos);
		temp=start;
		while(i<pos)
		{
			prev=temp;
			temp=temp->add;
			i++;
		}
		next=temp->add;
		prev->add=next;
		printf("\ndeleted node is %d",temp->data);
		free(temp);
	}
}
/*void countnode()
{
	int count=0;
	temp=start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->add;
	}
	printf("\ntotal node is %d",count);
}*/
void search()
{
	int s,f=0;
	if(start==NULL)
	printf("\nList not exit");
	else
	{
		printf("\nenter an element for search:");
		scanf("%d",&s);
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data=s)
			{
				f=1;
				break;
			}
			temp=temp->add;
		}
		if(f=1)
		printf("\nsearching success");
		else
		printf("\nsearching not success");
	}
}
