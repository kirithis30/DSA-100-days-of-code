//Day 73 - Question 1: First Non-Repeating Character

//Problem Statement
//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

//Input Format
//A single string s.

//Output Format
//Print the first non-repeating character or '$' if none exists.

//Sample Input
//geeksforgeeks

//Sample Output
//f

//Explanation
//The character 'f' occurs only once in the string and appears before any other non-repeating character.

#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char *s) {
    int count[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100005];
    if (scanf("%s", s) == 1) {
        printf("%c\n", findFirstNonRepeating(s));
    }
    return 0;
}