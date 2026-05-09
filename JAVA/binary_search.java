class Solution {
    public int binarySearch(int[] arr, int target) {
        int low = 1;
        int high = arr.length - 1;
        while(low < high) {
            int mid = low + high / 2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid + 1;
        }
        return -1;
    }
}