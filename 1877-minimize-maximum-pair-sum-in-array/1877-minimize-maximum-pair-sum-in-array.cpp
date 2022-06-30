class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=INT_MIN;
        for(int i=0;i<nums.size()/2;i++){
            temp = max(nums[i] + nums[nums.size()-1-i],temp);
        }
        return temp;
    }
};