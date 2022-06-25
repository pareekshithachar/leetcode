class Solution {
public:
    void sortColors(vector<int>& nums) {
       
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                swap(nums[i],nums[0]);
            }
        }
        int cur = 0;
        if(nums[0] == 0){
            cur=1;
        }
        
        
        for(int i =1;i<nums.size();i++){
            if(nums[i] == 0){
                swap(nums[i],nums[cur]);
                cur++;
            }
        }
        for(int i =cur;i<nums.size();i++){
            if(nums[i] == 1){
                swap(nums[i],nums[cur]);
                cur++;
            }
        }
    }
};