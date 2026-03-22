//Day 48 - Question 1: Count Leaf Nodes

//Problem: Count Leaf Nodes

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

int countLeafNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    printf("%d\n", countLeafNodes(root));

    return 0;
}