//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007
class Solution{
    public:
    vector<long long>dp;
    long long solve(int n, int k){
        if(n == 1) return k;
        if(n == 2){
            return k*k;
        }
        if(dp[n] != -1) return dp[n];
        
       return dp[n] = ((solve(n-1,k)%MOD + solve(n-2,k)%MOD)*(k-1)%MOD)%MOD;
        
    }
    long long countWays(int n, int k){
        // code here
        dp.resize(n+1,-1);
        return solve(n,k)%MOD;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends