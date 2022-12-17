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
    bool isvalid(int r, int c, int m, int n,vector<vector<int>>&grid){
        if(r < 0 || r >= n || c<0 || c>=m || grid[r][c] == 0){
            return false;
        }
        return true;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        dsu ds(m*n);
        vector<int>dr = {-1,0,1,0};
        vector<int>dc = {0,-1,0,1};
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int x = 0;x<2;x++){
                        int newr = i + dr[x];
                        int newc = j + dc[x];
                        int curval = i*n+j;
                        int newval = newr*n + newc;
                        if(isvalid(newr,newc,n,m,grid)){
                            ds.unionsbysize(newval,curval);
                        }
                    }
                }
            }
        }
        int ans = 1;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    int temp =1;
                    set<int>st;
                    for(int x = 0;x<4;x++){
                        int newr = i + dr[x];
                        int newc = j + dc[x];
                        int curval = i*n+j;
                        int newval = newr*n + newc;
                        
                        if(isvalid(newr,newc,n,m,grid)){
                            int parent = ds.findparent(newval);
                            if(st.count(parent) == 1 ){
                                
                                continue;
                            } 
                            st.insert(parent);
                            
                            temp+= ds.size[parent];
                        }
                    }
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends