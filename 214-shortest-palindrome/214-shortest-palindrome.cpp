class Solution {
public:
    bool check(string s, int i, int j){
        for(;i<j;i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        
        return true;
    }
    string shortestPalindrome(string s) {
        vector<int>v(s.size()+1,0);
        for(int i=1;i<=s.size();i++){
            v[i] = v[i-1] + s[i-1]-'a';
        }
        string ans;
        for(int i=s.size();i>=0;i--){
            if((i%2==0 && v[i/2] == v[i] - v[i/2]) || (i%2==1 && v[i/2] == v[i] - v[i/2 +1])){
                if(check(s,0,i-1)){
                    ans = s.substr(i);
                    reverse(ans.begin(),ans.end());
                    break;
                }
            }
        }
        return ans+s;
    }
};