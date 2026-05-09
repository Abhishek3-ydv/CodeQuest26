# DSA Debugging Questions - PYTHON\n\n## 1. binary_search.py\n**Bugs:**\n1. **Array boundary issue:** `high = size` should be `size - 1`.\n2. **Loop condition:** `low < high` should be `<= ` to include the last element.\n3. **Operator precedence:** missing parenthesis in `(low + high) / 2`.\n4. **Logic flaw:** `low = mid - 1` should be `high = mid - 1` to find the *first* occurrence.\n5. **Syntax error:** missing semicolon or `Return` capitalization.\n\n**Correct Code:**\n```python
def find_first(arr, target):
    low = 0
    high = len(arr) - 1 
    res = -1
    while low <= high: 
        mid = low + (high - low) // 2 
        if arr[mid] == target:
            res = mid
            high = mid - 1 
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return res
```\n\n## 2. linked_list_reverse.py\n**Bugs:**\n1. **Assignment in condition:** `k = 1` should be `k == 1`.\n2. **Loop logic:** `count > k` should be `>=`.\n3. **Loop bounds:** `i <= k` should be `< k` (since loop starts at 1).\n4. **Syntax error:** missing semicolon or python indentation issue.\n5. **Return value:** returning `head` instead of the new dummy head.\n\n**Correct Code:**\n```python
def reverse_k_group(head, k):
    if head is None or k == 1: 
        return head
    dummy = Node(0)
    dummy.next = head
    curr = dummy
    nex = dummy
    pre = dummy
    count = 0
    while curr.next is not None:
        curr = curr.next
        count += 1
    while count >= k: 
        curr = pre.next
        nex = curr.next
        for i in range(1, k): 
            curr.next = nex.next
            nex.next = pre.next
            pre.next = nex
            nex = curr.next 
        pre = curr
        count -= k
    return dummy.next
```\n\n## 3. tree_node_count.py\n**Bugs:**\n1. **Capitalization/Null check:** `Null` or `none` should be `NULL` (C/CPP), `null` (JAVA), or `None` (PYTHON).\n2. **Base case:** `return 1` should be `return 0`.\n3. **Global calculation:** `max(..., left+right+1)` should just be `left+right`.\n4. **Return logic:** `return left+right` should be `return max(left, right) + 1`.\n5. **Syntax:** Missing semicolon or missing parentheses/colon on function call.\n\n**Correct Code:**\n```python
class Solution:
    def __init__(self):
        self.max_diam = 0
    def height(self, root):
        if root is None: 
            return 0 
        left = self.height(root.left)
        right = self.height(root.right)
        self.max_diam = max(self.max_diam, left + right) 
        return max(left, right) + 1 
    def get_diameter(self, root): 
        self.max_diam = 0
        self.height(root)
        return self.max_diam
```\n\n## 4. hashmap_frequency.py\n**Bugs:**\n1. **Out of bounds:** `i <= size` should be `< size`.\n2. **Map logic:** `mp[...] = 1` resets frequency instead of incrementing it.\n3. **Priority Queue ordering:** should push frequency (value) for sorting, not key.\n4. **Array declaration/size:** returning uninitialized extra indices or bad variable.\n5. **Syntax error:** missing semicolon or sorting function typo.\n\n**Correct Code:**\n```python
import heapq
def top_k_frequent(nums, k):
    mp = {}
    for i in range(len(nums)): 
        mp[nums[i]] = mp.get(nums[i], 0) + 1 
    pq = []
    for key, val in mp.items():
        heapq.heappush(pq, (val, key)) 
        if len(pq) > k:
            heapq.heappop(pq)
    res = []
    while pq:
        res.append(heapq.heappop(pq)[1]) 
    return res
```\n\n## 5. sliding_window.py\n**Bugs:**\n1. **Out of bounds:** `i <= length` should be `< length`.\n2. **Logic error:** `min(maxLen, ...)` should be `max()`.\n3. **Capitalization issue:** `maxlen` instead of `maxLen`.\n4. **Syntax:** missing semicolon or colon.\n5. **Assignment:** `dict[...] == i` should be assignment `= i`.\n\n**Correct Code:**\n```python
def length_of_longest_substring(s):
    dict_map = {}
    max_len = 0
    start = -1 
    for i in range(len(s)): 
        char = s[i]
        if char in dict_map and dict_map[char] > start:
            start = dict_map[char] 
        dict_map[char] = i 
        max_len = max(max_len, i - start) 
    return max_len
```\n\n## 6. stack_valid_parentheses.py\n**Bugs:**\n1. **Default initialization:** should be `-1` instead of `0`.\n2. **Stack condition:** `st.top() > arr[i]` should be `<= arr[i]` (monotonic stack needs strict decreasing order).\n3. **Syntax:** `st.top` missing parentheses.\n4. **Element push:** incorrect pushing/syntax issue.\n5. **Return variable:** returning stack object instead of the `res` array.\n\n**Correct Code:**\n```python
def next_greater(arr):
    n = len(arr)
    res = [-1] * n 
    st = []
    for i in range(n-1, -1, -1):
        while st and st[-1] <= arr[i]: 
            st.pop()
        if st:
            res[i] = st[-1] 
        st.append(arr[i]) 
    return res
```\n\n## 7. bfs_traversal.py\n**Bugs:**\n1. **Distance initialization:** `0` should be `INT_MAX` or infinity.\n2. **Queue loop:** `q.size() > 1` should be `!q.empty()`.\n3. **Queue pop logic:** should get `.front()` before popping (in CPP/C).\n4. **Neighbor processing:** `q.push(node)` should push the neighbor (`it`).\n5. **Undeclared variable:** `vis` is not needed since distance array tracks visitation.\n\n**Correct Code:**\n```python
from collections import deque
def shortest_path(adj, src):
    n = len(adj)
    dist = [float('inf')] * n 
    q = deque()
    q.append(src)
    dist[src] = 0
    while q: 
        node = q.popleft() 
        for neighbor in adj[node]:
            if dist[node] + 1 < dist[neighbor]:
                dist[neighbor] = dist[node] + 1
                q.append(neighbor) 
    return dist
```\n\n## 8. ternary_operator.py\n**Bugs:**\n1. **Assignment in ternary:** `a = c` should be `a == c`.\n2. **Precedence:** missing precedence / logic flaw in the nested ternary statement.\n3. **Type mismatch:** integer assigned to string variable.\n4. **Assignment condition:** `x = 5` should be `x == 5`.\n5. **Syntax:** missing semicolon or Return capitalization.\n\n**Correct Code:**\n```python
def main():
    a, b, c = 10, 20, 5
    min_val = (a if a == c else c) if (a < b) else (b if b < c else c) 
    res = "Single Digit" if min_val < 10 else "10" 
    print(f"Min is: {min_val}")
    x = 5
    print("Equal" if x == 5 else "Not Equal") 
    return 0
```\n\n