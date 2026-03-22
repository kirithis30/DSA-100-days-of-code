//Day 49 - Question 1: BST Insert

//Problem: BST Insert

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

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);

    return 0;
}