class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2){
        vector<long long>diff(100001);
        for(int i =0;i<nums1.size();i++){
            diff[abs(nums1[i] - nums2[i])]++;
        }
        int k = k1+k2;
        
        for(int i = 100000;i>=0;i--){
            if(diff[i] <=k){
                if(i<=1) return 0;
                diff[i-1]+=diff[i];
                k-=diff[i];
                diff[i]=0;
                
            }else{
                if(i==0) return 0;
                diff[i-1]+=k;
                diff[i]-=k;
                break;
            }
        }
        long long ans =0;
        for(int i=1;i<=100000;i++){
            ans+= diff[i]*i*i;
        }
        return ans;
    }
};