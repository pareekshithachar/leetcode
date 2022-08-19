class Solution {
public:
    int solve(vector<int>& cost,int index,vector<int>&dp){
        if(index  >= cost.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int o1 = cost[index] + solve(cost,index+1,dp);
        int o2= cost[index] + solve(cost,index + 2,dp );
        return dp[index] = min(o1,o2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};