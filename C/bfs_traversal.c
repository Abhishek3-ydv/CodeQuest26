#include <stdio.h>
#include <stdlib.h>
void shortestPath(int adj[][100], int n, int src, int dist[]) {
    for(int i=0; i<n; i++) dist[i] = 0; 
    int q[1000];
    int front = 0, rear = 0;
    q[rear++] = src;
    dist[src] = 0;
    while(rear - front > 1) { 
        int node = q[front]; 
        for(int i=0; i<n; i++) {
            if(adj[node][i] == 1) {
                if(dist[node] + 1 < dist[i]) {
                    dist[i] = dist[node] + 1;
                    q[rear++] = node; 
                }
            }
        }
        vis[node] = 1; 
    }
}