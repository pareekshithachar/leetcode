class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n =nums.size();
        vector<int> dp(nums.size(),0);
        dp[0]=0;
        dp[1]= nums[1];
        for(int i=2; i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        vector<int> dp1(nums.size(),0);
        dp1[n-1]=0;
        dp1[n-2]= nums[n-2];
        for(int i=n-3; i>=0;i--){
            dp1[i]=max(dp1[i+2]+nums[i], dp1[i+1]);
        }
        return max(dp[n-1],dp1[0]);
    }
};
