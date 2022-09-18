class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        auto x=min_element(nums.begin(), nums.end())-nums.begin();
        cout<<x<<" ";
        int a=-1, ans=x+1;
        for(int i=0;i<x;i++){
            a=max(a, nums[i]);
        }
        cout<<a;
        int b=a;
        for(int i=x+1;i<nums.size();i++){
            if(nums[i]<a){
                ans=i+1;
                a=b;
            }
            b=max(a, nums[i]);
        }
        return ans;
    }
};