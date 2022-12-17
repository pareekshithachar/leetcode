//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int>ans;
    set<int>st;
    void dfs(vector<int>adj[], int node, int parent, int timer, vector<int>&low, vector<int>&disc,
    vector<int>&vis){
        disc[node] = low[node] = timer;
        timer++;
        vis[node] = 1;
        int child =0;
        for(auto x : adj[node]){
            if(x == parent) continue;
            if(!vis[x]){
                child++;
                dfs(adj,x,node,timer,low,disc,vis);
                low[node] = min(low[node], low[x]);
                
                if(low[x] >= disc[node] && parent != -1){
                    st.insert(node);
                }
            }else{
                low[node] = min(low[node], disc[x]);
            }
        }
        if(child > 1 && parent == -1){
            st.insert(0);
        }
        
        
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        
        int timer =0;
        int parent =-1;
        ans.clear();
        unordered_map<int,list<int>>mp;

        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<int>vis(n,0);
        
        dfs(adj,0,-1,timer,low,disc,vis);
        
        for(auto x : st){
            ans.push_back(x);
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends