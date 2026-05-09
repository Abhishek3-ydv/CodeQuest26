# DSA Debugging Questions - CPP

## 1. binary_search.cpp
**Bugs:**
1. **Array boundary issue:** `high = size` should be `size - 1`.
2. **Loop condition:** `low < high` should be `<= ` to include the last element.
3. **Operator precedence:** missing parenthesis in `(low + high) / 2`.
4. **Logic flaw:** `low = mid - 1` should be `high = mid - 1` to find the *first* occurrence.
5. **Syntax error:** missing semicolon or `Return` capitalization.

**Correct Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;
int findFirst(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, res = -1;
    while(low <= high) { 
        int mid = low + (high - low) / 2; 
        if(arr[mid] == target) { res = mid; high = mid - 1; }
        else if(arr[mid] < target) { low = mid + 1; }
        else { high = mid - 1; }
    }
    return res;
}
```

## 2. linked_list_reverse.cpp
**Bugs:**
1. **Assignment in condition:** `k = 1` should be `k == 1`.
2. **Loop logic:** `count > k` should be `>=`.
3. **Loop bounds:** `i <= k` should be `< k` (since loop starts at 1).
4. **Syntax error:** missing semicolon or python indentation issue.
5. **Return value:** returning `head` instead of the new dummy head.

**Correct Code:**
```cpp
Node* reverseKGroup(Node* head, int k) {
    if(head == NULL || k == 1) return head; 
    Node* dummy = new Node(); dummy->next = head;
    Node *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    while(curr->next != NULL) { curr = curr->next; count++; }
    while(count >= k) { 
        curr = pre->next; nex = curr->next;
        for(int i=1; i<k; i++) { 
            curr->next = nex->next; nex->next = pre->next;
            pre->next = nex; nex = curr->next; 
        }
        pre = curr; count -= k;
    }
    return dummy->next; 
}
```

## 3. tree_node_count.cpp
**Bugs:**
1. **Capitalization:** `Null` or `none` should be `NULL`.
2. **Base case:** `return 1` should be `return 0`.
3. **Global calculation:** `max(..., left+right+1)` should just be `left+right`.
4. **Return logic:** `return left+right` should be `return max(left, right) + 1`.
5. **Syntax:** Missing semicolon or missing parentheses/colon on function call.

**Correct Code:**
*(Correct height calculation returning max depth, and updating global diameter without +1)*

## 4. hashmap_frequency.cpp
**Bugs:**
1. **Out of bounds:** `i <= size` should be `< size`.
2. **Map logic:** `mp[...] = 1` resets frequency instead of incrementing it.
3. **Priority Queue ordering:** should push frequency (value) for sorting, not key.
4. **Array declaration:** returning uninitialized extra indices.
5. **Syntax error:** missing semicolon or sorting function typo.

**Correct Code:**
*(Use proper frequency counting and Min/Max Heap based on frequency value)*

## 5. sliding_window.cpp
**Bugs:**
1. **Out of bounds:** `i <= length` should be `< length`.
2. **Logic error:** `min(maxLen, ...)` should be `max()`.
3. **Capitalization issue:** `maxlen` instead of `maxLen`.
4. **Syntax:** missing semicolon or colon.
5. **Assignment:** `dict[...] == i` should be assignment `= i`.

**Correct Code:**
*(Use max() for length update, properly handle array/string bounds)*

## 6. stack_valid_parentheses.cpp
**Bugs:**
1. **Default initialization:** should be `-1` instead of `0`.
2. **Stack condition:** `st.top() > arr[i]` should be `<= arr[i]` (monotonic stack needs strict decreasing order).
3. **Syntax:** `st.top` missing parentheses.
4. **Element push:** incorrect pushing/syntax issue.
5. **Return variable:** returning stack object instead of the `res` array.

**Correct Code:**
*(Initialize res to -1, pop while stack top <= current, then assign and push)*

## 7. bfs_traversal.cpp
**Bugs:**
1. **Distance initialization:** `0` should be `INT_MAX` or infinity.
2. **Queue loop:** `q.size() > 1` should be `!q.empty()`.
3. **Queue pop logic:** should get `.front()` before popping.
4. **Neighbor processing:** `q.push(node)` should push the neighbor (`it`).
5. **Undeclared variable:** `vis` is not needed since distance array tracks visitation.

**Correct Code:**
*(Initialize dist to infinity, push src, update neighbors by pushing correctly)*

## 8. ternary_operator.cpp
**Bugs:**
1. **Assignment in ternary:** `a = c` should be `a == c`.
2. **Precedence:** missing precedence / logic flaw in the nested ternary statement.
3. **Type mismatch:** integer assigned to string variable.
4. **Assignment condition:** `x = 5` should be `x == 5`.
5. **Syntax:** missing semicolon or Return capitalization.

**Correct Code:**
*(Use strict equality == everywhere, match datatypes correctly)*

