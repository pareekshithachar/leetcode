//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool solve(int i, int j, string &w, string &p,vector<vector<int>>&dp){
        if(i < 0 && j <0 ) return true;
        if(i <0 &&  j>=0 ) return false;
        
        if(j<0 && i>=0){
            for(int x = 0;x <=i;x++){
                if(w[x] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = true;
        
        if(w[i] == p[j] || w[i] == '?'){
            ans = solve(i-1,j-1,w,p,dp);
        }
        else if(w[i] == '*'){
            bool include = solve(i,j-1,w,p,dp);
            bool exclude = solve(i-1,j,w,p,dp);
            ans = exclude || include;
            
        }else{
            ans =false;
        }
        return dp[i][j] = ans;
        
    }
    bool match(string w, string p)
    {
        // code here
        vector<vector<int>>dp(w.size(),vector<int>(p.size(),-1));
        return solve(w.size()-1, p.size()-1,w,p,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends