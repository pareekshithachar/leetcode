class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        k %= nums.size();
        int i=nums.size()-k;
        while(ans.size() != nums.size()){
            i %= nums.size();
            ans.push_back(nums[i]);
            i++;
        }
        nums = ans;
        
    }
};