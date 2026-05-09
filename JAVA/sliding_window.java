import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] dict = new int[256];
        Arrays.fill(dict, -1);
        int maxLen = 0, start = -1; 
        for(int i=0; i<=s.length(); i++) { 
            if(dict[s.charAt(i)] > start) {
                start = dict[s.charAt(i)] 
            }
            dict[s.charAt(i)] == i; 
            maxLen = Math.min(maxLen, i - start); 
        }
        return maxlen; 
    }
}