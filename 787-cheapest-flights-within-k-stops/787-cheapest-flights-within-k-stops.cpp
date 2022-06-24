class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(1001);
        for(auto x : flights){
            graph[x[0]].push_back({x[1], x[2]});
        }
        
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>>pq;
        
        pq.push({0,src,0});
        int ans = INT_MAX;
        vector<int>stops(1001, INT_MAX);
        
        while(!pq.empty()){
            auto [dist, node, stop] = pq.top();
            pq.pop();
            cout<<node<<" "<<stop<<" "<<dist<<"\n";
            if(node == dst) return dist;
            if(stop > k) continue;

            if(stops[node]!= INT_MAX and stops[node] < stop) continue;
            stops[node] = stop;
            for(auto [nextNode, weight] : graph[node]){
                pq.push({dist + weight, nextNode, stop + 1});
            }
        }
        
        return -1;
        
        
        
    }
};