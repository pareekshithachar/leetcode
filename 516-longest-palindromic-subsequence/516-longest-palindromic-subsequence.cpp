class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        string k = s;
        reverse(k.begin(),k.end());
        int maxi=0;
        vector<vector<int>>dp(l+1,vector<int>(l+1));
        for(int i =0;i<=l;i++){
            for(int j =0;j<=l;j++){
                if(i==0 || j ==0) dp[i][j] =0;
                else if(s[i-1] == k[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                maxi= max(maxi,dp[i][j]);
            }
        }
        return  maxi;
        
    }
};
