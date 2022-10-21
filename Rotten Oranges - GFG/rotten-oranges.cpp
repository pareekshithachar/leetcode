//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        // Code here
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int time =0;
        while(!q.empty()){
            int size= q.size();
            bool flag= true;
            
            for(int a=0;a<size; a++){
                pair<int,int>temp = q.front();
                int i = temp.first;
                int j = temp.second;
                q.pop();
                if(i-1 >=0 && grid[i-1][j] == 1){
                    flag = false;
                    q.push({i-1,j});
                    grid[i-1][j] = 2;
                }
                if(i+1 < m && grid[i+1][j] == 1){
                    flag = false;
                    q.push({i+1,j});
                    grid[i+1][j] = 2;
                }
                if(j-1 >=0 && grid[i][j-1] == 1){
                    flag = false;
                    q.push({i,j-1});
                    grid[i][j-1] = 2;
                }
                if(j+1 < n && grid[i][j+1] == 1){
                    flag = false;
                    q.push({i,j+1});
                    grid[i][j+1] = 2;
                }
                
            }
            if(!flag){
                time++;
            }
            // time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends