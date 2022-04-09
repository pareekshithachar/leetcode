class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            if(!q.empty() && q.front().second <= i-k) q.pop_front();
                while(!q.empty() && nums[i] > q.back().first){
                    q.pop_back();
                }
                q.push_back({nums[i],i});
                if(i<k-1) continue;
                ans.push_back(q.front().first);
            }
            return ans;

        }
    
};