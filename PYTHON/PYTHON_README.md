# DSA Debugging Questions - PYTHON

## 1. binary_search.py
**Bugs:**
1. **Array lower bound initialization:** `low = 1` should be `low = 0`.
2. **Loop condition:** `low < high` should be `<= ` to include the last element.
3. **Operator precedence/type:** `(low + high) / 2` should be `// 2` or `(low + high - low) / 2` without overflowing.
4. **Equality check:** `arr[mid] = target` is an assignment; it should be `==`.
5. **Logic flaw:** `high = mid + 1` should be `high = mid - 1` to search the left half.

**Correct Code:**
```python
def binary_search(arr, target):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```

## 2. sliding_window.py
**Bugs:**
1. **Initialization:** `window_sum = arr[i]` overrides the sum instead of accumulating `+=`.
2. **First loop range:** It loops `1` to `k` (or equivalent), missing the 0th element. It should be `0` to `k`.
3. **Array bounds:** The second loop goes out of bounds by doing `<= arr.size()` instead of `< arr.size()`.
4. **Window Subtraction:** `window_sum += arr[i] + arr[i-k]` should subtract the outgoing element `- arr[i-k]`.
5. **Max logic:** `min(maxSum, windowSum)` should be `max()` to find the maximum.

**Correct Code:**
```python
def max_sum_subarray(arr, k):
    if len(arr) < k:
        return -1
    window_sum = 0
    for i in range(k):
        window_sum += arr[i]
    max_sum = window_sum
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)
    return max_sum
```

## 3. hashmap_frequency.py
**Bugs:**
1. **Data Structure Type:** `freq` is initialized/declared as a List/Array instead of a Map/Dictionary.
2. **Iteration/Type:** Iterating indices vs values, leading to out of bounds or type mismatch.
3. **Increment logic:** `freq[num] = 1` resets the frequency instead of adding `+ 1`.
4. **Initialization logic:** `freq[num] = 0` sets it to 0 initially instead of 1.
5. **Array bounds:** Going to `<= len` causing an out-of-bounds exception in the loop.

**Correct Code:**
```python
def count_frequencies(arr):
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return freq
```

## 4. stack_valid_parentheses.py
**Bugs:**
1. **Data Structure Type:** `st` is initialized/declared as a Map/Queue instead of a Stack/List.
2. **Empty stack check:** If it encounters a closing bracket on an empty stack, it needs to check if it is empty (`if not st`) instead of `if st`.
3. **Peek/Pop logic:** Missing parentheses `st.peek` or not actually popping the element.
4. **Matching condition:** `top == '{'` should be `top != '{'` to detect a mismatch.
5. **Final check:** Returning `size > 0` instead of `size == 0` (stack should be empty at the end).

**Correct Code:**
```python
def is_valid(s):
    st = []
    for ch in s:
        if ch in '({[':
            st.append(ch)
        else:
            if not st:
                return False
            top = st.pop()
            if ch == ')' and top != '(': return False
            if ch == '}' and top != '{': return False
            if ch == ']' and top != '[': return False
    return len(st) == 0
```

## 5. bubble_sort.py
**Bugs:**
1. **Inner loop bounds:** Goes to `n - i` instead of `n - i - 1` causing an out-of-bounds error.
2. **Comparison operator:** `arr[j] < arr[j+1]` sorts in descending order, should be `>`.
3. **Swapping logic:** Reassigns values incorrectly instead of properly swapping using a temp variable or tuple unpacking.
4. **Return placement:** The `return` statement is inside the loop, causing it to exit prematurely.
5. **Indexing/Typo:** `arr[j+1] = arr[j+1]` instead of assigning to the correct swapped variable.

**Correct Code:**
```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
```

