#include <iostream>
#include <vector>
using namespace std;
int findFirst(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size(); 
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