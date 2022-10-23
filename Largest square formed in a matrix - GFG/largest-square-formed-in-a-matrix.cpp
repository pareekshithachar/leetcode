//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int i, int j, vector<vector<int>>&mat,int &maxi,vector<vector<int>>&dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
            
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int right = solve(i,j+1,mat,maxi,dp);
        int diag = solve(i+1,j+1,mat,maxi,dp);
        int down = solve(i+1,j,mat,maxi,dp);
        int ans;
        if(mat[i][j] == 1){
            ans = min({right,down,diag})+1;
            maxi = max(ans,maxi);
            return dp[i][j] = ans;
        }
        
        return dp[i][j] = 0;
    }
    int solvetab(int n, int m, vector<vector<int>>&mat,int &maxi){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
       
        for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>= 0;j--){
                if(mat[i][j] == 1){
                    int opt1 = 0;
                    
                    opt1 = dp[i][j+1];
                    
                    int opt2 = 0;
                    
                    opt2 = dp[i+1][j];
                    
                    int opt3 = 0;
                    
                    opt3 = dp[i+1][j+1];
                    
                    dp[i][j] = min({opt1,opt2,opt3}) +1;
                    maxi= max(dp[i][j] ,maxi);
                }
            }
        }
        
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi =0;
        solvetab(n,m,mat,maxi);
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends