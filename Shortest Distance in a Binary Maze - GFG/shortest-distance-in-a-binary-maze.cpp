//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isvalid ( int i , int j, vector<vector<int>>&dist){
        int m =dist.size();
        int n = dist[0].size();
        if(i <0 || i>=m || j< 0 || j >= n || dist[i][j] != 0) return false;
        
        return true;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> d) {
        // code here
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>>q;
        
        q.push({source,0});
        vector<int>nrow = {0,0,1,-1};
        vector<int>ncol = {1,-1,0,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            if(row == d.first && col == d.second ) return dis;
            for(int i =0;i<4;i++){
                int newr = row + nrow[i];
                int newc = col + ncol[i];
                
                if(isvalid(newr,newc,dist) && grid[newr][newc] == 1){
                    q.push({{newr,newc},dis+1});
                    dist[newr][newc] = dis+1;
                } 
            }
            
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends