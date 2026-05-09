# DSA Debugging Questions - JAVA

## 1. binary_search.java
**Bugs:**
1. **Array lower bound initialization:** `low = 1` should be `low = 0`.
2. **Loop condition:** `low < high` should be `<= ` to include the last element.
3. **Operator precedence/type:** `(low + high) / 2` should be `// 2` or `(low + high - low) / 2` without overflowing.
4. **Equality check:** `arr[mid] = target` is an assignment; it should be `==`.
5. **Logic flaw:** `high = mid + 1` should be `high = mid - 1` to search the left half.

**Correct Code:**
```java
class Solution {
    public int binarySearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
}
```

## 2. sliding_window.java
**Bugs:**
1. **Initialization:** `window_sum = arr[i]` overrides the sum instead of accumulating `+=`.
2. **First loop range:** It loops `1` to `k` (or equivalent), missing the 0th element. It should be `0` to `k`.
3. **Array bounds:** The second loop goes out of bounds by doing `<= arr.size()` instead of `< arr.size()`.
4. **Window Subtraction:** `window_sum += arr[i] + arr[i-k]` should subtract the outgoing element `- arr[i-k]`.
5. **Max logic:** `min(maxSum, windowSum)` should be `max()` to find the maximum.

**Correct Code:**
```java
class Solution {
    public int maxSumSubarray(int[] arr, int k) {
        if(arr.length < k) return -1;
        int windowSum = 0;
        for(int i=0; i<k; i++) {
            windowSum += arr[i];
        }
        int maxSum = windowSum;
        for(int i=k; i<arr.length; i++) {
            windowSum += arr[i] - arr[i-k];
            maxSum = Math.max(maxSum, windowSum);
        }
        return maxSum;
    }
}
```

## 3. hashmap_frequency.java
**Bugs:**
1. **Data Structure Type:** `freq` is initialized/declared as a List/Array instead of a Map/Dictionary.
2. **Iteration/Type:** Iterating indices vs values, leading to out of bounds or type mismatch.
3. **Increment logic:** `freq[num] = 1` resets the frequency instead of adding `+ 1`.
4. **Initialization logic:** `freq[num] = 0` sets it to 0 initially instead of 1.
5. **Array bounds:** Going to `<= len` causing an out-of-bounds exception in the loop.

**Correct Code:**
```java
import java.util.*;
class Solution {
    public HashMap<Integer, Integer> countFrequencies(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for(int i=0; i<arr.length; i++) {
            int num = arr[i];
            if(freq.containsKey(num)) {
                freq.put(num, freq.get(num) + 1);
            } else {
                freq.put(num, 1);
            }
        }
        return freq;
    }
}
```

## 4. stack_valid_parentheses.java
**Bugs:**
1. **Data Structure Type:** `st` is initialized/declared as a Map/Queue instead of a Stack/List.
2. **Empty stack check:** If it encounters a closing bracket on an empty stack, it needs to check if it is empty (`if not st`) instead of `if st`.
3. **Peek/Pop logic:** Missing parentheses `st.peek` or not actually popping the element.
4. **Matching condition:** `top == '{'` should be `top != '{'` to detect a mismatch.
5. **Final check:** Returning `size > 0` instead of `size == 0` (stack should be empty at the end).

**Correct Code:**
```java
import java.util.*;
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(char ch : s.toCharArray()) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.isEmpty()) return false;
                char top = st.pop();
                if(ch == ')' && top != '(') return false;
                if(ch == '}' && top != '{') return false;
                if(ch == ']' && top != '[') return false;
            }
        }
        return st.isEmpty();
    }
}
```

## 5. bubble_sort.java
**Bugs:**
1. **Inner loop bounds:** Goes to `n - i` instead of `n - i - 1` causing an out-of-bounds error.
2. **Comparison operator:** `arr[j] < arr[j+1]` sorts in descending order, should be `>`.
3. **Swapping logic:** Reassigns values incorrectly instead of properly swapping using a temp variable or tuple unpacking.
4. **Return placement:** The `return` statement is inside the loop, causing it to exit prematurely.
5. **Indexing/Typo:** `arr[j+1] = arr[j+1]` instead of assigning to the correct swapped variable.

**Correct Code:**
```java
class Solution {
    public void bubbleSort(int[] arr) {
        int n = arr.length;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}
```

