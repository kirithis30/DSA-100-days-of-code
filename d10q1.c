//Day 10 - Question 1: Check Palindrome

//Problem: Read a string and check if it is a palindrome using two-pointer comparison.

//Input:
//- Single line: string s

//Output:
//- Print YES if palindrome, otherwise NO

//Example:
//Input:
//level

//Output:
//YES

//Explanation: String reads same forwards and backwards

#include <stdio.h>

int main() {
    char s[1000];
    int length = 0;
    int isPalindrome = 1; 


    scanf("%s", s);

    
    while (s[length] != '\0') {
        length++;
    }

    
    int left = 0;
    int right = length - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0; 
            break;
        }
        left++;  
        right--; 
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}