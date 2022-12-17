//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class dsu{
    public:
    vector<int>parent;
    vector<int>rank;
    dsu(int n){
        parent.resize(n);
        for(int i =0;i<n;i++){
            parent[i] =i;
            
        }
        rank.resize(n,0);
    }
    int findparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    }
    
    void unions(int a, int b){
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
};
class Solution {
  public:
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        unordered_map<int,int>mp;
        dsu ds(n*m);
        vector<int>ans;
        for(int i =0;i<operators.size();i++){
            int row = operators[i][0];
            int col = operators[i][1];
            int cur = row*m + col;
            mp[cur] = cur;
            if(row != 0){
                if(mp.find(cur-m) != mp.end()){
                    ds.unions(cur, cur-m);
                }
            }
            if(row != n-1){
                if(mp.find(cur+m) != mp.end()){
                    ds.unions(cur, cur+m);
                }
            }
            if(col!=0){
                if(mp.find(cur-1) != mp.end()){
                    ds.unions(cur, cur-1);
                }
            }
            if(col!=m-1){
                if(mp.find(cur+1) != mp.end()){
                    ds.unions(cur, cur+1);
                }
            }
            int count=0;
            for(int i =0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(ds.parent[i*m+j] == i*m+j && mp.find(i*m+j) != mp.end()) count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends