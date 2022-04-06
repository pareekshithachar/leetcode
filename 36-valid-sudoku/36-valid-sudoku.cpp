class Solution {
public:
    bool checkx(vector<vector<char>>& board,int j){
        unordered_map<char,int> mp;
        for(int i = 0; i<board[0].size();i++){
            if(board[i][j] == '.') continue;
            if(mp.count(board[i][j])) return false;
            mp[board[i][j]] ++;
            
        }
        return true;
    }
    bool checky(vector<vector<char>>& board,int i){
        unordered_map<char,int> mp;
        for(int j = 0; j<board[0].size();j++){
            if(board[i][j] == '.') continue;
            if(mp.count(board[i][j])) return false;
            mp[board[i][j]] ++;
            
        }
        return true;
    }
    bool check3x3(vector<vector<char>>& board,int i, int j){
        unordered_map<char,int> mp;
        int tempi = i;
        int tempj =j;
        for(i; i<tempi+3;i++){

            for(j=tempj;j<tempj+3;j++){
                cout<<i<<j<<" ";
                if(board[i][j] == '.') continue;
                if(mp.count(board[i][j])) return false;
                
                mp[board[i][j]] ++;
            }
        }
        return true;
    }
        
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i< board[0].size();i++){
            if(!checky(board,i)) return false;
            
        }
        for(int i = 0; i< board[0].size();i++){
            if(!checkx(board,i)) return false;
            
        }
        for(int i =0; i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                if(!check3x3(board,i,j)) return false;
            }
        }
       
        
        return true;
    }
};