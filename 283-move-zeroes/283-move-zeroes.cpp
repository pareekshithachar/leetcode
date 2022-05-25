class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i] == 0){
                int j=i;
                while(nums[j+1] == 0){
                    j++;
                    if(j == nums.size() - 1) return;

                }
                
                
                swap(nums[i],nums[j+1]);
            }
        }
    }
};
//0,1,0,3,12
//1,0,0,3,12
//1,3,0,0,12
//1,3,12,0,0
//0,0