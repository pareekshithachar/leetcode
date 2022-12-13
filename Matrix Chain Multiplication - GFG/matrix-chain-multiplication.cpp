//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[] , int s, int e,vector<vector<int>>&dp){
        if(e == s){
            return 0;
        }
        
        if(dp[s][e] != -1) return dp[s][e];
        int ans = INT_MAX;
        for(int i=s;i<e;i++){
            int temp = arr[i]*arr[s-1]*arr[e];
            int left = solve(arr,s,i,dp);
            int right = solve(arr,i+1,e,dp);
            ans = min(ans, temp + left + right);
        }
        return dp[s][e] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return solve(arr, 1, N-1,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends