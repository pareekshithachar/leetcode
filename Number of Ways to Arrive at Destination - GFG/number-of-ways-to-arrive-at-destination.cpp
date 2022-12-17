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
        dist[0] = {0,0};
        unordered_map<int,list<pair<int,int>>>mp;
        
        for(int i =0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int front = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            for(auto x : mp[front]){
                int node = x.first;
                int cost = x.second;
                if(dist[node].first == cost + dis){
                    dist[node].second = (1%mod + dist[node].second%mod)%mod;
                     pq.push({node,dist[node].first});
                }
                
                if(dist[node].first > cost + dis){
                    dist[node].second = 1;
                    dist[node].first = cost + dis;
                    pq.push({node,dist[node].first});
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