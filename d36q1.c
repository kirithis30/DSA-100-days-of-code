//Day 36 - Question 1: Circular Queue Using Array

//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n (number of elements to enqueue)
//- Second line: n space-separated integers
//- Third line: integer m (number of dequeue operations)

//Output:
//- Print queue elements from front to rear after operations, space-separated

//Example:
//Input:
//5
//10 20 30 40 50
//2

//Output:
//30 40 50 10 20

//Explanation:
//Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        return; 
    } else if (front == -1) {
        front = rear = 0;
        items[rear] = value;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
        items[rear] = value;
    } else {
        rear++;
        items[rear] = value;
    }
}

void dequeue() {
    if (front == -1) {
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) return;
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", items[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", items[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", items[i]);
    }
}

int main() {
    int n, m, val;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}