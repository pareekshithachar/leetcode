//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void dfs(unordered_map<int,list<int>>&mp,unordered_map<int,int>&vis,vector<int>&temp, int node){
        if(vis[node]) return;
        vis[node]= 1;
        for(auto x : mp[node]){
            dfs(mp,vis,temp,x);
        }
        temp.insert(temp.begin(),node);
    }
    string findOrder(string dic[], int N, int K) {
        //code here
        unordered_map<int,int>vis;
        unordered_map<int,list<int>>mp;
        for(int i =0;i<N-1;i++){
            string s = dic[i];
            string k = dic[i+1];
            
            int x =0,y=0;
            while(x < s.size() && y<k.size()){
                if(s[x] != k[y]) break;
                x++;
                y++;
            }
            if(x < s.size() && y<k.size()){
                mp[s[x]-'a'].push_back(k[y]-'a');
            }
        }
        vector<int>temp;
        for(int i =0;i<K;i++){
            if(!vis[i]){
                dfs(mp,vis,temp,i);
            }
        }
        string ans ="";
        for(auto x : temp){
            ans+= x+'a';
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends