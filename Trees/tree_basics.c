#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* GetNewNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data)
{
    if (root == NULL) {
        return GetNewNode(data);
    }

    if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    printf("Insertion Complete for %d\n", data);
    return root;
}

bool Search(Node* root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    if (data < root->data)
        return Search(root->left, data);
    return Search(root->right, data);
}

void FreeTree(Node* root) {
    if (root == NULL) return;
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
}

int main()
{
    Node* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 60);
    root = Insert(root, 70);

    if (Search(root, 10)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    FreeTree(root);
    return 0;
}