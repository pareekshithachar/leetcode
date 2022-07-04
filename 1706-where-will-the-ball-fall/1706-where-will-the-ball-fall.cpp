class Solution {
public:
    int test(vector<vector<int>>& grid,int i,int j){
       int temp;
        if(grid[i][j] == 1){
            if(j == grid[i].size()-1 || grid[i][j+1] == -1) return -1;
            if(i ==  grid.size()-1 ) return j+1;
            return temp = test(grid, i+1,j+1);
        }else{
            if(j == 0 || grid[i][j-1] == 1) return -1;
            if(i ==  grid.size()-1 ) return j-1;
            return temp = test(grid, i+1,j-1);
        }
        return temp;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i=0;i<grid[0].size();i++){
            int x = test(grid,0,i);
            ans.push_back(x);
        }
        return ans;
    }
};