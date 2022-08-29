class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp = {{0,-1}};
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r = sum%k;
            if(mp.count(r)){
                if(i - mp[r] > 1) return true;
            }else{
                mp[r] =i;
            }
        }
        return false;
    }
};