class Solution {
public:
    int solve(vector<int>&dp, string s,int idx){
        int n = s.length();
        if(idx == n){
            return 1;
            
        }
        if(dp[idx] != -1) return dp[idx];
        
        int single = 0;
        if(s[idx]!='0') single = solve(dp,s,idx + 1 );
        int duble = 0;
        
        if(idx + 1 < n){
            
            if(s[idx] -'0'==1 || (s[idx] -'0'== 2 && s[idx+1]-'0' <7)){
                duble = solve(dp,s,idx + 2 );
            }
        }
        return dp[idx] = single + duble;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(dp,s,0);
    }
};