#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * head;

node * getNewNode(int num)
{
    node * newnode = (node *) malloc (sizeof(node));
    newnode -> data = num;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}

void InsertAtHead(int num)
{
    node * newnode = getNewNode(num);
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void Insertion(int num, int p)
{
    node * newnode = getNewNode(num);
    node * temp2 = head;
    for(int i = 0; i < p-2; i++)
        temp2 = temp2->next;

    temp2->next = newnode;
    newnode->prev = temp2;
}

void display()
{
    node * temp = head;
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main()
{
    int s, p, num;
    do {
        printf("1. Insertion at head\n");
        printf("2. Insertion at nth position\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &s);
        switch (s)
        {
            case 1:
                printf("Enter the number to be inserted\n");
                scanf("%d", &num);
                InsertAtHead(num);
                break;
            case 2:
                printf("Enter the number and the position to be inserted\n");
                scanf("%d%d", &num, &p);
                Insertion(num, p);
                break;
            case 3:
                display();
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input!\n");
        }
    }while(s != 4);
    return 0;
}
