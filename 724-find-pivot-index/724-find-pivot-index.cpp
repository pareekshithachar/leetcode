class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>sum(nums.size(), nums[0]);
        for(int i=1;i<nums.size();i++){
            sum[i] = sum[i-1]+ nums[i];
        }
        for(int i=0;i<nums.size();i++){
            int left, right;
            if( i ==0){
                left = 0;
            }else{
                 left = sum[i-1];
            }
            if(i == nums.size()-1){
                right = 0;
            }else{
                right = sum[n-1]-sum[i];
            }
            if(right == left) return i;
        }
        return -1;
    }
};