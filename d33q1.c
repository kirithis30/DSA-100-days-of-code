//Day 33 - Question 1: Infix to Postfix Conversion

//Problem: Convert an infix expression to postfix notation using stack.

//Input:
//- Single line: infix expression (operands are single characters)

//Output:
//- Print the postfix expression

//Example:
//Input:
//A+B*C

//Output:
//ABC*+

//Explanation:
//Operator precedence: * > +
//Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

int precedence(char symbol) {
    switch(symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, x;

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    if (scanf("%s", infix) == 1) {
        infixToPostfix(infix, postfix);
        printf("%s\n", postfix);
    }
    
    return 0;
}