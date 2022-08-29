class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>rem;
        rem[0] = 1;
        int count =0;
        int sum =0;
        for(auto x : nums){
            sum+=x;
            int remainder = sum%k;
            if(remainder < 0) remainder+=k;
            count += rem[remainder];
            rem[remainder]++;
        }
        return count;
    }
};