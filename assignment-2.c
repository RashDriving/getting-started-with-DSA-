
#include <stdio.h>

int findFirstOccurrence(int prices[], int n, int target) {
    int left = 0, right = n - 1, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (prices[mid] == target) {
            result = mid; 
            right = mid - 1; 
        } else if (prices[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    
     int prices[] = {2,4,6,8,10,12,14,17};
    int target = 6;
    int n = sizeof(prices) / sizeof(prices[0]);
    
    int result = findFirstOccurrence(prices, n, target);
    printf("Output: %d\n", result);

    


    return 0;
}



