class Solution {
public:
    int minimumLength(string s) {
        int l =0, r= s.size() -1;
        while(l<r){
            char x = s[l];
            if(s[l] != s[r]){
                break;
            }
            while(l<s.size() && s[l] == x ){
                l++;
            }
            while(r>=0 && s[r] == x ){
                r--;
            }
        }
        
        return r-l+1>=0? r-l+1:0;
    }
};