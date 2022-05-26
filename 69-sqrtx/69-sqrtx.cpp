class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x,ans =0;
        int mid = low + (high-low)/2;
        while(low<=high){
            mid = low+ (high-low)/2;
            if(mid<(x/mid)){
                low = mid+1;
                ans = mid;
            }else if(mid==(x/mid)){
                return mid;
            }else{
                high = mid-1;
            }
        }
        return high;
    }
};
