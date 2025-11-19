#include <stdio.h>
#include <stdlib.h>

// Define the structure for the tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// In-order traversal function
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);   // Traverse left subtree
        printf("%d ", root->data);  // Visit root
        inOrder(root->right);  // Traverse right subtree
    }
}
git a
int main() {
    // Create the root and other nodes
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform in-order traversal
    printf("In-order Traversal: ");
    inOrder(root);

    return 0;
}
