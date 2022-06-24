class Solution {
public:
    bool isPos(vector<vector<char>>& board,int i,int j, char num){
        for(int x = 0;x<9;x++){
            if(board[x][j] == num) return false;
            if(board[i][x] == num) return false;
        }
        cout<<i<<" "<<j<<" ";
        i = 3 *(i/3);
        j = 3 *(j/3);
        cout<<i<<" "<<j<<endl;
        int tempi=i;
        int tempj=j;
        for(i;i<tempi+3;i++){
            for(j;j<tempj+3;j++){
                if(board[i][j] ==  num)return false;
            }
            j=tempj;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] =='.'){
                    for(char val = '1'; val<='9'; val++){
                        if(isPos(board,i,j,val)){
                            board[i][j] = val;
                            bool future = solve(board);
                                if(future) return true;
                                else{
                                    board[i][j]='.';
                                }   
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};