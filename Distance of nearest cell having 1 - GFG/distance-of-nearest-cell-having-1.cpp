//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>>dist(m, vector<int>(n,-1));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i =0;i<m;i++){
	        for(int j =0;j<n;j++){
	            if(grid[i][j] == 1){
	                q.push({{i,j},0});
	                dist[i][j] =0;
 	            }
	        }
	    }
	    
	    vector<int>drows = {0,0,1,-1};
	    vector<int>dcols = {-1,1,0,0};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        
	        for(int i =0;i<4;i++){
	            int nrow = row + drows[i];
	            int ncol = col + dcols[i];
	            
	            if(nrow < m && nrow >=0 && ncol < n && ncol >=0 && dist[nrow][ncol] == -1){
	                dist[nrow][ncol] = steps+1;
	                q.push({{nrow,ncol},steps+1});
	            }
	        }
	        
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends