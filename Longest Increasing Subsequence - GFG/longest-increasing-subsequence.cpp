//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:

    //Function to find length of longest increasing subsequence.
    int solve(int n, int a[], int cur, int prev,vector<vector<int>>&dp){
        
        if(cur>=n){
            return 0;
        }
        if(dp[cur][prev+1] != -1) return dp[cur][prev+1];
        int include = 0;
        if(prev  == -1 || a[prev]<a[cur]){
            include = 1 + solve(n,a,cur+1,cur,dp);
        }
        int exclude = solve(n,a,cur+1,prev,dp);
        
        return dp[cur][prev+1]=max(exclude,include);
    }
    //5 7 8 4
    int findidx(int a[], vector<int>&path, int i){
        int low = 0, high = path.size()-1;
        int ans = 0;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(path[mid] > a[i]){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        return ans;
    }
    int solveop(int n, int a[], vector<int>&path){
        
        for(int i=0;i<n;i++){
            if(i == 0 || path[path.size() - 1] < a[i]){
                path.push_back(a[i]);
            }else{
                int x = findidx(a,path,i);
                path[x] = a[i];
            }
        }
        return path.size();
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
    //   vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<int>path;
       return solveop(n,a,path);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends