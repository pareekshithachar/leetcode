//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    vector<int>colour;
   
    // bool solve(bool graph[101][101], int m, int n, int node){
    //     if(st.size() == n) return true;
        
    //     for(int i = 0;i<n;i++){
    //         if(node == i || !graph[node][i]) continue;
    //         for(int col=0;col<m;col++){
    //             if(colour[i] != -1 && colour[i] == colour[node]) return false;

    //             colour[i] = col;
    //             st.insert(i);

    //             if(solve(graph,m,n,i)){
    //                 return true;
    //             }
    //             st.erase(i);
    //             colour[i] = -1;
    //         }
    //     }

    //     return false;
        
    // }
    bool issafe(bool graph[101][101],int n, int vertex,int col){
        for(int i =0;i<n;i++){
            if(graph[vertex][i] == 1 && col == colour[i] ) return false;
        }
        return true;
    }
    bool solve(bool graph[101][101], int m, int n, int vertex){
        if(vertex == n) return true;

        for(int col = 0;col<m;col++){

            if(issafe(graph,n,vertex,col)){
                colour[vertex] = col;
                if(solve(graph,m,n,vertex+1)){
                    return true;
                }
                colour[vertex] = -1;
            }

        }

        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        colour.resize(n,-1);
        return solve(graph,m,n,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends