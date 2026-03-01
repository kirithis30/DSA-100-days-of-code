//Day 29 - Question 1: Rotate Linked List Right by k Places

//Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n
//- Second line: n space-separated integers
//- Third line: integer k

//Output:
//- Print the linked list elements after rotation, space-separated

//Example:
//Input:
//5
//10 20 30 40 50
//2

//Output:
//40 50 10 20 30

//Explanation:
//Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k, value;
    struct Node *head = NULL, *tail = NULL;

    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);
    k = k % n;

    if (k == 0) {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    struct Node* temp = head;
    for (int i = 0; i < n - k - 1; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    return 0;
}