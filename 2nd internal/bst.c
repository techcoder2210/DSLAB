#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
}

// Function to search for a node
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Helper function to find the minimum value node
Node* find_min(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
Node* delete_node(Node** root, int data) {
 if (*root == NULL) {
        printf("Node not found\n");  // Node not found
        return NULL;
    }
    if (data < (*root)->data) {
        (*root)->left = delete_node(&((*root)->left), data);
    } else if (data > (*root)->data) {
        (*root)->right = delete_node(&((*root)->right), data);
    } else {
        // Node found and now removing it
        // Node with only one child or no child
        if ((*root)->left == NULL) {
            Node* temp = (*root)->right;
            free(*root);
            *root = temp;  // Update the root pointer directly
            return *root;
        } else if ((*root)->right == NULL) {
            Node* temp = (*root)->left;
            free(*root);
            *root = temp;  // Update the root pointer directly
            return *root;
        }

        // Node with two children
        Node* temp = find_min((*root)->right);
        (*root)->data = temp->data;
        (*root)->right = delete_node(&((*root)->right), temp->data);
    }
    return *root;
}
// Function to display the binary tree (in-order traversal)
void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

// Function to free the entire tree
void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
int main() {
    Node *root = NULL;
    int choice, data;
    while (1) {
        printf("1.Insert node\n");
        printf("2.Search for node\n");
        printf("3.Delete node\n");
        printf("4.Display tree\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Insert Node: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Search Node: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Node found\n");
                } else {
                    printf("Node not found\n");
                }
                break;
            case 3:
                printf("Delete node: ");
                scanf("%d", &data);
                delete_node(&root, data);
                break;
            case 4:
                display(root);
                printf("\n");
                break;
            case 5:
                free_tree(root);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
