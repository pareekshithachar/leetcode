//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findparent(vector<int>&parent, int node){
        if(parent[node] == node) return node;
        
        return parent[node] = findparent(parent, parent[node]);
    }
    
    void unions(vector<int>&rank, vector<int>&parent, int a, int b){
        int para = findparent(parent,a);
        int parb = findparent(parent,b);
        if(para == parb) return;
        
        if(rank[para] < rank[parb]){
            parent[para] = parb;
        }
        if(rank[parb] < rank[para]){
            parent[parb] = para;
        }
        
        if(rank[para] == rank[parb]){
            parent[parb] = para;
            rank[para]++;
        }
        return ;
    }
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        if(edges.size() < n-1) return -1;
        vector<int>parent(n,-1);
        vector<int>rank(n,0);
        
        for(int i =0;i<n;i++) parent[i] = i;
        for(int i =0;i<edges.size();i++){
            int para = findparent(parent,edges[i][0]);
            int parb = findparent(parent, edges[i][1]);
            if(para != parb) unions(rank,parent,para,parb);
            
        }
        int count= 0;
        for(int i =0;i<n;i++) if(parent[i] == i) count++;
        return count-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends