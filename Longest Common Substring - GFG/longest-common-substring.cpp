//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s, string k, int m, int n)
    {
        // your code here
        int len = 0;
        int row =0,col=0;
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(s[i-1] == k[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(len < dp[i][j]){
                        
                        len = dp[i][j];
                        row =i;
                        col =j;
                    }
                }
                else dp[i][j] = 0;
            }
        }
        string r ="";
        // cout<<row<<" ";
        int temp = len;
        while(len > 0){
            r = s[row-1]+r;
            row--;
            len--;
        }
        // cout<<r<<" ";
        return temp;
        // return solve(s,k,m-1,n-1,0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends