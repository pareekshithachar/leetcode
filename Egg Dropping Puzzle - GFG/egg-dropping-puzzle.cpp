//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i = 1;i <= n;i++){
            for(int j = 1; j<= k;j++){
                if(i == 1){
                    dp[i][j] = j;
                }else if(j == 1){
                    dp[i][j] = 1;
                }else{
                    int ans = INT_MAX;
                    for(int egs = j-1, egb = 0; egs>=0;egs--,egb++){
                        int v1 = dp[i][egs];
                        int v2 = dp[i-1][egb];
                        int val = max(v1,v2);
                        ans = min(ans,val);
                    }
                    dp[i][j] = ans + 1;
                    
                    
                }
            }
        }
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends