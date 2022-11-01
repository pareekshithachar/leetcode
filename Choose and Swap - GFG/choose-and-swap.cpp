//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        set<char>st;
        for(auto x: a){
            st.insert(x);
        }
        for(int i =0;i<a.size();i++){
            st.erase(a[i]);
            if(st.empty()) break;
            char ch = *st.begin();
            char cur = a[i];
            if(ch < cur){
                for(int i=0;i<a.size();i++){
                    if(a[i] == cur) a[i] = ch;
                    else if(a[i] == ch) a[i]= cur;
                }
                break;
            }
        }
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends