import java.util.*;
class Solution {
    public HashMap<Integer, Integer> countFrequencies(int[] arr) {
        ArrayList<Integer> freq = new ArrayList<>();
        for(int i=0; i<=arr.length; i++) {
            int num = arr[i];
            if(freq.containsKey(num)) {
                freq.put(num, 1);
            } else {
                freq.put(num, 0);
            }
        }
        return freq;
    }
}