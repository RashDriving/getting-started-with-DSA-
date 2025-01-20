#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void ClosestSum(int arr[], int n, int target) {
    int closestSum = INT_MAX;
    int num1 = 0, num2 = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int currentSum = arr[i] + arr[j];
            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    
    printf("The two numbers are: (%d, %d)\n", num1, num2);
}

int main() {
    int arr1[] = {1, 3, -1, 2, -4, 5, 7};
    int target1 = 6;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("For array 1:\n");
    findClosestSum(arr1, n1, target1);

    int arr2[] = {-3, -2, -5, 1, 8, 10};
    int target2 = 7;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("For array 2:\n");
    findClosestSum(arr2, n2, target2);

    int arr3[] = {0, 0, 0, 0, 0};
    int target3 = 5;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("For array 3:\n");
    findClosestSum(arr3, n3, target3);

    return 0;
}
