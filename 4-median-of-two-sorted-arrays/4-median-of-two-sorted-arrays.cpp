class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]>=nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
            }
        }
        for(;i<nums1.size();i++){
            ans.push_back(nums1[i]);
        }
        for(;j<nums2.size();j++){
            ans.push_back(nums2[j]);
        }
        int x=ans.size();
        if(x%2 ==0) return (ans[x/2]+ans[(x/2)-1])/2.0;
        
        return ans[x/2];
        
        
    }
};



// 1,2,3,4,5,6,7  =7
// 1,1,1,1,3,4,5,9,10,11,12 =11
    
// 1,1,1,1,1,2,3,3,4,4,5,5,6,7,9,10,11,12