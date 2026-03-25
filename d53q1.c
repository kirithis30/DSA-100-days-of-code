//Day 53 - Question 1: Print Binary Tree Vertical Order

//Problem Statement:
//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

//Input Format:
//- First line contains integer N (number of nodes)
//- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

//Output Format:
//- Print nodes column by column from leftmost to rightmost vertical line

//Example:
//Input:
//7
//1 2 3 4 5 6 7

//Output:
//4
//2
//1 5 6
//3
//7

//Explanation:
//Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

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

void findMinMax(struct Node* node, int* min, int* max, int hd) {
    if (node == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

void printVerticalLine(struct Node* node, int line_no, int hd) {
    if (node == NULL) return;
    if (hd == line_no) printf("%d ", node->data);
    printVerticalLine(node->left, line_no, hd - 1);
    printVerticalLine(node->right, line_no, hd + 1);
}

struct Node* buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* temp = queue[front++];
        if (i < n) {
            temp->left = newNode(arr[i++]);
            if (temp->left) queue[rear++] = temp->left;
        }
        if (i < n) {
            temp->right = newNode(arr[i++]);
            if (temp->right) queue[rear++] = temp->right;
        }
    }
    free(queue);
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
    for (int line_no = min; line_no <= max; line_no++) {
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    free(arr);
    return 0;
}