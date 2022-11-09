//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool ispos(string k){
        string a = k;
        reverse(a.begin(),a.end());
        return a == k;
    }
    void solve(int idx,string s,vector<string>&temp, vector<vector<string>>&ans){
        if(idx >= s.size()){
            for(int i = 0;i<temp.size();i++ ){
                if(!ispos(temp[i])){
                    return;
                }
            }
            ans.push_back(temp);
            return;
        }
        
        
        temp.push_back("");
        temp.back()+=s[idx];
        solve(idx+1, s, temp,ans);
        temp.pop_back();
        
        temp.back() += s[idx];
        solve(idx+1, s, temp,ans);
        string k = temp.back();
        k.pop_back();
        temp.back() = k;
        
        
        return ;
        
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string>temp;
        vector<vector<string>>ans;
        temp.push_back("");
        temp[0]+=S[0];
        
        
        solve(1,S,temp,ans);

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends