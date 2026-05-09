import java.util.*;
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<=nums.length; i++) { 
            mp.put(nums[i], 1); 
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq = 
            new PriorityQueue<>((a, b) -> a.getKey() - b.getKey()); 
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            pq.add(entry);
            if(pq.size() > k) {
                pq.poll();
            }
        }
        int[] res = new int[k]; 
        int idx = 0;
        while(!pq.isEmpty()) {
            res[idx++] = pq.poll().getValue();
            idx++ 
        }
        return res;
    }
}