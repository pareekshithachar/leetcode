class Solution {
public:


    void test(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&visited,int &ans){
        if((i>=grid.size() || i<0) || (j>=grid[0].size() || j<0)) return ;
        if(grid[i][j] != 1 || visited[i][j] == 1) return ;
        
        visited[i][j] = 1;
        ans++;
        test(grid,i-1,j,visited, ans);
        test(grid,i+1,j,visited, ans);
        test(grid,i,j-1,visited, ans);
        test(grid,i,j+1,visited, ans);
    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size()));
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int ans =0;
                test(grid,i,j,visited,ans);
                maxi = max(maxi,ans);

            }
           
        }
        return maxi;
    }
};