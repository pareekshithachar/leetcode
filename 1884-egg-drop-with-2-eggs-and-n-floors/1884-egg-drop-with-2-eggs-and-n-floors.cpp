class Solution {
public:
    
    int solve(int n, int e,vector<int>&dp){
        if(e==1) return n;
        if(n==1 || n==0) return n;
        int ans = INT_MAX;
        if(dp[n] != -1) return dp[n];
        for(int k=1;k<=n;k++){
            int temp = 1+ max(solve(k-1,e-1,dp),solve(n-k,e,dp));
            ans = min(ans, temp);
        }
        return dp[n] = ans;
    }
    int twoEggDrop(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,2,dp);
    }
};