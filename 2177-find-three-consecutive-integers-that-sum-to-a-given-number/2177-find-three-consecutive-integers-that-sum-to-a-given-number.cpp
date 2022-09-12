class Solution {
public:
    int ispos(long long mid, long long num){
        long long x = 3*mid + 3;
        if( x == num){
            return 0;
        }
        if( x > num){
            return 1;
        }
        return -1;
        
    }
    vector<long long> sumOfThree(long long num) {
        long long low =0, high = num/3;
        if(num == 0){
            return {{-1,0,1}};
        }
        while(low<high){
            long long mid = low + (high-low)/2;
            int check = ispos(mid,num);
            if(!check){
                return {{mid,mid+1,mid+2}};
            }
            if(check == -1){
                low = mid +1;
            }else{
                high = mid-1;
            }
        }
       return {}; 
    }
};