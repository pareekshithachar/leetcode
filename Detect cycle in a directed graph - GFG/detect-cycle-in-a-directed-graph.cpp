//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    unordered_map<int,bool>vis;
    unordered_map<int,bool>dfsvis;
    
    bool dfs(vector<int> adj[], int node){
        
        vis[node] = true;
        dfsvis[node] = true;
        for(auto x : adj[node]){
            if(vis[x] && dfsvis[x]) return true;
            if(!vis[x] && dfs(adj, x)){
                return true;
            }
        }
        dfsvis[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        for(int i=0;i<V;i++){
            // vis.clear();
            // dfsvis.clear();
            if(dfs(adj,i)){
                return true;
            }
        }
        // if(dfs(adj,0));
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends