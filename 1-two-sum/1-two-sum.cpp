class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num;
        for(int i=0; i<nums.size(); i++){
            num[nums[i]] =i;
        }
        for(int i=0; i<nums.size(); i++){
            if(num.find(target- nums[i])!=num.end()){
                
               if(i!=num[target- nums[i]]) return{i,num[target- nums[i]]};
            }
        }
        return {};
    }
};