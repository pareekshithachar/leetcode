//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int solve(vector<int>&price, int idx, bool bought, int k,vector<vector<vector<int>>>&dp){
    if(idx >= price.size()){
        return 0;
    }
    if(k >= 2){
        return 0;
    }
    if(dp[idx][bought][k] != -1) return dp[idx][bought][k];
    int ans = INT_MIN;
    if(bought){
        ans = max(ans,price[idx] +solve(price, idx+1,0,k+1,dp));
        ans = max(ans, solve(price,idx+1,1,k,dp));
    }else{
        ans = max(ans, solve(price,idx+1,1,k,dp) - price[idx]) ;
        ans = max(ans,solve(price,idx+1, 0,k,dp));
    }
    return dp[idx][bought][k] = ans;
}
int maxProfit(vector<int>&price){
    //Write your code here..
    vector<vector<vector<int>>>dp(price.size(), vector<vector<int>>(2,vector<int>(2+1,-1)));
    return solve(price,0,0,0,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends