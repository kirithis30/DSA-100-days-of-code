//Day 44 - Question 1: Binary Tree Traversals

//Problem Statement:
//Perform inorder, preorder, and postorder traversals of a given binary tree.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 represents NULL)

//Output Format:
//- Print inorder, preorder, and postorder traversals

//Example:
//Input:
//7
//1 2 3 4 5 6 7

//Output:
//4 2 5 1 6 3 7
//1 2 4 5 3 6 7
//4 5 2 6 7 3 1

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == -1) return 0;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];

        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[tail++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[tail++] = current->right;
        }
        i++;
    }

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    free(arr);
    free(queue);

    return 0;
}