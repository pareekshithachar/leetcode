//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(string &s1, string &s2, int idx1, int idx2, vector<vector<int>>&dp){
        if(idx1 >= s1.size() || idx2 >= s2.size()) return 0;
        
        int ans =0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]){
            ans = 1 + solve(s1,s2,idx1 +1,idx2 +1,dp);
            
        }else{
            ans = max(solve(s1,s2,idx1 +1,idx2,dp), solve(s1,s2,idx1,idx2+1,dp));
        }
        return dp[idx1][idx2]  = ans;
        
        
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(x,vector<int>(y,-1));
        return solve(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends