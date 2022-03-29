class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%3 !=0) return false;
        
        int target = sum/3;
        int count=0;
        int currsum=0;
        for(int i =0;i<arr.size();i++){
            currsum+=arr[i];
            if(currsum == target){
                currsum =0;
                count++;
            }
            
            
            
        }
        return count >= 3;
    }
};