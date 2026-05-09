#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char* s) {
    int dict[256];
    for(int j=0; j<256; j++) dict[j] = -1;
    int maxLen = 0, start = -1; 
    for(int i=0; i<=strlen(s); i++) { 
        if(dict[s[i]] > start) {
            start = dict[s[i]] 
        }
        dict[s[i]] == i; 
        maxLen = (maxLen, i - start); 
    }
    return maxlen; 
}