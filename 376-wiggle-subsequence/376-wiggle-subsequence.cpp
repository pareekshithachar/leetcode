class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2));
        
        dp[0][0]=dp[0][1]=1;
        if(nums.size()<=1) return 1;
        int n = nums.size();
        int res = 1;
        for(int i=1;i<nums.size();i++){
            int cur = nums[i];
            for(int j=0;j<i;j++){
                if(cur>nums[j]) dp[i][0] = max(dp[i][0],dp[j][1]+1);
                if(cur<nums[j])dp[i][1] = max(dp[i][1],dp[j][0]+1);
            }
            res = max({res,dp[i][0],dp[i][1]});
        }
        return res;
    }
};