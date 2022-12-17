//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int findparent(int node, vector<int>&parent){
        if(node == parent[node]) return node;
        return parent[node] = findparent(parent[node],parent);
    }
    
    void unions(vector<int>&rank, vector<int>&parent, int a, int b){
        int para = findparent(a,parent);
        int parb = findparent(b, parent);
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
    
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
        vector<int>parent(accounts.size());
        vector<int>rank(accounts.size(),0);
        for(int i =0;i<parent.size();i++) parent[i] = i;
        
        unordered_map<string,int>mp;
        for(int i =0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                
                if(mp.find(accounts[i][j]) != mp.end()){
                    
                    unions(rank,parent,mp[accounts[i][j]],i);
                }else{
                    mp[accounts[i][j]] = i;
                }
            }
        }
        
        
        
        vector<vector<string>>temp(n);
        
        for(auto x : mp){
            string mail = x.first;
            int idx = findparent(x.second,parent);
            
            temp[idx].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i =0;i<n;i++){
            if(temp[i].size()==0) continue;
            
            string x = accounts[i][0];
            
            sort(temp[i].begin(),temp[i].end());
            temp[i].insert(temp[i].begin(),x);
            ans.push_back(temp[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends