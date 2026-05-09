import java.util.*;
class Solution {
    public int[] shortestPath(ArrayList<ArrayList<Integer>> adj, int src) {
        int n = adj.size();
        int[] dist = new int[n];
        Arrays.fill(dist, 0); 
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        dist[src] = 0;
        while(q.size() > 1) { 
            int node = q.pop(); 
            for(int it : adj.get(node)) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.add(node); 
                }
            }
            vis[node] = 1; 
        }
        return dist;
    }
}