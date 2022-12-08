//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    
    int count1 =0,count2 = 0;
    for(int i =0;i<s.length();i++){
        if((i%2 == 1  && s[i] == '0') || (i%2 == 0 && s[i] == '1')){
            count1++;
        }
        if((i%2 == 1  && s[i] == '1') || (i%2 == 0 && s[i] == '0')){
            count2++;
        }
    }

    return min(count1,count2);
}