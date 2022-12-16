//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>vis(v,0);
        vector<int>parent(v,-1);
        
        for(int i =0;i<v;i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    
                    for(auto x : adj[front]){
                        if(vis[x] && x != parent[front]){
                            return true;
                        }else if(!vis[x]){
                            vis[x] =1;
                            q.push(x);
                            parent[x] = front;
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