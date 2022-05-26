class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0;i< nums.size();i++){
            int low = i,  high = nums.size()-1;
            while(low<=high){
                int mid = low +(high-low)/2;
                if(nums[i] + nums[mid] == target  ){
                    if(mid != i) return {i+1,mid+1};
                    return {i+1,i+2};
                } 
                else if(nums[i] + nums[mid] < target) low = mid+1;
                else high = mid -1;
            }
        }
        return {};
    }
};