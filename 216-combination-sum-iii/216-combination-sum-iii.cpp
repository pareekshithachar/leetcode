class Solution {
public:
    vector<vector<int>>res;
 
    void solve(int k, int tempk,int n, set<int> s, int sum,vector<int>ans, int x){
        if(tempk == k) {
            if(sum == n){
                res.push_back(ans);
                  
            }
            return;
        }
        for(int i=x+1;i<=9;i++){
            
            if(tempk != k){
                
                ans.push_back(i);
                solve(k,tempk+1,n,s,sum + i,ans, i);
                ans.pop_back();
                
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45 || (n==45 && k<9)){
            return {};
        }
        if(n==45 && k == 9){
            return {{1,2,3,4,5,6,7,8,9}};
        }
        set<int>s;
        vector<int>ans;
         solve(k,0,n,s,0,ans,0);
        return res;
    }
};