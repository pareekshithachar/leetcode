//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>parent(n+1,-1);
        unordered_map<int,list<pair<int,int>>>mp;
        for(int i =0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        pq.push({1,0});
        vector<int>dist(n+1,INT_MAX);
        dist[1] = 0;
        while(!pq.empty()){
            auto front =  pq.top();
            int node = front.first;
            int dis = front.second;
            pq.pop();
            for(auto x : mp[node]){
                
                if(dist[x.first] > dis + x.second){
                    dist[x.first] = dis + x.second;
                    parent[x.first] = node;
                    pq.push({x.first,dist[x.first]});
                }
            }
        }
        vector<int>ans;
        if(dist[n] == INT_MAX){
            return {-1};
        }
        while(n != -1){
            ans.push_back(n);
            n = parent[n];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends