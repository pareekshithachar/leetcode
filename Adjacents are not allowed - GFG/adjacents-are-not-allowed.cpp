//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int> > &nums, int row, int col,vector<vector<int>>&dp ){
        if(col < 0 ){
            return 0;
        }
        //choose 
        int choose = 0;
        int dontchose = 0;
        if(dp[row][col] != -1) return dp[row][col];
        if(row == 0){
            choose = nums[row][col] +  max(solve(nums,row,col-2,dp),solve(nums,row+1,col-2,dp));
            dontchose = max({solve(nums,row,col-1,dp),solve(nums,row+1,col-1,dp)});
        }
        if(row == 1){
            choose = nums[row][col] + max(solve(nums,row,col-2,dp),solve(nums,row-1,col-2,dp));
            dontchose = max({solve(nums,row,col-1,dp),solve(nums,row-1,col-1,dp)});
        }
        
        return dp[row][col] = max(choose,dontchose);
    
    }
    int maxSum(int N, vector<vector<int>> A)
    {
        // code here
        vector<vector<int>>dp(2,vector<int>(N,-1));
        int opt1 = solve(A,0,N-1,dp);
        int opt2 = solve(A,1,N-1,dp);
        return max(opt1,opt2);

        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }
        
        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends