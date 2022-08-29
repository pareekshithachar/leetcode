class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        int c = n%14 == 0 ? 14 : n%14;
        
        vector<int>temp = cells;
        
            cells[0] =0;
            cells[7] =0;
        
        
        while(c--){
            for(int i =1;i<7;i++){
                if(temp[i-1] == temp[i+1]){
                    cells[i] = 1;
                    
                }else{
                     cells[i] = 0;
                }
            }
            temp = cells;
            
        }
        return cells;
    }
};