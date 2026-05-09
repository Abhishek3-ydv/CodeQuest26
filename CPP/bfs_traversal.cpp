#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, 0); 
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(q.size() > 1) { 
        int node = q.pop(); 
        for(auto it : adj[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(node); 
            }
        }
        vis[node] = 1; 
    }
    return dist;
}