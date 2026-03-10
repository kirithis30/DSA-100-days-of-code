//Day 38 - Question 1: Deque Operations

//Problem: Deque (Double-Ended Queue)

//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

//Common Operations:
//1. push_front(value): Insert an element at the front of the deque.
//2. push_back(value): Insert an element at the rear of the deque.
//3. pop_front(): Remove an element from the front of the deque.
//4. pop_back(): Remove an element from the rear of the deque.
//5. front(): Return the front element of the deque.
//6. back(): Return the rear element of the deque.
//7. empty(): Check whether the deque is empty.
//8. size(): Return the number of elements in the deque.

//Additional Operations:
//- clear(): Remove all elements from the deque.
//- erase(): Remove one or more elements from the deque.
//- swap(): Swap contents of two deques.
//- emplace_front(): Insert an element at the front without copying.
//- emplace_back(): Insert an element at the rear without copying.
//- resize(): Change the size of the deque.
//- assign(): Replace elements with new values.
//- reverse(): Reverse the order of elements.
//- sort(): Sort the elements in ascending order.

//Time Complexity:
//- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
//- clear, erase, resize, assign, reverse: O(n)
//- sort: O(n log n)

//Input:
//- Sequence of deque operations with values (if applicable)

//Output:
//- Results of operations such as front, back, size, or the final state of the deque after all operations

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
    int size;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

bool empty(struct Deque* dq) {
    return (dq->size == 0);
}

int size(struct Deque* dq) {
    return dq->size;
}

void push_front(struct Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (empty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

void push_back(struct Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (empty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

void pop_front(struct Deque* dq) {
    if (empty(dq)) return;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    dq->size--;
}

void pop_back(struct Deque* dq) {
    if (empty(dq)) return;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    dq->size--;
}

int front(struct Deque* dq) {
    if (empty(dq)) return -1;
    return dq->front->data;
}

int back(struct Deque* dq) {
    if (empty(dq)) return -1;
    return dq->rear->data;
}

void display(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Deque* dq = createDeque();

    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    push_front(dq, 1);

    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));
    printf("Size: %d\n", size(dq));

    
    pop_front(dq);
    pop_back(dq);

    printf("Final Deque: ");
    display(dq);

    return 0;
}