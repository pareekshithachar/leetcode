class Solution {
public:
    bool isSetBit(int pos, int x){
        return 1 & x>>pos;
    }
    vector<int> singleNumber(vector<int>& nums) {
       int ini =nums[0];
        for(int i=1;i<nums.size();i++){
            ini^=nums[i]; 
        }
        int pos =0,bitmask =1;
        while((ini & bitmask) == 0){
            bitmask = bitmask<<1;
            pos++;
        }
        int newxor = 0;
        for(int i=0;i<nums.size();i++){
            if(isSetBit(pos,nums[i])){
                newxor^=nums[i];
            }
        }
        return {newxor, newxor^ini};
        
    }
};
