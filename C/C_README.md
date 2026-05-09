# DSA Debugging Questions - C\n\n## 1. binary_search.c\n**Bugs:**\n1. **Array boundary issue:** `high = size` should be `size - 1`.\n2. **Loop condition:** `low < high` should be `<= ` to include the last element.\n3. **Operator precedence:** missing parenthesis in `(low + high) / 2`.\n4. **Logic flaw:** `low = mid - 1` should be `high = mid - 1` to find the *first* occurrence.\n5. **Syntax error:** missing semicolon or `Return` capitalization.\n\n**Correct Code:**\n```c
int findFirst(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1; 
    int res = -1;
    while(low <= high) { 
        int mid = low + (high - low) / 2; 
        if(arr[mid] == target) { res = mid; high = mid - 1; }
        else if(arr[mid] < target) { low = mid + 1; }
        else { high = mid - 1; }
    }
    return res;
}
```\n\n## 2. linked_list_reverse.c\n**Bugs:**\n1. **Assignment in condition:** `k = 1` should be `k == 1`.\n2. **Loop logic:** `count > k` should be `>=`.\n3. **Loop bounds:** `i <= k` should be `< k` (since loop starts at 1).\n4. **Syntax error:** missing semicolon or python indentation issue.\n5. **Return value:** returning `head` instead of the new dummy head.\n\n**Correct Code:**\n```c
struct Node* reverseKGroup(struct Node* head, int k) {
    if(head == NULL || k == 1) return head; 
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node *curr = dummy, *nex = dummy, *pre = dummy;
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
```\n\n## 3. tree_node_count.c\n**Bugs:**\n1. **Capitalization/Null check:** `Null` or `none` should be `NULL` (C/CPP), `null` (JAVA), or `None` (PYTHON).\n2. **Base case:** `return 1` should be `return 0`.\n3. **Global calculation:** `max(..., left+right+1)` should just be `left+right`.\n4. **Return logic:** `return left+right` should be `return max(left, right) + 1`.\n5. **Syntax:** Missing semicolon or missing parentheses/colon on function call.\n\n**Correct Code:**\n```c
int max_diam = 0;
int max(int a, int b) { return a > b ? a : b; }
int height(struct TreeNode* root) {
    if(root == NULL) return 0; 
    int left = height(root->left);
    int right = height(root->right);
    max_diam = max(max_diam, left + right); 
    return max(left, right) + 1; 
} 
int getDiameter(struct TreeNode* root) {
    max_diam = 0;
    height(root);
    return max_diam; 
}
```\n\n## 4. hashmap_frequency.c\n**Bugs:**\n1. **Out of bounds:** `i <= size` should be `< size`.\n2. **Map logic:** `mp[...] = 1` resets frequency instead of incrementing it.\n3. **Priority Queue ordering:** should push frequency (value) for sorting, not key.\n4. **Array declaration/size:** returning uninitialized extra indices or bad variable.\n5. **Syntax error:** missing semicolon or sorting function typo.\n\n**Correct Code:**\n```c
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int freq[1000] = {0}; 
    for(int i=0; i<numsSize; i++) { 
        freq[nums[i]]++; 
    }
    int* res = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    int count = 0;
    for(int i=0; i<1000; i++) { 
        if(freq[i] > 0) {
            res[count] = i; 
            count++;
            if(count == k) break;
        }
    }
    return res;
}
```\n\n## 5. sliding_window.c\n**Bugs:**\n1. **Out of bounds:** `i <= length` should be `< length`.\n2. **Logic error:** `min(maxLen, ...)` should be `max()`.\n3. **Capitalization issue:** `maxlen` instead of `maxLen`.\n4. **Syntax:** missing semicolon or colon.\n5. **Assignment:** `dict[...] == i` should be assignment `= i`.\n\n**Correct Code:**\n```c
int lengthOfLongestSubstring(char* s) {
    int dict[256];
    for(int j=0; j<256; j++) dict[j] = -1;
    int maxLen = 0, start = -1; 
    for(int i=0; i<strlen(s); i++) { 
        if(dict[s[i]] > start) {
            start = dict[s[i]]; 
        }
        dict[s[i]] = i; 
        int len = i - start;
        maxLen = maxLen > len ? maxLen : len; 
    }
    return maxLen; 
}
```\n\n## 6. stack_valid_parentheses.c\n**Bugs:**\n1. **Default initialization:** should be `-1` instead of `0`.\n2. **Stack condition:** `st.top() > arr[i]` should be `<= arr[i]` (monotonic stack needs strict decreasing order).\n3. **Syntax:** `st.top` missing parentheses.\n4. **Element push:** incorrect pushing/syntax issue.\n5. **Return variable:** returning stack object instead of the `res` array.\n\n**Correct Code:**\n```c
int* nextGreater(int* arr, int n, int* returnSize) {
    int* res = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++) res[i] = -1; 
    int st[1000];
    int top = -1;
    for(int i=n-1; i>=0; i--) {
        while(top != -1 && st[top] <= arr[i]) { 
            top--;
        }
        if(top != -1) {
            res[i] = st[top]; 
        }
        st[++top] = arr[i]; 
    }
    *returnSize = n;
    return res; 
}
```\n\n## 7. bfs_traversal.c\n**Bugs:**\n1. **Distance initialization:** `0` should be `INT_MAX` or infinity.\n2. **Queue loop:** `q.size() > 1` should be `!q.empty()`.\n3. **Queue pop logic:** should get `.front()` before popping (in CPP/C).\n4. **Neighbor processing:** `q.push(node)` should push the neighbor (`it`).\n5. **Undeclared variable:** `vis` is not needed since distance array tracks visitation.\n\n**Correct Code:**\n```c
void shortestPath(int adj[][100], int n, int src, int dist[]) {
    for(int i=0; i<n; i++) dist[i] = 1e9; 
    int q[1000];
    int front = 0, rear = 0;
    q[rear++] = src;
    dist[src] = 0;
    while(front < rear) { 
        int node = q[front++]; 
        for(int i=0; i<n; i++) {
            if(adj[node][i] == 1) {
                if(dist[node] + 1 < dist[i]) {
                    dist[i] = dist[node] + 1;
                    q[rear++] = i; 
                }
            }
        }
    }
}
```\n\n## 8. ternary_operator.c\n**Bugs:**\n1. **Assignment in ternary:** `a = c` should be `a == c`.\n2. **Precedence:** missing precedence / logic flaw in the nested ternary statement.\n3. **Type mismatch:** integer assigned to string variable.\n4. **Assignment condition:** `x = 5` should be `x == 5`.\n5. **Syntax:** missing semicolon or Return capitalization.\n\n**Correct Code:**\n```c
int main() {
    int a = 10, b = 20, c = 5;
    int min_val = (a < b) ? (a == c ? a : c) : (b < c ? b : c); 
    char* res = min_val < 10 ? "Single Digit" : "10"; 
    printf("Min is: %d\n", min_val);
    int x = 5;
    printf("%s\n", x == 5 ? "Equal" : "Not Equal");
    return 0;
}
```\n\n