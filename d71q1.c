//Day 71 - Question 1: Hash Table Using Quadratic Probing

//Problem Statement
//Implement a hash table using quadratic probing with formula:

//h(k, i) = (h(k) + i*i) % m

//Input Format
//Same as previous.

//Output Format
//Result of SEARCH operations.

//Sample Input
//7
//4
//INSERT 49
//INSERT 56
//SEARCH 49
//SEARCH 15

//Sample Output
//FOUND
//NOT FOUND

//Explanation
//Collisions resolved using i² jumps.

#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int table[m];
    for (int j = 0; j < m; j++) table[j] = 0;

    for (int j = 0; j < n; j++) {
        char op[10];
        int val;
        scanf("%s %d", op, &val);

        if (op[0] == 'I') {
            int i = 0;
            int h = val % m;
            int idx = (h + i * i) % m;
            
            while (table[idx] != 0) {
                i++;
                idx = (h + i * i) % m;
            }
            table[idx] = val;

        } else {
            int i = 0;
            int h = val % m;
            int idx = (h + i * i) % m;
            int found = 0;

            while (table[idx] != 0 && i < m) {
                if (table[idx] == val) {
                    found = 1;
                    break;
                }
                i++;
                idx = (h + i * i) % m;
            }

            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    return 0;
}