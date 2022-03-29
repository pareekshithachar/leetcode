class Solution {
public:
    int helper(vector<int>& arr, int target,int value){
        int sum =0;
        for(auto x : arr){
            
            if(x<=value){
                sum+= x;
                
            }else{
                sum+=value;
            }
        }
        return abs(sum-target);
    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int mx = INT_MIN;
        for(int i=0;i<arr.size();i++){
            mx=max(mx,arr[i]);
        }
        int l=0, r=mx;
        while(l<=r){
            int mid = l + (r-l)/2;
            int x = helper(arr,target,mid);
            int y = helper(arr,target,mid+1);
            if(x <= y){
                r = mid-1;
            }else{
                l=mid+1;
            }
            
        }
        return l;
        
    }
};