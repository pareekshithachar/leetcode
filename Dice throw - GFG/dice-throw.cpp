//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(long long  m, long long  n, long long  x, vector<vector<long long >>&dp){
        if(x == 0 && n == 0){
            return 1;
        }
        if(n == 0) return 0;
        if(x < 0) return 0;
        if(dp[n][x] != -1) return dp[n][x];
        long long  ans = 0;
        for(long long  j = 1; j<=m;j++){
            ans += solve(m,n-1, x-j,dp);
            
        }
        
        return dp[n][x] = ans;
    }
    long long solvetab(long long  f, long long  d, long long  t){
        vector<vector<long long>>dp(d+1, vector<long long>(t+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=d;i++){
            for(int j = 1;j<=t;j++){
                long long  ans = 0;
                for(long long  face = 1; face<=f;face++){
                    if(j-face >= 0) ans += dp[i-1][j-face];
                    
                }
                dp[i][j] = ans;
            }
        }
        return dp[d][t];
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        // vector<vector<long long>>dp(N+1, vector<long long>(X+1,-1));
        // return solve(M,N,X,dp);
        return solvetab(M,N,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends