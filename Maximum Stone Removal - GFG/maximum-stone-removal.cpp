//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class dsu{
    public:
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
    int count =0;
    dsu(int n){
        parent.resize(n);
        for(int i =0;i<n;i++){
            parent[i] =i;
            
        }
        size.resize(n,1);
        rank.resize(n,0);
    }
    int findparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    }
    
    void unionsbyrank(int a, int b){
        int para = findparent(a);
        int parb = findparent(b);
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
    void unionsbysize(int a, int b){
        int para = findparent(a);
        int parb = findparent(b);
        if(para == parb) return;
        
        if(size[para] >= size[parb]){
            parent[parb] = para;
            size[para]+= size[parb];
        }else{
            parent[para] = parb;
            size[parb]+= size[para];
        }
        return ;
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        int maxrow=0,maxcol =0;
        for(auto x : stones){
            maxrow = max(maxrow,x[0]);
            maxcol = max(maxcol,x[1]);
        }

        dsu ds(maxrow + maxcol +2);
        unordered_map<int,int>mp;
        for(auto x : stones){
            int c1= x[0];
            int c2 = x[1] + maxrow + 1;
            ds.unionsbyrank(c1,c2);
            mp[c1]=1;
            mp[c2]=1;
        }
        int count =0;
        for(auto x : mp){
            if(ds.findparent(x.first) == x.first)count++;
        }
        return n-count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends