class Solution {
public:
    
    unordered_map<double,double> mp;
    double power(double x, long long n){
        if(n == 1) return x;
        if(mp.count(n)) return mp[n];
        if(n%2 ==1) {
            
            mp[(n-1)/2] = power(x, (n-1)/2);
            return x*power(x, (n-1)/2)*power(x, (n-1)/2);
        }   
        else{
            
            mp[n/2] =power(x, n/2);
            return power(x, n/2)*power(x, n/2);
        } 
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n>0){
           return power(x,n); 
        }else{
            return 1/power(x,abs(n));
        }
        
        
    }
};