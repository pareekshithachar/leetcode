//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string>ans;
	    void solve(string &s, int idx){
	        if(idx >= s.size()){
	            ans.insert(s);
	        }
	        for(int i =idx;i<s.size();i++){
	            swap(s[i],s[idx]);
	            solve(s,idx+1);
	            swap(s[i],s[idx]);
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    ans.clear();
		    solve(S,0);
		    vector<string>res;
		    
		    for (auto itr = ans.begin();
              itr != ans.end(); itr++)
            {
                res.push_back(*itr);
            }
		    sort(res.begin(),res.end());
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends