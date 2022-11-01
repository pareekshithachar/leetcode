//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        string maxi = "";
        for(int i =0; i<s.size();i++){
            int l =i;
            int r =i;
            while(l>=0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            string temp = s.substr(l, r-l+1);
            if(temp.size() > maxi.size()) maxi = temp;
            l = i;
            r = i+1;
            while(l>=0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            temp = s.substr(l, r-l+1);
            if(temp.size() > maxi.size()) maxi = temp;
            
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends