//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n, int arr[], int sum, int idx, vector<vector<int>>&dp){
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        if(idx >= n) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int include = solve(n,arr,sum-arr[idx],idx+1,dp);
        int exclude = solve(n,arr,sum,idx+1,dp);
        
        return dp[idx][sum] = include || exclude;
    }
    int solvetab(int n, int arr[], int sum){
        vector<vector<int>>dp(n+1, vector<int>(sum+1,0));
        vector<int>cur(sum+1,0);
        vector<int>next(sum+1,0);

    next[0] = 1;
            
        
        for(int i = n-1;i>=0;i--){
            for(int s = 1; s <= sum; s++){
                int include = 0;
                if(s-arr[i] >= 0) include = next[s-arr[i]];
                int exclude = next[s];
                
               cur[s] = include || exclude;    
            }
            next = cur;
        }
        return next[sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum =0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum % 2 != 0) return 0;
        sum/=2;
        
        vector<vector<int>>dp(N, vector<int>(sum+1,-1));
        return solvetab(N,arr, sum);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends