//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    #define mod 1000000007
    long long int countBT(int h) { 
        long long int  height[h+1];
        height[0] = 1;
        height[1] = 1;
        for(int  i = 2; i <= h;i++)
            height[i] = (height[i-1] * (2*height[i-2]%mod+height[i-1]%mod))%mod;
        return height[h];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends