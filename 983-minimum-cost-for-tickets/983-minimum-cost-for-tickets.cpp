class Solution {
public:
    
    int solve(vector<int>& days, vector<int>& costs, int index,vector<int>&dp){
        if(index >=days.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int option1  = costs[0] + solve(days,costs,index + 1,dp);
        int i;
        for(i = index; i< days.size() && days[i] < days[index] + 7;i++);
        int option2 = costs[1] + solve(days,costs,i,dp);
        
        for(i = index; i< days.size() && days[i] < days[index] + 30;i++);
        int option3 = costs[2] + solve(days,costs,i,dp);
        
        return dp[index] = min({option1,option2,option3});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
       return solve(days,costs,0,dp);
    }
};