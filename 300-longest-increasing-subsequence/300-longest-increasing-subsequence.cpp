class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1,1);
        int global =1;
        dp[0] = 1;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    
                    dp[i] = max(dp[j]+1,dp[i]);
                    
                }
                global = max(global, dp[i]);
            }
        }
        return global;
    }
};