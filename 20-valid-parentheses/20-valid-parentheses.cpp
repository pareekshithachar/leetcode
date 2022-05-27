class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length() == 1) return false;
        for(char c : s){
            if(c== '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.size() == 0) return false;
                if(st.top() == '(' && c ==')'){
                    st.pop();
                }else if(st.top() == '[' && c ==']'){
                    st.pop();
                }else if(st.top() == '{' && c =='}'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.size()) return false;
        return true;
    }
};