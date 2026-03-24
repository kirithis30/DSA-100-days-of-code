//Day 52 - Question 1: LCA in Binary Tree

//Problem Statement:
//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 represents NULL)
//- Third line contains two node values

//Output Format:
//- Print the LCA value

//Example:
//Input:
//7
//1 2 3 4 5 6 7
//4 5

//Output:
//2

#include <stdio.h>
#include <stdlib.h>

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

struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n) {
        struct Node* temp = queue[head++];
        temp->left = newNode(arr[i++]);
        if (temp->left) queue[tail++] = temp->left;
        if (i < n) {
            temp->right = newNode(arr[i++]);
            if (temp->right) queue[tail++] = temp->right;
        }
    }
    free(queue);
    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, n1, n2);

    if (lca) printf("%d\n", lca->data);

    free(arr);
    return 0;
}