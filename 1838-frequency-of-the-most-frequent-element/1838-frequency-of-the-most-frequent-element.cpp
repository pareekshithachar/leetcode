class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); 
        
        int m=0,l=nums.size()-1,r=nums.size()-1,sum=0;

        while(r>=0 and l>=0){
            if(sum+(nums[r]-nums[l])<=k){
                sum+=nums[r]-nums[l];
            }
            else{
                m=max(m,r-l);
                int diff=nums[r]-nums[r-1];
                l++;
                sum-=diff*(r-l);
                r--;
            }
           l--; 
        }
        m=max(m,r-l);
        return m;
        }
};