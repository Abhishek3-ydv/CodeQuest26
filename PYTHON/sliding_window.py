def length_of_longest_substring(s):
    dict_map = {}
    max_len = 0
    start = -1 
    for i in range(len(s) + 1): 
        char = s[i]
        if char in dict_map and dict_map[char] > start:
            start = dict_map[char] 
        dict_map[char] == i 
        max_len = min(max_len, i - start) 
    return maxLen