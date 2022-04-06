class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxcount=0;
        int count = 1;
        if(n ==  0) return 0;
        auto x = unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),x));
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]+ 1 == nums[i+1]){
                count ++;
            }else{
                maxcount = max(maxcount,count);
                count = 1;
            }
        }
        maxcount = max(count,maxcount);
        return maxcount;
    }
};
//0,0,1,2,3,4,5,6,7,8