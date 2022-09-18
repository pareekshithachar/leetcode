class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1) return 0;
        int n= graph.size();
        long long finalState = (1<<n)-1;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,1<<i});
        }
        int shortestpath =0;
        vector<vector<int>>vis(n,vector<int>(finalState+1,0));
        
        while(!q.empty()){
            shortestpath++;
            int size = q.size();
            for(int i=0;i<size;i++){
                int front = q.front().first;
                int curstate= q.front().second;
                q.pop();
                
                for(auto x : graph[front]){
                    if(vis[x][curstate | (1<<x)] != 0){
                        continue;
                    }
                    if((curstate | (1<<x)) == finalState) return shortestpath;
                    vis[x][curstate | (1 << x) ] =1;
                    q.push({x,curstate | (1<<x)});
                }
                
            }
            
        }
        return -1;
    }
};