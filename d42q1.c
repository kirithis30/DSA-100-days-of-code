//Day 42 - Question 1: Reverse a Queue Using Stack

//Problem Statement:
//Given a queue of integers, reverse the queue using a stack.

//Input Format:
//- First line contains integer N
//- Second line contains N space-separated integers

//Output Format:
//- Print the reversed queue

//Example:
//Input:
//5
//10 20 30 40 50

//Output:
//50 40 30 20 10

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front, rear;
};

struct Stack {
    int items[MAX];
    int top;
};

void enqueue(struct Queue* q, int value) {
    q->items[++(q->rear)] = value;
}

int dequeue(struct Queue* q) {
    return q->items[(q->front)++];
}

void push(struct Stack* s, int value) {
    s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {
    return s->items[(s->top)--];
}

int main() {
    int n, val;
    struct Queue q;
    struct Stack s;
    
    q.front = 0;
    q.rear = -1;
    s.top = -1;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    while (q.front <= q.rear) {
        push(&s, dequeue(&q));
    }

    while (s.top != -1) {
        enqueue(&q, pop(&s));
    }

    for (int i = q.front; i <= q.rear; i++) {
        printf("%d%s", q.items[i], (i == q.rear ? "" : " "));
    }

    return 0;
}