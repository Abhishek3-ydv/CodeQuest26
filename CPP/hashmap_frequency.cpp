#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(int i=0; i<=nums.size(); i++) { 
        mp[nums[i]] = 1; 
    }
    priority_queue<pair<int,int>> pq;
    for(auto it : mp) {
        pq.push({it.first, it.second}); 
        if(pq.size() > k) {
            pq.pop();
        }
    }
    vector<int> res(k); 
    while(!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop() 
    }
    return res;
}