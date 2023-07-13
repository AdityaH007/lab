/*
 * Program: BST Creation
 * Conditions:
 * 1) The number of elements in the right subtree is equal to the number of elements in the left subtree.
 * 2) The height of the tree is equal to the number of elements in the tree.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to count the number of nodes in a BST
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Function to calculate the height of a BST
int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to check if the given BST satisfies the conditions
int satisfiesConditions(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    int height = calculateHeight(root);
    if (leftCount == rightCount && height == leftCount) {
        return 1;
    }
    return 0;
}

// Function to traverse and print the BST (Inorder Traversal)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting elements into the BST
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 13);
    root = insertNode(root, 17);

    // Checking if the BST satisfies the conditions
    if (satisfiesConditions(root)) {
        printf("The BST satisfies the given conditions.\n");
    } else {
        printf("The BST does not satisfy the given conditions.\n");
    }

    // Printing the BST (Inorder Traversal)
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
