class Solution {
public:
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>> res;
        unordered_map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        for(auto y : mp){
            res.push({y.second,y.first});
            }
        vector<int>ans;
        while(k--){
            ans.push_back(res.top().second);
            res.pop();
        }
        return ans;
    }
        
};