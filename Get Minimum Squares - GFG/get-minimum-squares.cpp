//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	vector<int>dp;
	int solve(int n){
	    if(n == 0){
	        return 0;
	    }
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int mini = n;
	    for(int i =1;i<=sqrt(n);i++ ){
	        if(i*i <= n){
	            int ans = 1 + solve(n - i*i);
	            mini = min(ans,mini);
	        }
	    }
	    return dp[n]=mini;
	}
	int MinSquares(int n)
	{
	    // Code here
	   // int root = sqrt(n);
	   dp.clear();
	   dp.resize(n+1,-1);
	    int ans = solve(n);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends