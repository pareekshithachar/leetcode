class Solution {
public:
    int dfs(int src,int total,vector<vector<int>>&edge,vector<int>&vis,vector<bool>&hasApple){
        
        vis[src]=true;
        int children=0;
        
        for(auto ele:edge[src]){
            if(!vis[ele])
                children+=dfs(ele,2,edge,vis,hasApple);
        }
        
        if(!children && !hasApple[src])return 0;
        return children+total;
    }
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>>edge(n);
        
        for(int i=0;i<edges.size();i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>vis(n);
        
        return dfs(0,0,edge,vis,hasApple);
    }
};