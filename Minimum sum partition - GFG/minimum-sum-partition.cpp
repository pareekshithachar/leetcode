//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    vector<vector<int>>dp;
    int solve(int arr [],int n, int idx, int sum, int total){
        if(idx >= n){


            return abs(total - 2*sum);
        }
        if(dp[sum][idx]!= -1) return dp[sum][idx];
        int include = solve(arr, n, idx+1, sum + arr[idx],total);
        int exclude  =solve(arr,n,idx+1,sum,total);
        return dp[sum][idx] = min(include,exclude);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum =0;
	    int total =0;
	    
	    for(int i =0;i<n;i++){
	        total+= arr[i];
	    }
	    
	    dp.resize(total+1,vector<int>(n+1,-1));
	    return solve(arr,n,0,sum,total);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends