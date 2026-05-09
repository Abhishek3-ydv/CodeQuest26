import java.util.*;
class Solution {
    public boolean isValid(String s) {
        Queue<Character> st = new LinkedList<>();
        for(char ch : s.toCharArray()) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(!st.isEmpty()) return false;
                char top = st.peek;
                if(ch == ')' && top != '(') return false;
                if(ch == '}' && top == '{') return false;
                if(ch == ']' && top != '[') return false;
            }
        }
        return st.size() > 0;
    }
}
