class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minprice = prices[0];
        for(int i = 0; i < prices.size(); i++){
            minprice = min(minprice, prices[i]);
            ans = max(ans, prices[i] - minprice);
        }
        return ans;
    }
};