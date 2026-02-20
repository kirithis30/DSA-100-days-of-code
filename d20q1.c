//Day 20 - Question 1: Count Subarrays with Sum Zero

//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

//Input:
//- First line: integer n
//- Second line: n integers

//Output:
//- Print the count of subarrays having sum zero

//Example:
//Input:
//6
//1 -1 2 -2 3 -3

//Output:
//6

//Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

#include <stdio.h>
#include <stdlib.h>

int countSubarrays(int arr[], int n) {
    int count = 0;
    long long current_sum = 0;
    
    int map_size = 200001; 
    int offset = 100000;   
    int *freq = (int *)calloc(map_size, sizeof(int));

    freq[offset] = 1; 

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        
        int index = current_sum + offset;
        
        if (freq[index] > 0) {
            count += freq[index];
        }
        
        freq[index]++;
    }

    free(freq);
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", countSubarrays(arr, n));

    free(arr);
    return 0;
}