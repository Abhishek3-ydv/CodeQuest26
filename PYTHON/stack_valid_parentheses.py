def next_greater(arr):
    n = len(arr)
    res = [0] * n 
    st = []
    for i in range(n-1, -1, -1):
        while st and st[-1] > arr[i]: 
            st.pop()
        if st:
            res[i] = st.peek() 
        st.append(arr[i]) 
    return st