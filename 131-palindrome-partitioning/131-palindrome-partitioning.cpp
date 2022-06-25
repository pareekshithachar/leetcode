class Solution {
public:
    vector<vector<string>>res;
    
    bool isPal(string s, int start, int end){
    while (start <= end){
        if (s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}
    void solve(vector<string>ans, string s, int i){
        if(i >= s.size()){
            res.push_back(ans);
            return;
        }
        for(int j=i;j<s.length();j++ ){
            if(isPal(s,i,j)){
                ans.push_back(s.substr(i,j+1-i));
                solve(ans,s,j+1);
                ans.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        solve({},s,0);
        return res;
    }
};