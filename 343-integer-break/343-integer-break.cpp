
class Solution {
public:
    int find(int n,vector<int>&dp){
        if(n==1 || n==2)return 1;
        if(dp[n]!=-1)return dp[n];
        int maxa=INT_MIN;
        for(int i=1;i<n;i++){
            maxa=max(maxa,max(i*find(n-i,dp),i*(n-i)));
             
        }
        return dp[n]=maxa;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return find(n,dp);
    }
};