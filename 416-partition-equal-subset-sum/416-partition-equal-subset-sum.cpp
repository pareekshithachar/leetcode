class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int target=0;
        int n= nums.size();
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        
        if(target%2 == 1) return false;
        target = target/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
        for(int i=0;i<=nums.size();i++){
                for(int j=0;j<=target;j++){
                    if(i==0) dp[i][j]=false;
                    else if(j==0) dp[i][j]=true;
                }
            }
        for(int i =1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
        
    }
};
