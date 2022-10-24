//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // int solve(int idx, int d,int a[]){
    //     if(idx < 0){
    //         return 0;
    //     }
    //     int ans = 0;
    //     for(int j = idx -1 ;j>=0;j--){
    //         if(a[idx] - a[j] == d){
    //             ans = max(ans,1 + solve(j,d,a));
    //         }
    //     }
    //     return ans;
    // }
    int solve(int idx, int d, int a[]){
        int pre = a[idx];
        int ans = 0;
        for(int i = idx -1;i>=0;i--){
            if(pre - a[i] == d){
                ans++;
                pre = a[i];
            }
        }
        return ans;
    }
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2) return n;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                ans = max(ans, 2 + solve(i, A[j] - A[i], A));
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends