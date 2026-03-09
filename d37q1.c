//Day 37 - Question 1: Priority Queue Using Array

//Problem Statement:
//Implement a Priority Queue using an array. An element with smaller value has higher priority.

//Supported Operations:
//- insert x
//- delete
//- peek

//Input Format:
//- First line contains integer N
//- Next N lines contain operations

//Output Format:
//- Print the deleted or peeked element
//- Print -1 if the queue is empty

//Example:
//Input:
//5
//insert 30
//insert 10
//insert 20
//delete
//peek

//Output:
//10
//20

#include <stdio.h>
#include <string.h>

#define MAX 1000

int queue[MAX];
int size = 0;

void insert(int x) {
    if (size < MAX) {
        queue[size++] = x;
    }
}

int findMinIndex() {
    if (size == 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (queue[i] < queue[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

void delete() {
    int idx = findMinIndex();
    if (idx == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", queue[idx]);
        for (int i = idx; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        size--;
    }
}

void peek() {
    int idx = findMinIndex();
    if (idx == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", queue[idx]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}