//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here  
        set<char>st;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
        }
        int count =0;
        int ans = INT_MAX;
        unordered_map<char,int>mp;
        int i =0;
        for(int j =0; j<s.size();j++){
            mp[s[j]] ++;
            if(mp[s[j]] == 1){
                count++;
            }
            while(count == st.size()){
                ans = min(ans,j-i+1);
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    count--;
                }
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends