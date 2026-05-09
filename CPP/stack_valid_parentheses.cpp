#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, 0); 
    stack<int> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && st.top() > arr[i]) { 
            st.pop();
        }
        if(!st.empty()) {
            res[i] = st.top; 
        }
        st.push(arr[i]); 
    }
    return st; 
}