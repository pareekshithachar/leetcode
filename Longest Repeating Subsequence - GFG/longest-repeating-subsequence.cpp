//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(string &s, string &k, int i, int j,int dp[1001][1001]){
	        if(i >=s.size() || j>=k.size()) return 0;
	        
	        int ans = INT_MIN;
	        if(dp[i][j] != -1) return dp[i][j];
	        if(s[i] == s[j] && i!=j){
	            ans = 1 + solve(s,k,i+1,j+1,dp);
	            
	        }else{
	            ans = max(solve(s,k,i+1,j,dp), solve(s,k,i,j+1,dp));
	        }
	        return dp[i][j] = ans;
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		  //  vector<vector<int>>dp(str.size(), vector<int>(str.size(),-1));
		  int dp[1001][1001];
		  memset(dp,-1,1001*1001*sizeof (int));
		  
		    return solve(str,str,0,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends