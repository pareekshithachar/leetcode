//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(string &s, vector<string>&ans, string k, int idx){
	        if(idx >= s.size()){
	            if(k!= "") ans.push_back(k);
	            return ;
	        }
	        
	        solve(s,ans,k,idx+1);
	        solve(s,ans,k+s[idx],idx+1);
	        
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    solve(s,ans,"",0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends