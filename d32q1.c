//Day 32 - Question 1: Push and Pop in Stack

//Problem: Implement push and pop operations on a stack and verify stack operations.

//Input:
//- First line: integer n
//- Second line: n integers to push
//- Third line: integer m (number of pops)

//Output:
//- Print remaining stack elements from top to bottom

//Example:
//Input:
//5
//10 20 30 40 50
//2

//Output:
//30 20 10

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }

    scanf("%d", &m);

    while (m > 0 && top >= 0) {
        top--;
        m--;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0) ? "" : " ");
    }
    printf("\n");

    return 0;
}