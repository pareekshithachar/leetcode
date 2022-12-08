//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int m,n;
    int solve(vector<vector<char>> &mat,int i, int j, string &target, int idx){

        if(i >= m || i<0 || j>=n || j<0 || mat[i][j] == '.' || mat[i][j] != target[idx]){
            return 0;
        }
        if(idx == target.size()-1) {

            return 1;
        }
        
        int ans =0;
        char temp = mat[i][j];
        mat[i][j] = '.';
        ans+=solve(mat,i+1,j,target,idx+1);
        ans+=solve(mat,i-1,j,target,idx+1);
        ans+=solve(mat,i,j+1,target,idx+1);
        ans+=solve(mat,i,j-1,target,idx+1);
        mat[i][j] = temp;
        return ans;
        
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int a =0;
        m= mat.size();
        n=mat[0].size();
        for(int i =0;i<mat.size();i++){
            for(int j =0;j<mat[0].size();j++){
                a += solve(mat, i,j, target,0);
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends