//Day 34 - Question 1: Evaluate Postfix Expression

//Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

//Input:
//- Postfix expression with operands and operators

//Output:
//- Print the integer result

//Example:
//Input:
//2 3 1 * + 9 -

//Output:
//-4

//Explanation:
//Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int main() {
    struct Node* stack = NULL;
    char exp[100];
    
    while (scanf("%s", exp) != EOF) {
        if (isdigit(exp[0]) || (exp[0] == '-' && isdigit(exp[1]))) {
            push(&stack, atoi(exp));
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            
            switch (exp[0]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }

    printf("%d\n", pop(&stack));
    return 0;
}