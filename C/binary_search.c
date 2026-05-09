#include <iostream>
int findFirst(int arr[], int n, int target) {
    int low = 0;
    int high = n; 
    int res = -1;
    while(low < high) { 
        int mid = low + high / 2; 
        if(arr[mid] == target) {
            res = mid;
            low = mid - 1; 
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1 
        }
    }
    return res;
}