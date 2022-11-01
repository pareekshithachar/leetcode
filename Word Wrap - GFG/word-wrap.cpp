//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int solve(vector<int>&nums, int k, int idx, int len,vector<vector<int>>&dp){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx][len+1] != -1) return dp[idx][len+1];
        int sameline = INT_MAX;
        if(len == -1 || k - len - 1 - nums[idx] >=0 ) sameline = solve(nums,k,idx+1, len+1+nums[idx],dp);
        int newline = INT_MAX;
        if(len != -1){
           newline = (k-len)*(k-len) + solve(nums,k,idx,-1,dp); 
        } 
        
        return dp[idx][len+1] = min(sameline,newline);
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        vector<vector<int>>dp(nums.size()+1,vector<int>(k+2,-1));
        return solve(nums,k,0,-1,dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends