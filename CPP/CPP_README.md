# DSA Debugging Questions - CPP\n\n## 1. binary_search.cpp\n**Bugs:**\n1. **Array boundary issue:** `high = size` should be `size - 1`.\n2. **Loop condition:** `low < high` should be `<= ` to include the last element.\n3. **Operator precedence:** missing parenthesis in `(low + high) / 2`.\n4. **Logic flaw:** `low = mid - 1` should be `high = mid - 1` to find the *first* occurrence.\n5. **Syntax error:** missing semicolon or `Return` capitalization.\n\n**Correct Code:**\n```cpp
int findFirst(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1; 
    int res = -1;
    while(low <= high) { 
        int mid = low + (high - low) / 2; 
        if(arr[mid] == target) { res = mid; high = mid - 1; }
        else if(arr[mid] < target) { low = mid + 1; }
        else { high = mid - 1; }
    }
    return res;
}
```\n\n## 2. linked_list_reverse.cpp\n**Bugs:**\n1. **Assignment in condition:** `k = 1` should be `k == 1`.\n2. **Loop logic:** `count > k` should be `>=`.\n3. **Loop bounds:** `i <= k` should be `< k` (since loop starts at 1).\n4. **Syntax error:** missing semicolon or python indentation issue.\n5. **Return value:** returning `head` instead of the new dummy head.\n\n**Correct Code:**\n```cpp
Node* reverseKGroup(Node* head, int k) {
    if(head == NULL || k == 1) return head; 
    Node* dummy = new Node();
    dummy->next = head;
    Node *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    while(curr->next != NULL) { curr = curr->next; count++; }
    while(count >= k) { 
        curr = pre->next;
        nex = curr->next;
        for(int i=1; i<k; i++) { 
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next; 
        }
        pre = curr;
        count -= k;
    }
    return dummy->next; 
}
```\n\n## 3. tree_node_count.cpp\n**Bugs:**\n1. **Capitalization/Null check:** `Null` or `none` should be `NULL` (C/CPP), `null` (JAVA), or `None` (PYTHON).\n2. **Base case:** `return 1` should be `return 0`.\n3. **Global calculation:** `max(..., left+right+1)` should just be `left+right`.\n4. **Return logic:** `return left+right` should be `return max(left, right) + 1`.\n5. **Syntax:** Missing semicolon or missing parentheses/colon on function call.\n\n**Correct Code:**\n```cpp
int max_diam = 0;
int height(TreeNode* root) {
    if(root == NULL) return 0; 
    int left = height(root->left);
    int right = height(root->right);
    max_diam = max(max_diam, left + right); 
    return max(left, right) + 1; 
} 
int getDiameter(TreeNode* root) {
    max_diam = 0;
    height(root);
    return max_diam; 
}
```\n\n## 4. hashmap_frequency.cpp\n**Bugs:**\n1. **Out of bounds:** `i <= size` should be `< size`.\n2. **Map logic:** `mp[...] = 1` resets frequency instead of incrementing it.\n3. **Priority Queue ordering:** should push frequency (value) for sorting, not key.\n4. **Array declaration/size:** returning uninitialized extra indices or bad variable.\n5. **Syntax error:** missing semicolon or sorting function typo.\n\n**Correct Code:**\n```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++) { 
        mp[nums[i]]++; 
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto it : mp) {
        pq.push({it.second, it.first}); 
        if(pq.size() > k) {
            pq.pop();
        }
    }
    vector<int> res; 
    while(!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop(); 
    }
    return res;
}
```\n\n## 5. sliding_window.cpp\n**Bugs:**\n1. **Out of bounds:** `i <= length` should be `< length`.\n2. **Logic error:** `min(maxLen, ...)` should be `max()`.\n3. **Capitalization issue:** `maxlen` instead of `maxLen`.\n4. **Syntax:** missing semicolon or colon.\n5. **Assignment:** `dict[...] == i` should be assignment `= i`.\n\n**Correct Code:**\n```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1; 
    for(int i=0; i<s.length(); i++) { 
        if(dict[s[i]] > start) {
            start = dict[s[i]]; 
        }
        dict[s[i]] = i; 
        maxLen = max(maxLen, i - start); 
    }
    return maxLen; 
}
```\n\n## 6. stack_valid_parentheses.cpp\n**Bugs:**\n1. **Default initialization:** should be `-1` instead of `0`.\n2. **Stack condition:** `st.top() > arr[i]` should be `<= arr[i]` (monotonic stack needs strict decreasing order).\n3. **Syntax:** `st.top` missing parentheses.\n4. **Element push:** incorrect pushing/syntax issue.\n5. **Return variable:** returning stack object instead of the `res` array.\n\n**Correct Code:**\n```cpp
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1); 
    stack<int> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && st.top() <= arr[i]) { 
            st.pop();
        }
        if(!st.empty()) {
            res[i] = st.top(); 
        }
        st.push(arr[i]); 
    }
    return res; 
}
```\n\n## 7. bfs_traversal.cpp\n**Bugs:**\n1. **Distance initialization:** `0` should be `INT_MAX` or infinity.\n2. **Queue loop:** `q.size() > 1` should be `!q.empty()`.\n3. **Queue pop logic:** should get `.front()` before popping (in CPP/C).\n4. **Neighbor processing:** `q.push(node)` should push the neighbor (`it`).\n5. **Undeclared variable:** `vis` is not needed since distance array tracks visitation.\n\n**Correct Code:**\n```cpp
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, 1e9); 
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) { 
        int node = q.front(); q.pop(); 
        for(auto it : adj[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it); 
            }
        }
    }
    return dist;
}
```\n\n## 8. ternary_operator.cpp\n**Bugs:**\n1. **Assignment in ternary:** `a = c` should be `a == c`.\n2. **Precedence:** missing precedence / logic flaw in the nested ternary statement.\n3. **Type mismatch:** integer assigned to string variable.\n4. **Assignment condition:** `x = 5` should be `x == 5`.\n5. **Syntax:** missing semicolon or Return capitalization.\n\n**Correct Code:**\n```cpp
int main() {
    int a = 10, b = 20, c = 5;
    int min_val = (a < b) ? (a == c ? a : c) : (b < c ? b : c); 
    string res = min_val < 10 ? "Single Digit" : "10"; 
    cout << "Min is: " << min_val << endl;
    int x = 5;
    cout << (x == 5 ? "Equal" : "Not Equal") << endl;
    return 0;
}
```\n\n