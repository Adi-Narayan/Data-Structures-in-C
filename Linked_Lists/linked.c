// Basic Linked List functions
// Assumes that the user doesn't input more than 1 value at the same position
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

struct node * head;

void InsertBeg(int num, int p)
{
    node *temp1 = (node *) malloc(sizeof(node));
    temp1->data = num;
    temp1->next = NULL;
    if (p == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    node *temp2 = head;
    for(int i = 0; i < p-2; i++)
        temp2 = temp2->next;
    temp1->next = temp2->next;
    temp2->next = temp1;

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

void Reverse() // Reversing the entire linked list (store info) or use recursion as follows(doesn't store, only display)
{
    node *prev, *current, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

/*
 * To Reverse without storing (only display)

 node * temp = head (at function call in main)
 void display(node * temp)
 {
    if(temp != NULL)
    {
        display(temp->next);
        printf("%d", temp->data);
    }
 }


 */

void Delete(int pos)
{
    node *temp1 = head;
    if(pos ==1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    for(int i = 0; i < pos-2; i++)
        temp1 = temp1 -> next;
    node * temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

int main()
{
    int s, p;
    do
    {
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &s);
        switch(s)
        {
            case 1:
                printf("Enter position of insertion\n");
                scanf("%d", &p);
                printf("Enter number to input\n");
                int num;
                scanf("%d", &num);
                InsertBeg(num, p);
                break;
            case 2:
                printf("Enter the position to be deleted\n");
                int pos;
                scanf("%d", &pos);
                Delete(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                Reverse();
                break;
            case 5:
                printf("Exiting...");
                break;
            default: printf("Invalid Input!\n");
        }

    }while(s != 5);
    return 0;
}
