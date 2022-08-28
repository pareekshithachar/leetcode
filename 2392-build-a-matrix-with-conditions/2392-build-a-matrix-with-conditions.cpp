class Solution {
public:
    vector<int> topo(vector<vector<int>>&g,int v){
        queue<int>q;
        vector<int>ans;
        vector<int>indeg(v+1,0);
        for(int i=1;i<=v;i++){
            for(auto x : g[i]){
                indeg[x]++;
            }
        }
        for(int i=1;i<=v;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            ans.push_back(top);
            q.pop();
            for(auto x : g[top]){
                if(--indeg[x] == 0){
                    q.push(x);
                }
            }
        }
        return ans;
        
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>>gr(k+1);
        vector<vector<int>>gc(k+1);
        for(int i=0;i<rowConditions.size();i++){
            gr[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for(int i=0;i<colConditions.size();i++){
            gc[colConditions[i][0]].push_back(colConditions[i][1]);
        }
        vector<int>cr = topo(gr,k);
        vector<int>cc = topo(gc,k);
        if(cr.size() != k || cc.size() != k) return {};
        vector<vector<int>>ans(k, vector<int>(k,0));
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++) {
            mp[cc[i]] = i;
        }
        
        for(int i = 0; i < k; i++) {
            ans[i][mp[cr[i]]] = cr[i];
        }
        return ans;
    }
};