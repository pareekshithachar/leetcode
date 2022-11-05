//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,int>parent;
        unordered_map<int,bool>vis;
        for(int i =0 ;i< V;i++){
            if(!vis[i] ){
                queue<int>q;
                q.push(i);
                vis[i] = true;
                parent[i] = -1;
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    for(auto nbr : adj[front]){
                        if(vis[nbr] && nbr != parent[front]){
                            return true;
                        }else if(!vis[nbr]){
                            vis[nbr] = true;
                            parent[nbr] = front;
                            q.push(nbr);
                        }
                    }
                }
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