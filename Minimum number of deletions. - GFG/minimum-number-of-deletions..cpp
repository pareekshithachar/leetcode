//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int solve(int idx1,int idx2, string &s1, string &s2,vector<vector<int>>&dp ){
        if(idx1 >= s1.size() || idx2 >=s2.size()) return 0;
        int ans =0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]){
            ans = 1 + solve(idx1+1, idx2+1,s1,s2,dp);
        }
        ans = max(ans,solve(idx1+1,idx2,s1,s2,dp));
        ans = max(ans,solve(idx1,idx2+1,s1,s2,dp));
        return dp[idx1][idx2] = ans;
    }

int minDeletions(string str, int n) { 
    //complete the function here 
    string s = str;
    reverse(s.begin(),s.end());
    vector<vector<int>>dp(str.size(),vector<int>(str.size(),-1));
    int check = solve(0,0,str,s,dp);

    return n-check;
} 