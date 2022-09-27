class Solution {
public:
    int countPrimes(int n) {
        vector<bool>primes(n+1,true);
        int count =0;
        primes[0] = primes[1] = false;
        for(int i=2;i<n;i++){
            if(primes[i]) count++;
            for(int j= 2*i;j<n;j=j+i){
                primes[j] = false;
            }
        }
        return count;
    }
};