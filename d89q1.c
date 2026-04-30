//Day 89 - Question 1: Allocate Minimum Pages

//Problem Statement
//Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

//Books must be allocated in contiguous order.

//Input Format
//n m
//n space-separated integers representing pages in books

//Output Format
//Print the minimum possible value of the maximum pages assigned to any student.

//Sample Input
//4 2
//12 34 67 90

//Sample Output
//113

//Explanation
//One optimal allocation is:
//Student 1: 12 + 34 + 67 = 113
//Student 2: 90
//Maximum pages = 113 (minimum possible).

#include <stdio.h>
#include <stdbool.h>

bool isPossible(int arr[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return false;

        if (currentSum + arr[i] > maxPages) {
            studentsRequired++;
            currentSum = arr[i];

            if (studentsRequired > m) {
                return false;
            }
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    if (m > n) return -1;

    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int low = maxVal, high = sum;
    int result = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findPages(arr, n, m));

    return 0;
}