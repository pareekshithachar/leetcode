//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isvalid ( int i , int j, vector<vector<int>>&dist){
        int m =dist.size();
        int n = dist[0].size();
        if(i <0 || i>=m || j< 0 || j >= n) return false;
        
        return true;
    }
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int m =heights.size();
        int n = heights[0].size();
        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
        cost[0][0] = 0;
        
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});
        int ans = INT_MAX;
        vector<int>nrow = {0,0,1,-1};
        vector<int>ncol = {1,-1,0,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int pathcost = q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int newr = row + nrow[i];
                int newc = col + ncol[i];
                
                if(isvalid(newr,newc,cost)){
                    int curdiff = abs(heights[newr][newc] - heights[row][col]);
                    int check = max(curdiff,pathcost);
                    if(cost[newr][newc] > check){
                        cost[newr][newc] = check;
                        q.push({{newr,newc},check});
                    }
                }
            }
            
        }
        return cost[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends