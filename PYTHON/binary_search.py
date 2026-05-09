def find_first(arr, target):
    low = 0
    high = len(arr) 
    res = -1
    while low < high: 
        mid = low + high // 2 
        if arr[mid] == target:
            res = mid
            low = mid - 1 
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    Return res