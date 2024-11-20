// Basic node creation and display

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * create(int n)
{
    node * head = NULL;
    node * temp = NULL;
    node * p = NULL;
    for(int i = 0; i < n; i++)
    {
        temp = (node *) malloc (sizeof(node));
        printf("Enter details for node: %d\n", (i + 1));
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if(head == NULL)
            head = temp;
        else
        {
            p = head;
            while(p->next != NULL)
                p = p->next;
            p->next = temp;
        }
        printf("Input Complete!\n");

    }
    return head;
}

void display(node * head)
{
    node * temp = head;
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{

    int n;
    node * HEAD = NULL;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    HEAD = create(n);
    display(HEAD);
    return 0;
}