class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
       
       
       vector<pair<int,int>>temp[n+1];
        for(auto x:rides)
            temp[x[1]].push_back({x[0],x[1]-x[0]+x[2]});
        
        vector<long long>dp(n+1);
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1];
            // for(auto x : temp[i]){
            //     dp[i] = max(dp[i], dp[x.first] + x.second);
            // }
            for(int j=0;j<temp[i].size();j++){
                dp[i] = max(dp[i],dp[temp[i][j].first] + temp[i][j].second);
            }
            
        }
        return dp[n];
    }
};