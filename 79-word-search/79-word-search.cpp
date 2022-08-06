class Solution {
public:
    vector<vector<char>>visited;
    bool can=false;
    
    void dfs(int x, int i, int j,vector<vector<char>>& board,string word){
        if(visited[i][j]){
            return;
        }
        visited[i][j] = 1;
        
        if(word[x] != board[i][j]){
            visited[i][j] = 0;
            return;
        }
        
        if(x ==  word.size()-1){
            can = true;
            return;
        }
        if(i!=0 ) dfs(x+1,i-1,j,board,word);
        if(j!=0 ) dfs(x+1,i,j-1,board,word);
        if(j!=board[0].size()-1) dfs(x+1,i,j+1,board,word);
        if(i!=board.size()-1) dfs(x+1,i+1,j,board,word);
        visited[i][j] = 0;
        return;
            
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited.resize(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    dfs(0,i,j,board,word);
                }
            }
        }
        
        return can;
    }
};