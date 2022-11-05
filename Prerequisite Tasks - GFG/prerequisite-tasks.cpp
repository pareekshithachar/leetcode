//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>indegree(V);
	    unordered_map<int,list<int>>g;
	    for(int i =0;i<pre.size();i++){
	        indegree[pre[i].second]++;
	        g[pre[i].first].push_back(pre[i].second);
	    }
	    int count =0;
	    queue<int>q;

	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	            count++;   
	        } 
	    }
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        for(auto x : g[front]){
	            indegree[x]--;
	            if(indegree[x] == 0){
	                count++;
	                q.push(x);
	            }
	        }
	    }
	    return (count == V);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends