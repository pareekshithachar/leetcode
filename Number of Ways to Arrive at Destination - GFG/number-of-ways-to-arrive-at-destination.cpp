//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int mod = 1e9+7;
        vector<pair<int,int>>dist(n,{INT_MAX,0});
        //value,count
        dist[0] = {0,1};
        unordered_map<int,list<pair<int,int>>>mp;
        
        for(int i =0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0}); // dist,node
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto x : mp[node]){
                int destination = x.first;
                int cost = x.second;
                
                if(cost + dis == dist[destination].first){
                    dist[destination].second = (dist[destination].second%mod + dist[node].second%mod)%mod;
                }
                
                if(cost + dis < dist[destination].first){
                    dist[destination].second = dist[node].second;
                    dist[destination].first = cost + dis;
                    pq.push({dist[destination].first,destination});
                }
            }
        }
        return dist[n-1].second;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends