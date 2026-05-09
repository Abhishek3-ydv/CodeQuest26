#include <stdio.h>
#include <stdlib.h>
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int freq[1000] = {0}; 
    for(int i=0; i<=numsSize; i++) { 
        freq[nums[i]] = 1; 
    }
    int* res = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    int count = 0;
    for(int i=0; i<1000; i++) { 
        if(freq[i] > 0) {
            res[count] = freq[i]; 
            count++;
            if(count == k) break;
        }
    }
    res[k] = 0 
    return res;
}