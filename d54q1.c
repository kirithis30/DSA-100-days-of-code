//Day 54 - Question 1: Zigzag Traversal

//Problem Statement:
//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 indicates NULL)

//Output Format:
//- Print traversal in zigzag order

//Example:
//Input:
//7
//1 2 3 4 5 6 7

//Output:
//1 3 2 4 5 6 7

//Explanation:
//Level 1 is printed left-to-right, level 2 right-to-left, and so on.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int n, int arr[]) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    return root;
}

void printZigzag(struct Node* root, int n) {
    if (!root) return;
    struct Node* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;
    bool leftToRight = true;

    while (head < tail) {
        int size = tail - head;
        int row[size];
        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[head++];
            int index = leftToRight ? i : (size - 1 - i);
            row[index] = curr->data;
            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
        for (int i = 0; i < size; i++) printf("%d ", row[i]);
        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(n, arr);
    printZigzag(root, n);
    return 0;
}