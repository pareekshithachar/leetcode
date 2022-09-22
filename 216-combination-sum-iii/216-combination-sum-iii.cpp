class Solution {
public:
    vector<vector<int>>res;
 
    void solve(int k, int tempk,int n, int sum,vector<int>ans, int x){
        if(tempk == k) {
            if(sum == n){
                res.push_back(ans);
                  
            }
            return;
        }
        for(int i=x+1;i<=9;i++){
            
            if(tempk != k){
                
                ans.push_back(i);
                solve(k,tempk+1,n,sum + i,ans, i);
                ans.pop_back();
                
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45){
            return {};
        }
        
        vector<int>ans;
         solve(k,0,n,0,ans,0);
        return res;
    }
};