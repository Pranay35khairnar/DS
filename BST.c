#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *ladd;
    int data;
    struct node *radd;
};struct node *root = NULL;
void create(struct node *r, struct node *new1);
void inorder(struct node *r);
struct node* search(struct node *r, int key);
int maxKey(struct node *r);
int minKey(struct node *r);

void main() 
{
    int ch, n;
    char p;
    do {
        printf("\n#_-_-_-_-_-_-_-_-_-_-_-_-_-_-_BST MENU_-_-_-_-_-_-_-_-_-_-_-_-_-_-_#");
        printf("\n1] create\n2] display inorder (all elements in ascending order)");
        printf("\n3] max.key\n4] min.key\n5] search\n6] exit");
        printf("\n#_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_#");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) 
		{
            case 1:
                do 
				{
                    printf("\nEnter an element: ");
                    scanf("%d", &n);
                    struct node *new1 = (struct node *)(malloc(sizeof(struct node)));
                    new1->ladd = new1->radd = NULL;
                    new1->data = n;
                    
                    if (root == NULL) 
					{
                        root = new1;
                    } 
					else 
					{
                        create(root, new1);
                    }
                    
                    printf("\nWant to continue (y/n)? ");
                    scanf(" %c", &p);
                } while (p == 'y' || p == 'Y');
                break;

            case 2:
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                if (root != NULL) 
				{
                    printf("Max key: %d\n", maxKey(root));
                } else 
				{
                    printf("Tree is empty.\n");
                }
                break;

            case 4:
                if (root != NULL) 
				{
                    printf("Min key: %d\n", minKey(root));
                } else 
				{
                    printf("Tree is empty.\n");
                }
                break;

            case 5:
                printf("Enter key to search: ");
                scanf("%d", &n);
                if (search(root, n) != NULL) 
				{
                    printf("Key %d found in the tree.\n", n);
                } 
				else 
				{
                    printf("Key %d not found in the tree.\n", n);
                }
                break;
                default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (ch != 6);
    
    
}

void create(struct node *r, struct node *new1) 
{
    if (new1->data < r->data) 
	{
        if (r->ladd == NULL) 
		{
            r->ladd = new1;
        } else 
		{
            create(r->ladd, new1);
        }
    } else if (new1->data > r->data) 
	{
        if (r->radd == NULL) 
		{
            r->radd = new1;
        } 
		else 
		{
            create(r->radd, new1);
        }
    } 
	else 
	{
        printf("\nDuplicate element not allowed\n");
    }
}

void inorder(struct node *r) 
{
    if (r != NULL) 
	{
        inorder(r->ladd);
        printf("%5d", r->data);
        inorder(r->radd);
    }
}

struct node* search(struct node *r, int key) 
{
    if (r == NULL || r->data == key)
	{
        return r;
    }
    if (key < r->data) 
	{
        return search(r->ladd, key);
    }
    return search(r->radd, key);
}

int maxKey(struct node *r) 
{
    while (r->radd != NULL) 
	{
        r = r->radd;
    }
    return r->data;
}

int minKey(struct node *r) 
{
    while (r->ladd != NULL)
	{
        r = r->ladd;
    }
    return r->data;
}
