class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int l =0, h = row*col -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            int element = matrix[mid/col][mid%col];
            if(element == target){
                return true;
            }
            if(element < target){
                l = mid+1;
                
            }else{
                h = mid -1;
            }
            
        }
        return false;
    }
};