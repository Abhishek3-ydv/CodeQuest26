#include <stdio.h>
#include <stdlib.h>
int* nextGreater(int* arr, int n, int* returnSize) {
    int* res = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++) res[i] = 0; 
    int st[1000];
    int top = -1;
    for(int i=n-1; i>=0; i--) {
        while(top != -1 && st[top] > arr[i]) { 
            top--;
        }
        if(top != -1) {
            res[i] = st[top; 
        }
        st[++top] = arr[i]; 
    }
    *returnSize = n;
    return st; 
}