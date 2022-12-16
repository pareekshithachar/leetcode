//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycle(int node,vector<bool>&vis,int parent,vector<int> adj[],vector<bool>&dfsvis){
        vis[node]=true;
        dfsvis[node] = true;
        for(auto x : adj[node]){
            if(x == parent) continue;
            if(vis[x] && dfsvis[x]){
                return true;
            }else if(!vis[x]){
                bool check = iscycle(x,vis,node,adj,dfsvis);
                if(check) return true;
            }
            
        }
        dfsvis[node] = false;
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>vis(v,0);
        vector<bool>dfsvis(v,0);
        
        for(int i =0;i<v;i++){
            if(!vis[i] && iscycle(i,vis,i,adj,dfsvis)){
                return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends