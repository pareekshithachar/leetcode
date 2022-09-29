class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,int i){
        if(i>=nums.size()){
            ans.push_back(nums);
        }
        
        for(int j = i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums,ans,i+1);
            swap(nums[i],nums[j]);
        }
        return;
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        
        solve(nums,ans,0);
        return ans;
    }
};