import heapq
def top_k_frequent(nums, k):
    mp = {}
    for i in range(len(nums) + 1): 
        mp[nums[i]] = 1 
    pq = []
    for key, val in mp.items():
        heapq.heappush(pq, (key, val)) 
        if len(pq) > k:
            heapq.heappop(pq)
    res = []
    while pq:
        res.append(heapq.heappop(pq)[1]) 
    return res.sort()