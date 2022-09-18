class Solution {
public:
    vector<vector<int>>visited;
    int m,n;
    vector<pair<int,int>>b1,b2;
    bool isBoundary( vector<vector<int>> &grid,int i, int j){
    if(i>0 and grid[i-1][j]==0)
      return true;
    if(j>0 and grid[i][j-1]==0)
      return true;
    if(i<n-1 and grid[i+1][j]==0)
      return true;
    if(j<m-1 and grid[i][j+1]==0)
      return true;
    return false;
  }
    
    void dfs(vector<vector<int>>& grid, int i, int j,vector<pair<int,int>>&b){
        
        if( i<0 || i> m-1 || j <0 || j>n-1 || grid[i][j] == 0 || visited[i][j] == 1){
            return;
        }
        visited[i][j]=1;
        if(isBoundary(grid,i,j)){
            b.push_back({i,j});
        }
        dfs(grid,i+1,j,b);
        dfs(grid,i,j+1,b);
        dfs(grid,i-1,j,b);
        dfs(grid,i,j-1,b);
         
    }  
    int shortestBridge(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        visited.resize(m,vector<int>(n,0));
        for(int i =0;i<m;i++){
            bool check=false;
            for(int j=0; j<n;j++){
                
                if(grid[i][j] == 1){
                    check=true;                    
                    dfs(grid,i,j,b1);
                    break;
                }
            }
            if(check) break;
        }
        
        for(int i =0;i<m;i++){
            bool check = false;
            for(int j=0; j<n;j++){
                
                if(!visited[i][j] && grid[i][j] == 1){
                    
                    check=true; 
                    dfs(grid,i,j,b2);
                    break;
                }
            }
            if(check) break;
        }
        // cout<<b1.size()<< " "<<b2.size()<<endl;
        int ans = INT_MAX;
        for(int i=0;i<b1.size();i++){
            for(int j=0;j<b2.size();j++){
                
                ans = min(ans, abs(b1[i].first-b2[j].first)+abs(b1[i].second- b2[j].second));
            }
        }
        
        return ans-1;
    }
};