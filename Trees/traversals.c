#include <stdio.h>
#include <stdlib.h>
// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Structure for queue node
struct QueueNode {
    struct Node* data;
    struct QueueNode* next;
};
// Structure for queue
struct Queue {
    struct QueueNode *front, *rear;
};
// Function to create a new tree node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
// Function to enqueue a tree node
void enqueue(struct Queue* queue, struct Node* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = node;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}
// Function to dequeue a tree node
struct Node* dequeue(struct Queue* queue) {
    if (queue->front == NULL) return NULL;
    struct QueueNode* temp = queue->front;
    struct Node* node = temp->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return node;
}
// Function for level order traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }

    free(queue);
}
// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int minValue(struct Node *pNode);

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;
    // If the value to be deleted is smaller than the root's value, then it lies in left subtree
    if (value < root->data)
        root->left = deleteNode(root->left, value);

// If the value to be deleted is greater than the root's value, then it lies in right subtree
    else if (value > root->data)
        root->right = deleteNode(root->right, value);

// if key is same as root's key, then this is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        root->data = minValue(root->right);

        // delete the inorder successor
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}


// Function to find the minimum value in a binary tree
int minValue(struct Node *root)
{
    int minv = root->data;
    while (root->left != NULL)
    {
        minv = root->left->data;
        root = root->left;
    }
    return minv;
}
// Function for inorder traversal
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Function for preorder traversal
void preorder(struct Node* root) {
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// Function for postorder traversal
void postorder(struct Node* root) {
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
// Function to print the tree structure
void printTree(struct Node* root, int level) {
    if (root == NULL)
        return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}
// Function to free the tree memory
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\n=== Binary Search Tree Operations ===\n");
        printf("1. Insert a number\n");
        printf("2. Delete a number\n");
        printf("3. Display Inorder\n");
        printf("4. Display Preorder\n");
        printf("5. Display Postorder\n");
        printf("6. Display Level Order\n");
        printf("7. Display Tree Structure\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Number inserted successfully!\n");
                break;

            case 2:
                printf("Enter the number to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Number deleted successfully!\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Level Order Traversal: ");
                levelOrder(root);
                printf("\n");
                break;

            case 7:
                printf("Tree Structure:\n");
                printTree(root, 0);
                break;

            case 8:
                printf("Exiting program...\n");
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}