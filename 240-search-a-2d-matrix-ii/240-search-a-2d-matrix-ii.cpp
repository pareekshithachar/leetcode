class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowidx = 0;
        int colidx = col-1;
        while(rowidx < row && colidx >=0){
            int element = matrix[rowidx][colidx];
            if(element == target){
                return true;
            }
            if(element < target){
                rowidx++;
            }else{
                colidx--;
            }
        }
        return false;
    }
};