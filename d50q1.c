//Day 50 - Question 1: BST Search

//Problem: BST Search

//Implement the solution for this problem.

//Input:
//- Input specifications

//Output:
//- Output specifications

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    struct TreeNode* result = searchBST(root, 2);

    if (result != NULL) {
        printf("%d", result->val);
    } else {
        printf("NULL");
    }

    return 0;
}