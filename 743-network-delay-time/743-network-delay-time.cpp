class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k--;
        vector<int>visited(n,0);
        visited[k]=1;
        vector<int>cost(n,INT_MAX);
        cost[k] = 0;
        vector<vector<pair<int,int>>>g(n);
        
        for(auto x : times){
            
            x[0]--;
            x[1]--;
            g[x[0]].push_back({x[1],x[2]});

            
        }
        
        queue<int>q;

        q.push(k);
        
        while(!q.empty()){
            int front =q.front();
            q.pop();
            
            for(auto x : g[front]){
                
                if(x.second +  cost[front] < cost[x.first]){
                    cost[x.first] = x.second +  cost[front];
                    
                    q.push(x.first);
                    }
            }
        }
        int ans =0;
        for(auto x : cost){
            if(x == INT_MAX) return -1;
            cout<<x<<" ";
            ans = max(ans,x);
        }
        return ans;
    }
};