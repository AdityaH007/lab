#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}


void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;


    Node** queue = (Node**)malloc(sizeof(Node*) * 100);
    int front = 0;
    int rear = 0;


    queue[rear++] = root;

    while (front < rear) {
        Node* currentNode = queue[front++];
        printf("%d ", currentNode->data);

       
        if (currentNode->left != NULL)
            queue[rear++] = currentNode->left;

        
        if (currentNode->right != NULL)
            queue[rear++] = currentNode->right;
    }

    free(queue);
}


void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}


void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

int main() {
    Node* root = NULL;

    int data;
    printf("Enter root node value: ");
    scanf("%d", &data);
    root = insertNode(root, data);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert node\n");
        printf("2. Level-order traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Inorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int parentData, childData;
                char position;

                printf("Enter parent node value to check existence: ");
                scanf("%d", &parentData);
                printf("Enter child node value: ");
                scanf("%d", &childData);
                printf("Enter position (L/R): ");
                scanf(" %c", &position);

                Node* parentNode = searchNode(root, parentData);
                if (parentNode == NULL) {
                    printf("Parent node not found.\n");
                } else {
                    if (position == 'L' || position == 'l')
                        {parentNode->left = createNode(childData);
                        parentNode->right=0;}
                    else if (position == 'R' || position == 'r')
                        {parentNode->right = createNode(childData);
                        parentNode->left=0;}
                    else
                        printf("Invalid position.\n");
                }
                break;
            }
            case 2:
                printf("Level-order traversal: ");
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
