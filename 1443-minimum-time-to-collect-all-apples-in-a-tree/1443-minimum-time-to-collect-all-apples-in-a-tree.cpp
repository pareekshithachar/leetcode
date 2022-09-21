class Solution {
public:
    vector<vector<int>>adj;
    int ans=0;
    int dfs(int node,int parent,vector<bool>&apple){
        int c=0;
        for(int child:adj[node]){
            if(child==parent){
                continue;
            }
            c+=max((int)apple[child],dfs(child,node,apple));
        }
        ans+=c*2;
        if(c>0){
            return 1;
        }
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,hasApple);
        return ans;
    }
};