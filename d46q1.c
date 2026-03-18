//Day 46 - Question 1: Level Order Traversal

//Problem: Level Order Traversal

//Implement the solution for this problem.

//Input:
//- Input specifications

//Output:
//- Output specifications

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* tempNode = queue[front++];

        printf("%d ", tempNode->data);

        if (tempNode->left != NULL) {
            queue[rear++] = tempNode->left;
        }

        if (tempNode->right != NULL) {
            queue[rear++] = tempNode->right;
        }
    }
    free(queue);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printLevelOrder(root);

    return 0;
}