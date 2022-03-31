class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0,sum=0;
        unordered_map<int,int>res;
        res[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(res.find(sum-k)!=res.end()){
                count+=res[sum-k];
            }
            res[sum]++;
        }
        return count;
    }
};