//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int dp[21][21][21];
int solve(string &a, string &b, string &c, int i, int j, int k){
    if(i >= a.size() || j>=b.size() || k >=c.size()) return 0;
    int ans =0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(a[i] == b[j] && b[j] == c[k]){
        ans = 1 + solve(a,b,c,i+1,j+1,k+1);
    }
    
    int opt1 = solve(a,b,c,i+1,j,k);
    int opt2 = solve(a,b,c,i,j+1,k);
    int opt3 = solve(a,b,c,i,j,k+1);
    
    int opt4 = solve(a,b,c,i+1,j+1,k);
    int opt5 = solve(a,b,c,i+1,j,k+1);
    
    int opt6 = solve(a,b,c,i,j+1,k+1);
    
    return dp[i][j][k] = max({ans,opt1,opt2,opt3,opt4,opt5,opt6});
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp,-1,sizeof(dp));
    return solve(A,B,C,0,0,0);
}