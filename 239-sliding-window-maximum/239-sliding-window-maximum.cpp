class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        
        int i=0;
       for(;i<k;i++){
           q.push({nums[i],i});
           
       }
        ans.push_back(q.top().first);
        
        for(;i<nums.size();i++ ){
            q.push({nums[i],i});
            while(q.top().second<= i - k){
                q.pop();
            }
             
            ans.push_back(q.top().first);
            
        }
        return ans;
    }
};