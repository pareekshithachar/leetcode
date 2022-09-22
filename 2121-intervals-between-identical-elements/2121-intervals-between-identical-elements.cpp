class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        int n=arr.size() ;
        unordered_map<int , vector<long long>> mp ;
        
        for(int i=0 ; i<n ; i++)  mp[arr[i]].push_back(i) ;
        
        vector<long long> ans(arr.size()) ;
        
        for(auto it : mp)
        {
            vector<long long> v = it.second ;
            int sz = v.size() ;
            vector<long long> presum(sz,v[0]) ;
            for(int i=1 ; i<sz ; i++)   presum[i] = presum[i-1] + v[i] ;
            
            for(int i=0 ; i<sz ; i++)    
            {
                long long left = 0 ;
                if(i-1 >= 0)  left = i*v[i] - presum[i-1] ;
                long long right = presum[sz-1] - presum[i] - (sz-i-1)*v[i] ;
                
                ans[v[i]] = left+right ;
            }
            
        }
        
        return ans ;
    }
};