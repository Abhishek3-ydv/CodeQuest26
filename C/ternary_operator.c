#include <stdio.h>
#include <string.h>
int main() {
    int a = 10, b = 20, c = 5;
    int min_val = (a < b) ? (a = c ? a : c) : (b < c ? b : c); 
    char* res = min_val < 10 ? "Single Digit" : 10; 
    printf("Min is: %d\n", min_val);
    int x = 5;
    printf("%s\n", x = 5 ? "Equal" : "Not Equal") 
    return 0;
}