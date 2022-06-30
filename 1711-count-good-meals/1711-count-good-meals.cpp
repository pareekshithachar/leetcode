class Solution {
public:
    
    long long mod = 1e9 + 7;
    
    int countPairs(vector<int>& deliciousness) {
        
        int n = deliciousness.size();
        
        // store the power of 2's into power array
        
        vector<long long> power;
        
        for(int i = 0; i <= 21; i++)
        {
            power.push_back(pow(2, i));
        }
        
        unordered_map<int, int> mp;
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < power.size(); j++)
            {
                int need = power[j] - deliciousness[i];
                
                if(mp.count(need))
                {
                    count =  (count % mod + mp[need] % mod) % mod;
                }
            }
            
            mp[deliciousness[i]]++;
        }
        
        return count;
    }
};