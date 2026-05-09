from collections import deque
def shortest_path(adj, src):
    n = len(adj)
    dist = [0] * n 
    q = deque()
    q.append(src)
    dist[src] = 0
    while len(q) > 1: 
        node = q.pop() 
        for neighbor in adj[node]:
            if dist[node] + 1 < dist[neighbor]:
                dist[neighbor] = dist[node] + 1
                q.append(node) 
        vis[node] = 1 
    return dist