//Day 43 - Question 1: Binary Tree Construction (Level Order)

//Problem Statement:
//Construct a Binary Tree from the given level-order traversal.

//Input Format:
//- First line contains integer N
//- Second line contains N space-separated integers (-1 represents NULL)

//Output Format:
//- Print inorder traversal of the constructed tree

//Example:
//Input:
//7
//1 2 3 4 5 -1 6

//Output:
//4 2 5 1 3 6

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0 || arr[0] == -1) return 0;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];

        if (i < n) {
            if (arr[i] != -1) {
                current->left = newNode(arr[i]);
                queue[tail++] = current->left;
            }
            i++;
        }

        if (i < n) {
            if (arr[i] != -1) {
                current->right = newNode(arr[i]);
                queue[tail++] = current->right;
            }
            i++;
        }
    }

    printInorder(root);
    printf("\n");

    return 0;
}