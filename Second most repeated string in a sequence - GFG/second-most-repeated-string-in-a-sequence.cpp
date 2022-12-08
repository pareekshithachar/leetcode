//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        sort(arr, arr + n );
        priority_queue<pair<int, string>>pq;
        for(int i =0;i<n;i++){
            int a = upper_bound(arr, arr + n, arr[i]) - arr;
            
            pq.push({a-i,arr[i]});
            if(i == n) break;
            i = a-1;
            
        }
        pq.pop();
        if(pq.empty()) return "";
        return pq.top().second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends