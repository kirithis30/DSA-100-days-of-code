//Day 39 - Question 1: Min Heap Implementation

//Problem Statement:
//Implement a Min Heap using an array where the smallest element is always at the root.

//Supported Operations:
//- insert x
//- extractMin
//- peek

//Input Format:
//- First line contains integer N
//- Next N lines contain heap operations

//Output Format:
//- Print results of extractMin and peek
//- Print -1 if operation cannot be performed

//Example:
//Input:
//6
//insert 40
//insert 10
//insert 30
//peek
//extractMin
//peek

//Output:
//10
//10
//30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[10000];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    heap[size] = x;
    int current = size;
    size++;

    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
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
        } else if (strcmp(op, "peek") == 0) {
            peek();
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        }
    }

    return 0;
}