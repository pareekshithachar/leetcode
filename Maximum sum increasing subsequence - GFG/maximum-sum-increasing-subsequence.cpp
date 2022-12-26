//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
// 	int solve(int arr[], int n, int cur, int prev){
// 	    if(cur >= n) return 0;
	    
	    
// 	    int ans =0;
// 	    if(dp[cur][prev+1] != -1) return dp[cur][prev+1];
// 	    if(prev == -1 || arr[prev] < arr[cur]){
// 	        ans = arr[cur] + solve(arr,n,cur+1,cur);
// 	    }
// 	    ans = max(ans, solve(arr,n,cur+1,prev));
	    
// 	    return dp[cur][prev+1] = ans;
// 	}
	int maxSumIS(int a[], int n){  
	    // Your code goes here
	    
	    vector<int>dp(n,1);
        int ans=0;
       for(int i=0;i<n;i++){

            dp[i]=a[i];
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                   dp[i]=max(dp[j]+a[i],dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }

        return ans;
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends