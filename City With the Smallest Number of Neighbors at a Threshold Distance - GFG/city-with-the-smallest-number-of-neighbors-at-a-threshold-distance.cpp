//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& roads,
                 int thresh) {
                     
                     
                     
                     
                     unordered_map<int,list<pair<int,int>>>mp;
        
        for(int i =0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        
        vector<int>cities(n,INT_MAX);
        for(int i =0; i<n;i++){
            set<int>st;
            vector<int>dist(n,INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            pq.push({0,i});
            while(!pq.empty()){
                int node = pq.top().second;
                int cost = pq.top().first;
                pq.pop();
                st.insert(node);
                for(auto x : mp[node]){
                    int dest = x.first;
                    int w = x.second;
                    if(w + cost > thresh) continue;
                    if(dist[dest] > w + cost){
                        dist[dest] = w + cost;
                        pq.push({dist[dest],dest});
                        
                    }
                }
            }
            cities[i] = st.size();
        }
        
        int mini = *min_element(cities.begin(),cities.end());
        
        for(int i =n-1;i>=0;i--){
            if(cities[i] == mini) return i;
        }
        return -1;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends