class Solution {
public:
    vector<vector<int>>ans;
    void sub(vector<int>& nums, vector<int>&res, int i){
        // cerr<<i<<" ";
        if(i > nums.size() - 1 ){
            ans.push_back(res);
            return;
        } 
        
        sub(nums,res,i+1);
        res.push_back(nums[i]);
        sub(nums,res,i+1);
        res.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        sub(nums,res,0);
        return ans;
    }
};